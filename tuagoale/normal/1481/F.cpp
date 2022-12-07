/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
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

const int N = 200500;
int ne[N<<1], to[N<<1], h[N], tot;
inline void add(int x, int y) {
	ne[++tot] = h[x], to[h[x] = tot] = y;
}

int cnt[N], D[N], mxdep, n, x;
vector<int> vec[N];
#include <bitset>
bitset< 50019 > bit[355], B[355], nw;
int ans[N], col[N], deg[N], bl, S = 350;
void dfs(int x, int dep, int fa) {
	vec[D[x] = dep].push_back(x);
	cnt[dep]++, Mx(mxdep, dep);
	for (int i = h[x]; i; i = ne[i]) 
		if (to[i] != fa) deg[x]++, dfs(to[i], dep + 1, x);
}

int main() {
//	freopen ("hs.in","r",stdin);
//	freopen ("hs.out","w",stdout);
	read(n), read(x);
	for (int i = 2, x;i <= n; ++i) read(x), add(x, i), add(i, x);
	dfs(1, 1, 0);
	char a = 'a', b = 'b';
	if (x + x > n) x = n - x, swap(a, b);
	nw[0] = 1, bit[++bl] = nw;
	for (int i = 1;i <= n; ++i) {
		if (!cnt[i]) break;
		nw |= nw << cnt[i];
		if (i % S == 0) bit[++bl] = nw;
	}
	if (!nw[x]) {
		write(mxdep + 1);
		int spj = 0, y = n - x;
		for (int i = 1;i <= mxdep; ++i) {
			if (cnt[i] <= x) {
				for (auto t: vec[i]) ans[t] = a;
				x -= cnt[i];
				continue;
			}
			if (cnt[i] <= y) {
				for (auto t: vec[i]) ans[t] = b;
				y -= cnt[i];
				continue;
			}
			spj = i;
		}
		char tt = x < y ? a : b; int k = min(x, y);
		for (auto t: vec[spj]) 
			if (!deg[t]) ans[t] = k ? (k -= 1, tt) : (a ^ b ^ tt);
		for (auto t: vec[spj])
			if (!ans[t]) ans[t] = a ^ b ^ tt;
		for (int i = 1;i <= n; ++i) putchar(ans[i]);
		return 0;
	}
	write(mxdep);
	for (int i = bl;i >= 1; --i) {
		int st = (i - 1) * S;
		B[0] = bit[i];
		for (int j = st + 1;j <= st + S; ++j) {
			if (!cnt[j]) break;
			B[j - st] = B[j - 1 - st] | B[j - 1 - st] << cnt[j];
		}
		while (mxdep > st) {
			if (B[mxdep - st][x] && !B[mxdep - st - 1][x]) 
				x -= cnt[mxdep], col[mxdep] = 1;
			--mxdep;
		}
	}
	for (int i = 1;i <= n; ++i) putchar(col[D[i]] ? a : b);
	return 0;
}

/*

9 4
1 2 2 2 2 2 1 2

1 0

*/