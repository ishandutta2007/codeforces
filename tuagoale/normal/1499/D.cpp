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

const int N = 20000050;
int e[N], pr[N], w[N], tot;
void prework(int lim) {
	w[1] = 1;
	for (int i = 2;i <= lim; ++i) {
		if (!e[i]) pr[e[i] = ++tot] = i, w[i] = 2;
		for (int j = 1;j <= e[i] && pr[j] * i <= lim; ++j) 
			e[pr[j] * i] = j, w[pr[j] * i] = w[i] * (j != e[i] ? 2 : 1);
	}
}

int T, c, d, x;
int main() {
	for (read(T), prework(2e7); T; T--) {
		ll ans = 0;
		auto solve = [&](ll t) {
			ll tx = x / t + d;
			if (tx % c) return 0;
			tx /= c;
			return w[tx];
		};
		read(c), read(d), read(x);
		for (int i = 1;i * i <= x; ++i) if (x % i == 0) {
			ans += solve(i); if (i * i != x) ans += solve(x / i);
		}
		write(ans);
	}
	return 0;
}

/*

1
5 7 6

*/