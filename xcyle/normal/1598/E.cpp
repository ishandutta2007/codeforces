#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
#define ll long long
#define maxn 2005
using namespace std;
int n, m, q, num[maxn], cnt, x, y;
vector<int> rk[maxn][maxn];
set<int> a[maxn];
ll ans = 0;
void dfs(int x, int y, int tp, int col)
{
	if(x < 1 || x > n || y < 1 || y > m) return;
	rk[x][y].push_back(++num[col]);
	dfs(x - tp, y + 1 - tp, tp ^ 1, col);
}
inline void foo(ll x, ll d) {ans += d * x * (x - 1);}
void work(int id, int pos)
{
	set<int>::iterator it = a[id].lower_bound(pos);
	it--;
	int pre = *(it), suf = *(a[id].upper_bound(pos));
	if(!a[id].count(pos))
	{
		foo(suf - pre - 1, -1);
		foo(pos - pre - 1, 1);
		foo(suf - pos - 1, 1);
		a[id].insert(pos);
		ans--;
	}
	else
	{
		foo(suf - pos - 1, -1);
		foo(pos - pre - 1, -1);
		foo(suf - pre - 1, 1);
		a[id].erase(pos);
		ans++;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) dfs(i, 1, 1, ++cnt);
	for (int i = 1; i <= m; i++) dfs(n, i, 0, ++cnt);
	ans = n * m * 2;
	for (int i = 1; i <= cnt; i++) a[i].insert(0), a[i].insert(num[i] + 1), foo(num[i], 1);
	while(q--)
	{
		scanf("%d%d", &x, &y);
		x = n - x + 1;
		work(x + y - 1, rk[x][y][0]), work(x + y, rk[x][y][1]);
		printf("%lld\n", ans / 2);
	}
	return 0;
}