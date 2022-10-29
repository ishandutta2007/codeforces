#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

#define l(x) t[x].l
#define r(x) t[x].r
#define dat(x) t[x].dat
#define sum(x) t[x].sum
#define add(x) t[x].add 
#define clean(x, y) memset(x, y, sizeof(x))
const int maxn = 4e5 + 100;
const int inf = 2e9;
typedef long long LL;
using namespace std;

template <typename T>
inline void read(T &s) {
    s = 0;
    T w = 1, ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') w = -1; ch = getchar(); }
    while (isdigit(ch))  { s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar(); }
    s *= w;
}

template<typename T>
inline void write(T s) {
	if (s < 0) putchar('-'), s = -s;
	if (s > 9) write(s / 10);
	putchar(s % 10 + '0');
}

int n;
int a[maxn];
struct tree {
	int l, r;
	LL dat, sum, add;
} t[maxn << 2];

void build(int p, int l, int r) {
	l(p) = l, r(p) = r;
	if (l == r) { sum(p) = a[l]; return ; }
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	dat(p) = dat(p << 1) + dat(p << 1 | 1);
//	sum(p) = sum(p << 1) + sum(p << 1 | 1); 
}

void spread(int p) {
	if (add(p)) {
//		sum(p << 1) = add(p) * (r(p << 1) - l(p << 1) + 1);
//		sum(p << 1 | 1) = add(p) * (r(p << 1 | 1) - l(p << 1 | 1) + 1);
		add(p << 1) += add(p);
		add(p << 1 | 1) += add(p);
		dat(p << 1) += add(p);
		dat(p << 1 | 1) += add(p);
		add(p) = 0;
	}
}

void change(int p, int l, int r, int d) {
	if (l <= l(p) && r >= r(p)) {
		sum(p) += (LL) d * (r(p) - l(p) + 1);
		add(p) += d;
		dat(p) += d;
		return ;
	}
	spread(p);
	int mid = (l(p) + r(p)) >> 1;
	if (l <= mid) change(p << 1, l, r, d);
	if (r > mid) change(p << 1 | 1, l, r, d);
	sum(p) = sum(p << 1) + sum(p << 1 | 1);
	dat(p) = max(dat(p << 1), dat(p << 1 | 1));
}

LL ask(int p, int l, int r) {
	if (l <= l(p) && r >= r(p)) return dat(p);
	spread(p);
	int mid = (l(p) + r(p)) >> 1;
	LL val = 0;
	if (l <= mid) val = max(val, ask(p << 1, l, r));
	if (r > mid)  val = max(val, ask(p << 1 | 1, l, r));
	return val;
}
int pos[400005];
int main() {
	read(n);
	build(1, 1, n);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		pos[x]=i;
	}
	int now=n;
	change(1,1,pos[n],1);
	for(int i=1;i<=n;i++)
	{
		write(now),putchar(' ');
		int x;
		read(x);
		change(1,1,x,-1);
		while(ask(1,1,n)<=0&&now>1)
		{
			--now;
			change(1,1,pos[now],1);
		}
	}
	/*for (int i = 1; i <= n; ++i) {
		int opt, x, y;
		read(opt), read(x), read(y);
		if (opt == 1)
			change(1, x, y, 1);
		else
			write(ask(1, x, y)), putchar('\n');
	}*/
	return 0;
}