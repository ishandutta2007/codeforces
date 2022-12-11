#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 10;
int n, m;
bool dom[N][N];
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
int t[N][N];
int dp[N][(1 << 10)];
bool used[N][(1 << 10)];

bool checkCoord(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n && y < m);
}

bool check(int mask)
{
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) == 0)
		{
			if (i == n - 1 || (mask & (1 << (i + 1))) != 0)
				return false;
			i++;
		}
	}	
	return true;
}

void relax(int a, int b, int ind)
{                                    
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if ((a & (1 << i)) != 0 && ((b & (1 << i)) != 0))
			return;
		if ((a & (1 << i)) == 0)
		{
			if ((b & (1 << i)) == 0)
			{                
				if (i == n - 1 || (b & (1 << (i + 1))) != 0)
					return;                                
				if ((a & (1 << (i + 1))) != 0)		
					return;

				if (dom[i][ind])
				{
					if (t[i][ind] == t[i][ind + 1])
						cnt += 2;
				}
				if (dom[i + 1][ind])
				{
					if (t[i + 1][ind] == t[i + 2][ind] || t[i + 1][ind] == t[i + 1][ind + 1])
						cnt += 2;
				}
				i++;
			}
			else
			{
				if (ind == m - 1)
					return;
				if (dom[i][ind])
				{
					if (t[i][ind] == t[i + 1][ind])
						cnt += 2;
				}
			}
		}
		else
		{
			if (dom[i][ind])
			{
				if (t[i][ind] == t[i][ind + 1] || t[i][ind] == t[i + 1][ind])
					cnt += 2;
			}
		}
	}
	cnt += (ind == 0 ? 0 : dp[ind][a]);              
//	cout << a << ":" << b << "  " << ind << " = " << cnt << endl;
	used[ind + 1][b] = 1;
	dp[ind + 1][b] = min(dp[ind + 1][b], cnt);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
                           
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int s = 0; s < m; s++)
			scanf("%d", &t[i][s]);
	}

	for (int i = 0; i < N; i++)
		for (int s = 0; s < (1 << 10); s++)
			dp[i][s] = (int)1e9;

	int allCnt = 0;
	for (int i = 0; i < n; i++)
		for (int s = 0; s < m; s++)
		{
			for (int d = 0; d < 4; d++)
			{
				int x = i + DX[d];
				int y = s + DY[d];
				if (checkCoord(x, y) && t[i][s] == t[x][y])
				{
					dom[i][s] = 1;                 
					allCnt++;
				}
			}
		}


	for (int mask = 0; mask < (1 << n); mask++)
	{	
		if (!check(mask))
			continue;

		relax(0, mask, 0);
	}

	for (int i = 1; i < m; i++)
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			if (!used[i][mask])
				continue;
			for (int nMask = 0; nMask < (1 << n); nMask++)
				relax(mask, nMask, i);
		}
	}                         
                           
    allCnt /= 2;  
    int ans = dp[m][0];  
//    cout << ans;

    ans /= 2;
    allCnt -= ans;
    ans = n * m / 2 - allCnt;
    cout << ans;


	return 0;
}