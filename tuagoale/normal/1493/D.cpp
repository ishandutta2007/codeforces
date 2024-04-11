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

const int P = 1e9 + 7;
const int N = 200050;
const int lim = 200005;
ll ans = 1;
#include <map>
map<int, int> mp[N];
int all[N], e[N], pr[N], tot, n, q;
void del(int x) {
	ans = ans * x % P;
	for (int i = 1;i <= n; ++i) {
		mp[i][x]--; if (!mp[i][x]) all[x]--;
	}
}
void addin(int x, int y) {
	while (y != 1) {
		int t = e[y], tm = 0;
		while (y % t == 0) y /= t, ++tm;
		int tt = mp[x][t];
		mp[x][t] += tm;
		if (!tt) {
			all[t]++;
			while (all[t] == n) del(t);
		}
	}
}

int main() {
	read(n), read(q);
	for (int i = 2;i <= lim; ++i) {
		if (!e[i]) pr[++tot] = e[i] = i;
		for (int j = 1;j <= tot && pr[j] * i <= lim; ++j) {
			e[pr[j] * i] = pr[j]; if (pr[j] == e[i]) break;
		}
	}
	for (int i = 1, x;i <= n; ++i) read(x), addin(i, x);
	for (int i = 1, x, y;i <= q; ++i) 
		read(x), read(y), addin(x, y), write(ans);
	return 0;
}