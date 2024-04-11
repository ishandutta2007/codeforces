#include <algorithm>
#include <bitset>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1000005;
const int INF = 0x3f3f3f3f;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x * f;
}
int n, m, w;
int cnt1, cnt2, ans[N], fa[N], siz[N];

int fir[N << 2], to[N << 4], nxt[N << 4], tot;
inline void ins(int x, int y) { to[++tot] = y, nxt[tot] = fir[x], fir[x] = tot; }

int Getbel(int x) { return fa[x] == x ? x : Getbel(fa[x]); }

struct Change {
	int x, y;
} p[N];
struct Query {
	int x, t, id;
} q[N], q1[N], q2[N];

void modify(int o, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		ins(o, v);
		return;
	}
	int mid = (l + r) >> 1;
	if (ql <= mid)
		modify(o << 1, l, mid, ql, qr, v);
	if (qr > mid)
		modify(o << 1 | 1, mid + 1, r, ql, qr, v);
}
vector<int>V[N];
int X[N], Y[N];
int tp;
pii tmp[N];
inline void unit(int x, int y) {
	x = Getbel(x), y = Getbel(y);
	if (x == y)
		return;
	if (siz[x] < siz[y])
		swap(x, y);
	fa[y] = x;
	tmp[++tp] = make_pair(y, siz[y]);
	tmp[++tp] = make_pair(x, siz[x]);
	siz[x] += siz[y];
}
inline void undo(int u)
{
	while (tp > u)
	{
		pii t = tmp[tp--];
		int x = t.first, rk = t.second;
		fa[x] = x;
		siz[x] = rk;
	}
}
void solve(int o, int l, int r, int ql, int qr)
{
	if (ql > qr)
		return;
	int cur = tp;
	for (int i = fir[o]; i; i = nxt[i])
		unit(p[to[i]].x, p[to[i]].y);
	if (l == r)
	{
		for (int i = ql; i <= qr; i++)
			ans[q[i].id] = siz[Getbel(q[i].x)];
		undo(cur);
		return;
	}
	int tp1 = 0, tp2 = 0, mid = (l + r) >> 1;
	for (int i = ql; i <= qr; i++)
		if (q[i].t <= mid)
			q1[++tp1] = q[i];
		else
			q2[++tp2] = q[i];
	for (int i = 1; i <= tp1; i++)
		q[ql + i - 1] = q1[i];
	for (int i = 1; i <= tp2; i++)
		q[ql + tp1 + i - 1] = q2[i];
	solve(o << 1, l, mid, ql, ql + tp1 - 1);
	solve(o << 1 | 1, mid + 1, r, ql + tp1, qr);
	undo(cur);
}
int main()
{
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; i++)
		fa[i] = i, siz[i] = 1;
	int now = 1;
	for (int i = 1; i <= m; i++)
	{
		int opt = read();
		if (opt == 1)
		{
			int x = read(), y = read();
			if (x > y)
				swap(x, y);
			X[i] = x, Y[i] = y;
			V[min(m + 1, now + w)].push_back(i);
		}
		if (opt == 2)
		{
			int z = read();
			++cnt2;
			q[cnt2] = (Query){ z, i, cnt2 };
		}
		if (opt == 3)
		{
			now++;
			for (int j = 0; j < (int)V[now].size(); j++)
			{
				modify(1, 1, m, V[now][j], i - 1, ++cnt1);
				p[cnt1] = (Change){X[V[now][j]], Y[V[now][j]]};
			}
		}
	}
	for (int i = now + 1; i <= m + 1; i++)
		for (int j = 0; j < (int)V[i].size(); j++)
		{
			modify(1, 1, m, V[i][j], m, ++cnt1);
			p[cnt1] = (Change){X[V[i][j]], Y[V[i][j]]};
		}
	solve(1, 1, m, 1, cnt2);
	for (int i = 1; i <= cnt2; i++)
		printf("%d\n", ans[i]);
}