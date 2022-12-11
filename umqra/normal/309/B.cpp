#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int N = (int)1e6 + 10;
const int LOG = 22;

string str[N];
int len[N];
int sumPref[N];
int dp[N][LOG];

int getCntSumbol(int a, int b)
{
	if (b == a)
		return len[a];
	return (b - a + sumPref[b] - (a == 0 ? 0 : sumPref[a - 1]));
}

int getDp(int val, int t)
{
	if (val == -1)
		return val;
	return dp[val][t];
}

void printAns(int v, int r, int c, int n)
{
	int curC = c;
	bool wasEnd = true;
	while (r > 0 && v < n)
	{
		if (curC >= len[v] && wasEnd)
		{
			wasEnd = false;
			cout << str[v];
			if (curC != len[v])
				cout << ' ';
			curC -= len[v];
			v++;
		}
		else if (curC >= len[v] + 1 && !wasEnd)
		{
			wasEnd = false;
			cout << str[v];
			if (curC != len[v] + 1)
				cout << ' ';
			curC -= len[v] + 1;
			v++;
		}
		else
		{
			if (!wasEnd)
				cout << endl;
			wasEnd = true;
			r--;
			curC = c;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);
	
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		len[i] = str[i].length();
	}
	
	sumPref[0] = len[0];
	for (int i = 1; i < n; i++)
		sumPref[i] = sumPref[i - 1] + len[i];
	
	for (int i = 0; i < n; i++)
	{
		int l = -1, r = i + 1;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (getCntSumbol(m, i) <= c)
				r = m;
			else
				l = m;
		}
		dp[i][0] = r - 1;
		for (int s = 1; s < LOG; s++)
			dp[i][s] = getDp(dp[i][s - 1], s - 1);

	}
	
	int stV = -1;
	int bestR = -1;
	
	for (int i = 0; i < n; i++)
	{
		int curR = r;
		int curV = i;
		for (int s = LOG - 1; s >= 0; s--)
		{
			if ((1 << s) <= curR)
			{
				curV = getDp(curV, s);
				curR -= (1 << s);
			}
		}
		if (i - curV > bestR)
		{
			bestR = i - curV;
			stV = curV;
		}
	}
	
	printAns(stV + 1, r, c, n);
	
	return 0;
}