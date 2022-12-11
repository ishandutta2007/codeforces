#include <iostream>
#include <cstdio>
using namespace std;
           	
typedef long long ll;

int num[10];
int indNum = 0;

int gAns = 0;

const int mod = (int)1e9 + 7;

int add(int a, int b)
{
	return (a + b >= mod ? a + b - mod : a + b);
}

int mult(int a, int b)
{           
	ll c = (ll)a * (ll)b;
	return (int)(c % (ll)mod);
}

int dp[11][10][3];//POS, CNT1, CNT2

int binPow(int a, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return mult(binPow(a, k - 1), a);
	else
	{
		int t = binPow(a, k / 2);
		return mult(t, t);
	}
}

int calcC(int n, int m)
{
	if (m > n)
		return 0;
	int res = 1;
	for (int i = n; i > n - m; i--)
		res = mult(res, i);             
	return res;
}

int allCnt[10];

void solve(int c1, int m)
{
	for (int i = 0; i < 11; i++)
		for (int s = 0; s < 10; s++)
			for (int j = 0; j < 3; j++)
				dp[i][s][j] = 0;    
	dp[0][0][1] = 1;
	for (int i = 0; i < indNum; i++)
	{
		for (int a = 0; a <= c1; a++)     
		{
			int t = num[i];
			for (int cN = 0; cN < 10; cN++)	
			{
				int d = (cN == 4 || cN == 7);
				for (int eq = 0; eq < 3; eq++)
				{
					if (eq == 0)
					{
						if (cN <= t)
							dp[i + 1][a + d][0] = add(dp[i + 1][a + d][0], dp[i][a][eq]);
						else
							dp[i + 1][a + d][2] = add(dp[i + 1][a + d][2], dp[i][a][eq]);
					}
					else if (eq == 1)
					{
						if (cN == t)
							dp[i + 1][a + d][1] = add(dp[i + 1][a + d][1], dp[i][a][eq]);
						else if (cN < t)
							dp[i + 1][a + d][0] = add(dp[i + 1][a + d][0], dp[i][a][eq]);
						else
							dp[i + 1][a + d][2] = add(dp[i + 1][a + d][2], dp[i][a][eq]);
					}
					else
					{
						if (cN < t)
							dp[i + 1][a + d][0] = add(dp[i + 1][a + d][0], dp[i][a][eq]);
						else
							dp[i + 1][a + d][2] = add(dp[i + 1][a + d][2], dp[i][a][eq]);						
					}
				}
			}
		}
	}
	allCnt[c1] = add(dp[indNum][c1][0], dp[indNum][c1][1]);  
}

int cntFromC[10];

void fun(int k, int pos, int curCnt = 0)
{
	if (curCnt >= k)
		return;
	if (pos == 6)
	{
		int locAns = 1;
		for (int i = 0; i < 10; i++)
			locAns = mult(locAns, calcC(allCnt[i], cntFromC[i]));
		locAns = mult(locAns, allCnt[k]);
		gAns = add(gAns, locAns);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		cntFromC[i]++;
		fun(k, pos + 1, curCnt + i);
		cntFromC[i]--;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int m;
	scanf("%d", &m);

	int z = m;
	while (z)
	{
		num[indNum++] = z % 10;
		z /= 10;
	}

	for (int cnt1 = 1; cnt1 < 10; cnt1++)          
			solve(cnt1, m);
        
    int q = m;
    for (int i = 9; i >= 1; i--)
    	q -= allCnt[i];

    allCnt[0] = q;

    for (int i = 1; i < 10; i++)
    {
    	fun(i, 0);
    }

    cout << gAns << endl;

	return 0;
}