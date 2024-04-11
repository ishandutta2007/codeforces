
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

const int N = 500050;
int st[N], a[N], vis[N], n, k, tp;
void insert(int x) {
	if (!tp) return st[++tp] = x, void();
	int l = 1, r = tp;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (st[mid] <= x) l = mid + 1;
		else r = mid - 1;
	}
	if (l > tp) st[++tp] = x;
	else st[l] = x;
}

int main() {
	read(n), read(k);
	for (int i = 1;i <= n; i++) read(a[i]), a[i] -= i;
	for (int i = 1, x;i <= k; i++) read(x), vis[x] = 1;
	int lim = -1e9;
	for (int i = 1;i <= n; i++) {
		if (vis[i] == 1) {
			if (a[i] < lim) return write(-1), 0;
			Mx(lim, a[i]);
		}
		if (a[i] < lim) vis[i] = -1;
	}
	lim = 1e9;
	for (int i = n;i >= 1; i--) {
		if (vis[i] == 1) {
			if (a[i] > lim) return write(-1), 0;
			Mn(lim, a[i]);
		}
		if (a[i] > lim) vis[i] = -1;
	}
	memset(st, 0x3f, sizeof(st)); 
	st[tp = 0] = 0;
	for (int i = 1;i <= n; i++) {
		if (vis[i]) continue;
		insert(a[i]);
	}
	write(n - k - tp);
	return 0;
}