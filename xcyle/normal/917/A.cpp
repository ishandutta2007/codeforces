#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 5005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int ok[2][maxn][maxn], sum[maxn], cnt[maxn];
vector<int> t;
char s[maxn];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	t.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		 sum[i] = sum[i - 1] + (s[i] == '?' ? 1 : 0);
		 cnt[i] = cnt[i - 1];
		 if(s[i] == '(') cnt[i]++;
		 else if(s[i] == ')') cnt[i]--;//(s[i] == ')' ? -1 : 1);
		 if(s[i] == '?') t.push_back(i);
	}
	t.push_back(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		ok[0][i][i - 1] = 1;
		for (int j = i; j <= n; j++)
		{
			if(s[j] == ')') sum--;
			else sum++;
			ok[0][i][j] = ok[0][i][j - 1];
			if(sum < 0) ok[0][i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		ok[1][i + 1][i] = 1;
		for (int j = i; j >= 1; j--)
		{
			if(s[j] == '(') sum--;
			else sum++;
			ok[1][j][i] = ok[1][j + 1][i];
			if(sum < 0) ok[1][j][i] = 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int x = sum[j] - sum[i - 1];
			int det = cnt[j] - cnt[i - 1];
			if((det - x) % 2 != 0 || !ok[0][i][j] || !ok[1][i][j]) continue;
			int c = (x - det) / 2;
			if(c < 0 || c > x) continue;
//			printf("%d %d %d %d %d %d\n", i, j, x, det, c, t[sum[i - 1] + c]);
			int pos1 = t[sum[i - 1] + c + 1] - 1, pos2 = t[sum[i - 1] + c] + 1;
//			printf("%d %d %d %d %d %d %d\n", i, j, x, det, c, pos1, pos2);
			pos1 = max(pos1, i - 1);
			pos1 = min(pos1, j);
			pos2 = max(pos2, i);
			pos2 = min(pos2, j + 1);
			if(c && !ok[0][i][pos1]) continue;
            if(c != x && !ok[1][pos2][j]) continue;
//			printf("%d %d %d %d %d %d %d\n", i, j, x, det, c, pos1, pos2);
            ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}