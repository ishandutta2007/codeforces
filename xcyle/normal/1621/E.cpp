/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define db double
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
const ll INF = 1e11;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, m;
db a[maxn];
inline int cmp(db x, db y)
{
	return x > y;
}
vector<pair<double, int> > stu[maxn], tmp[maxn];
int id[maxn];
inline int cmp2(int x, int y)
{
	pair<double, int> X = stu[x].back(), Y = stu[y].back();
	return X.first > Y.first;
}
int pre[maxn][3], suf[maxn][3];
int ans[maxn];
int work(int A, int B)
{
	if(pre[min(A, B) - 1][0] != 0) return 0;
	if(suf[max(A, B) + 1][0] != n + 1) return 0;
	if(A < B)
	{
		return pre[B - 1][1] < A;
	}
	else return pre[A - 1][2] < B;
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	n = m;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		stu[i].clear();
		int x = read();
		while(x--) stu[i].push_back(make_pair((db)read(), ++tot));
		db sum = 0;
		for (auto x: stu[i]) sum += x.first;
		stu[i].push_back(make_pair(sum / stu[i].size(), 0));
		id[i] = i;
//		printf("%.3f\n", sum);
	}
	sort(id + 1, id + n + 1, cmp2);
	for (int i = 1; i <= n; i++) tmp[i] = stu[i];
	for (int i = 1; i <= n; i++) stu[i] = tmp[id[i]];
	for (int i = 1; i <= n; i++)
	{
//		for (auto x: stu[i]) printf("%.3f %d\n", x.first, x.second);
//		printf("\n");
	}
//	printf("!");
	pre[0][0] = pre[0][1] = pre[0][2] = 0;
	for (int i = 1; i < n; i++)
	{
		pre[i][0] = (stu[i].back()).first <= a[i] ? pre[i - 1][0] : i;
		pre[i][1] = (stu[i].back()).first <= a[i + 1] ? pre[i - 1][1] : i;
		pre[i][2] = (stu[i + 1].back()).first <= a[i] ? pre[i - 1][2] : i;
	}
	suf[n + 1][0] = suf[n + 1][1] = suf[n + 1][2] = n + 1;
	for (int i = n; i > 1; i--)
	{
		suf[i][0] = (stu[i].back()).first <= a[i] ? suf[i + 1][0] : i;
		suf[i][1] = (stu[i].back()).first <= a[i - 1] ? suf[i + 1][1] : i;
		suf[i][2] = (stu[i - 1].back()).first <= a[i] ? suf[i + 1][2] : i;
	}
	for (int i = 1; i <= n; i++)
	{
		db sum = 0;
		for (int j = 0; j + 1 < stu[i].size(); j++) sum += stu[i][j].first;
		for (int j = 0; j + 1 < stu[i].size(); j++)
		{
			db t = 0;
			if(stu[i].size() > 2) t = (sum - stu[i][j].first) / (stu[i].size() - 2);
			if(a[1] < t)
			{
			ans[stu[i][j].second] = 0;
			continue;
			 } 
			int l = 1, r = n, mid;
			while(l < r)
			{
				mid = (l + r + 1) >> 1;
				if(a[mid] >= t) l = mid;
				else r = mid - 1;
			}
//			printf("%.3f %d\n", t, l);
			ans[stu[i][j].second] = work(l, i);
		}
	}
	for (int i = 1; i <= tot; i++) printf("%d", ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		solve();
	 } 
	return 0;
}