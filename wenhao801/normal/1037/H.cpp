#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int MAXN = 200200;
struct SAM { int len, slink, trans[26]; } t[MAXN];
int top = 1, las = 1;
void extend (int c) {
	int now = ++top, i; t[now].len = t[las].len + 1;
	for (i = las; i && !t[i].trans[c]; i = t[i].slink) t[i].trans[c] = now;
	las = now;
	if (!i) { t[now].slink = 1; return; }
	int rua = t[i].trans[c];
	if (t[rua].len == t[i].len + 1) { t[now].slink = rua; return; }
	int cl = ++top; t[cl] = t[rua]; t[cl].len = t[i].len + 1;
	for (i; i && t[i].trans[c] == rua; i = t[i].slink) t[i].trans[c] = cl;
	t[rua].slink = t[now].slink = cl;
}
char s[MAXN], tmp[MAXN];
vector <int> E[MAXN];

namespace seg {
	struct node { int ls, rs, val; } t[MAXN << 5]; int top;
	void pushup (int x) { t[x].val = t[t[x].ls].val + t[t[x].rs].val; }
	void modify (int pos, int k, int L, int R, int &x) {
		int prex = x; x = ++top; t[x] = t[prex];
		if (L == R) { t[x].val += k; return; }
		int mid = (L + R) >> 1;
		if (pos <= mid) modify(pos, k, L, mid, t[x].ls);
		else modify(pos, k, mid + 1, R, t[x].rs);
		pushup(x);
	}
	int query (int l, int r, int L, int R, int x) {
		if (!x) return 0;
		if (l <= L && R <= r) return t[x].val;
		int mid = (L + R) >> 1, ret = 0;
		if (l <= mid) ret += query(l, r, L, mid, t[x].ls);
		if (mid < r) ret += query(l, r, mid + 1, R, t[x].rs);
		return ret;
	}
	int merge (int x, int y, int L, int R) {
		if (!x || !y) return x | y;
		int ret = ++top, mid = (L + R) >> 1;
		if (L == R) { t[ret].val = t[x].val | t[y].val; return ret; }
		t[ret].ls = merge(t[x].ls, t[y].ls, L, mid);
		t[ret].rs = merge(t[x].rs, t[y].rs, mid + 1, R);
		pushup(ret); return ret;
	}
}
int rt[MAXN], n;
void dfs (int x) {
	if (!rt[x]) rt[x] = ++seg::top;
	for (auto i: E[x]) {
		dfs(i);
		rt[x] = seg::merge(rt[x], rt[i], 1, n);
	}
}
bool check (int l, int r, int len, int x) { return seg::query(l + len - 1, r, 1, n, rt[x]); }

char ans[MAXN];
int solve (int l, int r, char *s, int len, int now, int olen) {
	// printf("solve %d %d %d %d\n", l, r, len, now);
	if (len && t[now].trans[s[0] - 'a'] && check(l, r, olen - len + 1, t[now].trans[s[0] - 'a'])) {
		int res = solve(l, r, s + 1, len - 1, t[now].trans[s[0] - 'a'], olen);
		if (res != -1) { ans[len] = s[0]; return res; }
	}
	for (int i = len ? (s[0] - 'a' + 1) : 0; i < 26; i++) 
		if (t[now].trans[i] && check(l, r, olen - len + 1, t[now].trans[i])) {
			ans[len] = i + 'a';
			// printf("here %d\n", len);
			return len;
		}
	return -1;
}

int main () {
	scanf("%s", s + 1); n = strlen(s + 1);
	int i, j; rt[1] = ++seg::top;
	for (i = 1; i <= n; i++) extend(s[i] - 'a'), seg::modify(i, 1, 1, n, rt[las]);
	for (i = 2; i <= top; i++) E[t[i].slink].push_back(i);
	dfs(1);
	int Q; scanf("%d", &Q);
	while (Q--) {
		int l, r; scanf("%d%d%s", &l, &r, tmp + 1);
		int len = strlen(tmp + 1);
		int res = solve(l, r, tmp + 1, len, 1, len);
		if (res == -1) puts("-1");
		else { for (i = len; i >= res; i--) putchar(ans[i]); puts(""); }
	}
	return 0;
}