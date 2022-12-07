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

const int P = 998244353;
const int N = 5013;
int h[N], ne[N<<1], to[N<<1], tot, n, k;
inline void add(int x, int y) { ne[++tot] = h[x], to[h[x] = tot] = y; }
ll f[N][N], dp[N];
int siz[N];
void dfs(int x, int fa) {
	siz[x] = f[x][0] = 1;
	static ll g[N];
	for (int i = h[x]; i; i = ne[i]) {
		int y = to[i]; if (y == fa) continue;
		dfs(y, x);
		memset(g, 0, 8 * (siz[x] + siz[y]));
		for (int a = 0;a < siz[x] && a <= k; ++a) 
			for (int b = 0;b < siz[y] && b <= k; ++b) {
				int t = max(a, b + 1);
				if (a + b + 1 <= k) g[t] = (g[t] + f[x][a] * f[y][b]) % P;
				g[a] = (g[a] + f[x][a] * f[y][b]) % P;
			}
		siz[x] += siz[y];
		memcpy(f[x], g, siz[x] * 8);
	}
}

int main() {
	read(n), read(k);
	for (int i = 1, x, y;i < n; ++i)
		read(x), read(y), add(x, y), add(y, x);
	dfs(1, 0);
	ll ans = 0;
	for (int i = 0;i <= k; ++i) ans += f[1][i];
	write(ans % P);
	return 0;
}