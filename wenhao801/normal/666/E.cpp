#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

const int MAXN = 500500;

namespace seg {
	struct node {
		int ls, rs, val, mxpos;
		node operator + (const node &other) const {
			bool res = (val > other.val) || (val == other.val && mxpos < other.mxpos);
			if (res) return {0, 0, val, mxpos};
			else return other;
		}
	} t[MAXN << 4];
	int rt[MAXN], top;
	void pushup (int x) { const int ls = t[x].ls, rs = t[x].rs; t[x] = t[t[x].ls] + t[t[x].rs]; t[x].ls = ls, t[x].rs = rs; }
	void modify (int pos, int l, int r, int x) {
		if (l == r) { ++t[x].val, t[x].mxpos = pos; return; }
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			if (!t[x].ls) t[x].ls = ++top;
			modify(pos, l, mid, t[x].ls);
		}
		else {
			if (!t[x].rs) t[x].rs = ++top;
			modify(pos, mid + 1, r, t[x].rs);
		}
		pushup(x);
	}
	node query (int l, int r, int L, int R, int x) {
		if (!x || (l <= L && R <= r)) return t[x];
		int mid = (L + R) >> 1;
		if (l <= mid && mid < r) return query(l, r, L, mid, t[x].ls) + query(l, r, mid + 1, R, t[x].rs);
		else if (l <= mid) return query(l, r, L, mid, t[x].ls);
		else return query(l, r, mid + 1, R, t[x].rs);
	}
	int merge (int l, int r, int x, int y) {
		if (!x || !y) return x + y;
		int ret = ++top; 
		if (l == r) { t[ret] = t[x]; t[ret].val += t[y].val; t[ret].mxpos = l; return ret; }
		int mid = (l + r) >> 1;
		t[ret].ls = merge(l, mid, t[x].ls, t[y].ls); t[ret].rs = merge(mid + 1, r, t[x].rs, t[y].rs);
		pushup(ret); return ret;
	}
}

struct node { int len, link, ch[26]; } t[MAXN];
int las = 1, top = 1;

inline int newnode () { ++top; seg::rt[top] = ++seg::top; return top; }
void extend (int c) {
	if (t[las].ch[c]) {
		int tmp = t[las].ch[c];
		if (t[tmp].len == t[las].len + 1) { las = tmp; return; }
		int cl = newnode(); t[cl] = t[tmp], t[cl].len = t[las].len + 1;
		for (int i = las; t[i].ch[c] == tmp; i = t[i].link) t[i].ch[c] = cl;
		t[tmp].link = cl; las = cl; return;
	}
	int i, now = newnode(); t[now].len = t[las].len + 1;
	for (i = las; i && !t[i].ch[c]; i = t[i].link) t[i].ch[c] = now;
	las = now;
	if (!i) { t[now].link = 1; return; }
	int tmp = t[i].ch[c];
	if (t[tmp].len == t[i].len + 1) { t[now].link = tmp; return; }
	int cl = newnode(); t[cl] = t[tmp], t[cl].len = t[i].len + 1;
	for (; t[i].ch[c] == tmp; i = t[i].link) t[i].ch[c] = cl;
	t[tmp].link = t[now].link = cl;
}

char a[MAXN], s[MAXN];

int n, m, fa[MAXN][22], pos[MAXN], slen[MAXN];
vector <int> E[MAXN];
inline void pre (int x) { for (auto i: E[x]) pre(i), seg::rt[x] = seg::merge(1, n, seg::rt[x], seg::rt[i]); }

int main () {
	scanf("%s", a + 1); int i, j;
	m = strlen(a + 1); scanf("%d", &n);
	seg::rt[1] = ++seg::top;
	for (i = 1; i <= n; i++) {
		las = 1;
		scanf("%s", s + 1); int len = strlen(s + 1);
		for (j = 1; j <= len; j++) {
			extend(s[j] - 'a');
			seg::modify(i, 1, n, seg::rt[las]);
		}
	}
	for (i = 2; i <= top; i++) E[t[i].link].emplace_back(i), fa[i][0] = t[i].link;
	pre(1);
	for (j = 1; j <= 20; j++) for (i = 1; i <= top; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
	int now = 1, len = 0;
	for (i = 1; i <= m; i++) {
		while (now != 1 && !t[now].ch[a[i] - 'a']) now = t[now].link, len = t[now].len;
		if (t[now].ch[a[i] - 'a']) now = t[now].ch[a[i] - 'a'], ++len;
		pos[i] = now, slen[i] = len;
	}
	int q; scanf("%d", &q); while (q--) {
		int ln, rn, lm, rm;
		scanf("%d%d%d%d", &ln, &rn, &lm, &rm);
		now = pos[rm], len = rm - lm + 1;
		if (slen[rm] < len) { printf("%d 0\n", ln); continue; }
		if (t[fa[now][0]].len + 1 > len) {
			for (int i = 20; i >= 0; i--) if (fa[now][i] && t[fa[fa[now][i]][0]].len + 1 > len) now = fa[now][i];
			now = fa[now][0];
		}
		auto res = seg::query(ln, rn, 1, n, seg::rt[now]);
		if (!res.val) printf("%d 0\n", ln);
		else printf("%d %d\n", res.mxpos, res.val);
	}
	return 0;
}