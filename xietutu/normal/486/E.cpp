#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ull;
const int maxn = 100010, INF = 100001, M = 1e9+7;
char s[maxn];
int TC, n, maxl, a[maxn], fl[maxn], fr[maxn], g[maxn];
ull gl[maxn], gr[maxn];
struct node {
	ull v;
	node *ls, *rs; 
} TS[maxn * 22], *null = TS;
node* newnode() {
	node* x = TS + (++TC);
	x->ls = x->rs = null;
	x->v = 0;
	return x;
}
struct Tree {
	node* root; int st, ed, pos; ull delta;
	void init() {
		root = newnode();
	}
	void modify(node* now, int l, int r) {
		if (l == r) {
			now->v = (now->v + delta) % M;
			return;
		}
		int mid = (l + r) / 2;
		if (pos <= mid) {
			if (now->ls == null) now->ls = newnode();
			modify(now->ls, l, mid);
		}
		else {
			if (now->rs == null) now->rs = newnode();
			modify(now->rs, mid + 1, r);
		}
		now->v = (now->ls->v + now->rs->v) % M;
	}
	ull query(node* now, int l, int r) {
		if (now == null) return 0;
		if (st <= l && r <= ed) return now->v;
		int mid = (l + r) / 2; ull ret = 0;
		if (st <= mid) ret = query(now->ls, l, mid);
		if (mid < ed) ret = (ret + query(now->rs, mid + 1, r)) % M;
		return ret;
	}
	void Modify(int p, ull v) {
		pos = p; delta = v;
		modify(root, 0, 100000); 
	}
	ull Query(int p) {
		st = 0; ed = p;
		return query(root, 0, 100000);
	}
} T[maxn];
void solvel() {
	for (int i = 1; i <= n; ++i)
		g[i] = INF;
	for (int i = 1; i <= n; ++i) {
		int k = lower_bound(g + 1, g + n + 1, a[i]) - g;
		fl[i] = k;
		g[k] = a[i];
	}
	
	for (int i = 0; i <= n; ++i)
		T[i].init();
	T[0].Modify(0, 1);
	for (int i = 1; i <= n; ++i) {
		int now = fl[i];
		gl[i] = T[now - 1].Query(a[i] - 1);
		T[now].Modify(a[i], gl[i]);
	}
}
void solver() {
	TC = 0;
	for (int i = 1; i <= n; ++i)
		a[i] = INF - a[i];
	for (int i = 1; i <= n; ++i)
		g[i] = INF;
	for (int i = n; i >= 1; --i) {
		int k = lower_bound(g + 1, g + n + 1, a[i]) - g;
		fr[i] = k;
		g[k] = a[i];
	}
	
	for (int i = 0; i <= n; ++i)
		T[i].init();
	T[0].Modify(0, 1);
	for (int i = n; i >= 1; --i) {
		int now = fr[i];
		gr[i] = T[now - 1].Query(a[i] - 1);
		T[now].Modify(a[i], gr[i]);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	solvel();
	solver();
	ull tot = 0;
	for (int i = 1; i <= n; ++i)
		maxl = max(maxl, fl[i]);
	for (int i = 1; i <= n; ++i)
		if (fl[i] == maxl) tot = (tot + gl[i]) % M;

	for (int i = 1; i <= n; ++i)
		if (fl[i] + fr[i] - 1 == maxl) {
			if (1LL * gl[i] * gr[i] % M == tot) s[i] = '0' + 3;
			else s[i] = '0' + 2;
		}
		else s[i] = '0' + 1;
	printf("%s\n", s + 1);
}