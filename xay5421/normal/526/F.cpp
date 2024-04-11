// by LJC00118
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
  
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3e5 + 5;

struct node_t { int l, r, minn, cnt, tag; } p[N << 2];

int st1[N], st2[N], a[N];
int n, top1, top2; ll ans;

void update(int u) {
	p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
	p[u].cnt = 0;
	if (p[u << 1].minn == p[u].minn) p[u].cnt += p[u << 1].cnt;
	if (p[u << 1 | 1].minn == p[u].minn) p[u].cnt += p[u << 1 | 1].cnt;
}

void add_tag(int u, int x) {
	p[u].minn += x;
	p[u].tag += x;
}

void pushdown(int u) {
	if (p[u].tag) {
		add_tag(u << 1, p[u].tag);
		add_tag(u << 1 | 1, p[u].tag);
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r;
	if (l == r) {
		p[u].minn = l; p[u].cnt = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	update(u);
}

void add(int u, int l, int r, int x) {
	if (l <= p[u].l && p[u].r <= r) {
		add_tag(u, x);
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if (mid >= l) add(u << 1, l, r, x);
	if (mid + 1 <= r) add(u << 1 | 1, l, r, x);
	update(u);
}

int main() {
	read(n);
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		read(x); read(y);
		a[x] = y;
	}
	for (int i = 1; i <= n; i++) {
		while (top1 && a[st1[top1]] < a[i]) add(1, top1 > 1 ? st1[top1 - 1] + 1 : 1, st1[top1], a[i] - a[st1[top1]]), --top1;
		st1[++top1] = i;
		while (top2 && a[st2[top2]] > a[i]) add(1, top2 > 1 ? st2[top2 - 1] + 1 : 1, st2[top2], a[st2[top2]] - a[i]), --top2;
		st2[++top2] = i;
		ans += p[1].cnt;
	}
	print(ans, '\n');
    return 0;
}