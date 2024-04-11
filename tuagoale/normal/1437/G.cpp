
/*
 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)

 */

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 600050;
int ch[N][26], en[N], f[N], id[N], ed[N], cnt = 1;
char s[N];
inline void insert(char *s, int k) {
	int p = 1, len = strlen(s + 1); 
	for (int i = 1;i <= len; i++) {
		int c = s[i] - 'a';
		if (!ch[p][c]) ch[p][c] = ++cnt;
		p = ch[p][c];
	}
	en[k] = p, ed[p] = k;
}

int dep[N], siz[N], son[N], Top[N], dfn[N], num;
int h[N], ne[N<<1], to[N<<1], tot;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
void dfs(int x) {
	dep[x] = dep[f[x]] + (siz[x] = 1);
	for (int i = h[x], y; i; i = ne[i]) {
		dfs(y = to[i]), siz[x] += siz[y];
		if (siz[son[x]] < siz[y]) son[x] = y;
	}
}

void dfs2(int x, int topf) {
	Top[x] = topf, dfn[x] = ++num, id[num] = x;
	if (son[x]) dfs2(son[x], topf);
	for (int i = h[x], y; i; i = ne[i])
		if ((y = to[i]) != son[x]) dfs2(y, y);
}

void build(void) {
    queue<int> q;
    for (int i = 0;i < 26; i++)
        if (ch[1][i]) q.push(ch[1][i]), f[ch[1][i]] = 1;
        else ch[1][i] = 1;
    while (q.size()) {
        int x = q.front(); q.pop();
        if (x != 1) add(f[x], x);
        for (int i = 0;i < 26; i++) {
            if (!ch[x][i]) ch[x][i] = ch[f[x]][i];
            else q.push(ch[x][i]), f[ch[x][i]] = ch[f[x]][i];
        }
    }
}

#define ls p << 1
#define rs ls | 1
int mx[N<<2];

void build(int p, int l, int r) {
	mx[p] = -1;
	if (l == r) return mx[p] = ed[id[l]] ? 0 : -1, void();
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	mx[p] = max(mx[ls], mx[rs]);
}

void change(int p, int l, int r, int x, int c) {
	if (l == r) return mx[p] = c, void();
	int mid = (l + r) >> 1;
	if (x <= mid) change(ls, l, mid, x, c);
	else change(rs, mid + 1, r, x, c);
	mx[p] = max(mx[ls], mx[rs]);
}

void query(int p, int l, int r, int L, int R, int &ans) {
	if (L <= l && r <= R) return Mx(ans, mx[p]);
	int mid = (l + r) >> 1;
	if (L <= mid) query(ls, l, mid, L, R, ans);
	if (R > mid) query(rs, mid + 1, r, L, R, ans);
}

void query(int x, int &ans) {
	while (x) {
		query(1, 1, num, dfn[Top[x]], dfn[x], ans);
		x = f[Top[x]];
	}
}

struct Heap {
	priority_queue<int> A, B;
	void update(void) { while (B.size() && A.top() == B.top()) A.pop(), B.pop(); }
	int Top(void) { update(); return A.top(); }
	void del(int x) { B.push(x); }
	void push(int x) { A.push(x); }
}q[300005];

int pre[N], n, m;
int main() {
	read(n), read(m);
	for (int i = 1;i <= n; i++) 
		scanf ("%s", s + 1), insert(s, i), q[en[i]].push(0);
	build(), dfs(1), dfs2(1, 1), build(1, 1, num);
	for (int i = 1, x, y;i <= m; i++) {
		int op; read(op);
		if (op == 1) {
			read(x), read(y);
			q[en[x]].push(y), q[en[x]].del(pre[x]), pre[x] = y;
			change(1, 1, num, dfn[en[x]], q[en[x]].Top());
		}
		else {
			scanf ("%s", s + 1);
			int len = strlen(s + 1), nw = 1, ans = -1;
			for (int i = 1;i <= len; i++) {
				nw = ch[nw][s[i] - 'a'];
				query(nw, ans);
			}
			write(ans);
		}
	}
	return 0;
}