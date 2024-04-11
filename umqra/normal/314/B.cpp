#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 200;

string a, c;
int go[N][N];
bool used[N][N];

int b;

int calcLen(int x, int y, int st, int en, bool &flag)
{                                                                                  
	int d = (go[x][y] <= x ? 1 : 0);          
	int nY = (y == (int)c.length() - 1 ? 0 : y + 1);
	if (go[x][y] == st && nY == en)                 
	{
		if (go[x][y] > x)
			flag = 1;
		else
			flag = 0;
		return !flag;
	}
	return calcLen(go[x][y], nY, st, en, flag) + d;
}

int calcWord(int x, int y, int st, int en, bool flag = true)
{
	if (x == st && y == en && flag)
		return 0;       
	int d = (y == (int)c.length() - 1 ? 1 : 0);          
	int nY = (y == (int)c.length() - 1 ? 0 : y + 1);
	return calcWord(go[x][y], nY, st, en) + d;
}

ll solve(int fPos, int sPos, int cntBlock = 0, int cntWord = 0)
{                              
    if (cntBlock >= b)
    	return (ll)cntWord;    
	
	if (go[fPos][sPos] == -1)
		return (ll)cntWord;

	int nS = (sPos == (int)c.length() - 1 ? 0 : sPos + 1);
	int d = (sPos == (int)c.length() - 1 ? 1 : 0);             
	if (sPos == 0 && used[fPos][sPos] == 1)
	{                       
		bool f;
		int len = calcLen(fPos, sPos, fPos, sPos, f);
		int t = calcWord(fPos, sPos, fPos, sPos, false);                           
		ll ans = (ll)cntWord + (ll)((b - cntBlock - f) / len) * (ll)t;
		int locCntB = ((b - cntBlock - f) / len) * len;          
		if (fPos < go[fPos][sPos])
			return ans + solve(go[fPos][sPos], nS, cntBlock + locCntB, 0);     
		else
			return ans + solve(go[fPos][sPos], nS, cntBlock + locCntB + 1, 0);
	}   
	used[fPos][sPos] = 1;
	if (fPos < go[fPos][sPos])
		return solve(go[fPos][sPos], nS, cntBlock, cntWord + d);     
	else
		return solve(go[fPos][sPos], nS, cntBlock + 1, cntWord + d);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

    int d;               
	scanf("%d%d", &b, &d);     
	cin >> a >> c;


	for (int i = 0; i < N; i++)
		for (int s = 0; s < N; s++)
			go[i][s] = -1;

	for (int i = 0; i < (int)a.length(); i++)
		for (int s = 0; s < (int)c.length(); s++)
		{
			if (a[i] != c[s])
				continue;
			int sNext = (s == (int)c.length() - 1 ? 0 : s + 1);
			int q = (i == (int)a.length() - 1 ? 0 : i + 1);
			int cntQ = 0;
			while (cntQ != (int)a.length())
			{
				if (a[q] == c[sNext])
				{
					go[i][s] = q;
					break;
				}
				cntQ++;
				q++;
				if (q == (int)a.length())
					q = 0;
			}                                                
		}
                              
	for (int i = 0; i < (int)a.length(); i++)
	{
		if (go[i][0] != -1)
		{
			ll partAns = solve(i, 0);
			printf("%I64d", partAns / (ll)d);
			return 0;
		}
	}

	puts("0");

	return 0;
}