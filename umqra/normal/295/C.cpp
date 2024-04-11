#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int N = 51;
const int mod = (int)1e9 + 7;

int dp[4 * N][N][N];
bool used[4 * N][N][N];
int x[N];
int c[N][N];

int mult(int a, int b)
{
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

int mult(int a, int b, int c)
{
	return mult(a, mult(b, c));
}

int add(int a, int b)
{
	int c = (a + b);
	return (c >= mod ? c - mod : c);
}

void calcC()
{
	for (int i = 0; i < N; i++)
	{
		for (int s = 0; s <= i; s++)
		{
			if (s == 0)
				c[i][s] = 1;
			else
			{
				if (i != 0)
					c[i][s] = add(c[i - 1][s], c[i - 1][s - 1]);
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	calcC();
	int n, k;
	scanf("%d%d", &n, &k);
	k /= 50;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		x[i] /= 50;
		(x[i] == 1 ? cnt1++ : cnt2++);
	}
	used[0][cnt1][cnt2] = 1;
	dp[0][cnt1][cnt2] = 1;
	int minD = (int)1e9;
	for (int i = 0; i < 4 * n; i++)
	{
		for (int c1 = 0; c1 <= cnt1; c1++)
			for (int c2 = 0; c2 <= cnt2; c2++)
			{                      
				if (used[i][c1][c2])
				{                                                  
					if (c1 == 0 && c2 == 0)
						minD = min(minD, i);	               
					if (i & 1)
					{
						int t1 = cnt1 - c1;
						int t2 = cnt2 - c2;
						for (int a = 0; a <= t1; a++)
							for (int b = 0; b <= t2; b++)
							{
								if (a + b > 0 && a + 2 * b <= k)
								{
									used[i + 1][c1 + a][c2 + b] = 1;
									dp[i + 1][c1 + a][c2 + b] = add(dp[i + 1][c1 + a][c2 + b], mult(dp[i][c1][c2], 
																c[t1][a], c[t2][b]));
								}
							}
					}
					else
					{
						for (int a = 0; a <= c1; a++)
							for (int b = 0; b <= c2; b++)
							{
								if (a + b > 0 && a + 2 * b <= k)
								{
									used[i + 1][c1 - a][c2 - b] = 1;
									dp[i + 1][c1 - a][c2 - b] = add(dp[i + 1][c1 - a][c2 - b], mult(dp[i][c1][c2], 
																c[c1][a], c[c2][b]));       
								}
							}
					}
				}
			}
	}

	if (minD == (int)1e9)
		puts("-1\n0");
	else	
	{
		printf("%d\n%d", minD, dp[minD][0][0]);

	}

	return 0;
}