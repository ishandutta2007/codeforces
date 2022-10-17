#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 300005
using namespace std;
const long long INF = 1e9 + 1;
int t, len[4];
struct node
{
	long long d;
	int type;
}p[maxn];
inline int cmp(node x, node y)
{
	return x.d < y.d;
}
int cnt = 0;
int pre[maxn][4], suf[maxn][4];
inline long long calc(long long a, long long b, long long c)
{
	return (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c);
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		cnt = 0;
		scanf("%d%d%d", &len[1], &len[2], &len[3]);
		for (int i = 1; i <= len[1]; i++) scanf("%lld", &p[++cnt].d);
		for (int i = 1; i <= len[2]; i++) scanf("%lld", &p[++cnt].d);
		for (int i = 1; i <= len[3]; i++) scanf("%lld", &p[++cnt].d);
		for (int i = 1; i <= len[1]; i++) p[i].type = 1;
		for (int i = len[1] + 1; i <= len[1] + len[2]; i++) p[i].type = 2;
		for (int i = len[1] + len[2] + 1; i <= len[1] + len[2] + len[3]; i++) p[i].type = 3;
		sort(p + 1, p + cnt + 1, cmp);
		for (int i = 1; i <= cnt; i++)
		{
			for (int j = 1; j <= 3; j++) pre[i][j] = pre[i - 1][j];
			pre[i][p[i].type] = i;
		}
		suf[cnt + 1][1] = suf[cnt + 1][2] = suf[cnt + 1][3] = 0;
		for (int i = cnt; i >= 1; i--)
		{
			for (int j = 1; j <= 3; j++) suf[i][j] = suf[i + 1][j];
			suf[i][p[i].type] = i;
		}
		long long ans = INF * INF * 3;
		for (int i = 1; i <= cnt; i++)
		{
			if(p[i].type == 1)
			{
				if(pre[i][2] && suf[i][3]) ans = min(ans, calc(p[i].d, p[pre[i][2]].d, p[suf[i][3]].d));
				if(pre[i][3] && suf[i][2]) ans = min(ans, calc(p[i].d, p[pre[i][3]].d, p[suf[i][2]].d));
			}
			if(p[i].type == 2)
			{
				if(pre[i][1] && suf[i][3]) ans = min(ans, calc(p[i].d, p[pre[i][1]].d, p[suf[i][3]].d));
				if(pre[i][3] && suf[i][1]) ans = min(ans, calc(p[i].d, p[pre[i][3]].d, p[suf[i][1]].d));
			}
			if(p[i].type == 3)
			{
				if(pre[i][2] && suf[i][1]) ans = min(ans, calc(p[i].d, p[pre[i][2]].d, p[suf[i][1]].d));
				if(pre[i][1] && suf[i][2]) ans = min(ans, calc(p[i].d, p[pre[i][1]].d, p[suf[i][2]].d));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}