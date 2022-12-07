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

#include <unordered_map>
int tot;
#define ull unsigned ll
unordered_map<ull, int> mp;
inline ull Rand(void) {
	ull x = rand();
	x = x << 16 ^ rand();
	x = x << 16 ^ rand();
	return x << 16 ^ rand();
}
const int N = 10005009;
int e[N], pr[N]; ull val[N], a[N];
void prework(int lim) {
	for (int i = 2;i <= lim; ++i) {
		if (!e[i]) pr[e[i] = ++tot] = i, val[i] = Rand();
		for (int j = 1;pr[j] * i <= lim && j <= e[i]; ++j)
			e[pr[j] * i] = j;
	}
}

int poi[25], tp[25], ans, n, k, T;
int main() {
//	freopen ("hs.in","r",stdin);
	srand((ll)new char);
	for (prework(1e7), read(T); T; T--) {
		read(n), read(k);
		for (int i = 1, x;i <= n; ++i) {
			read(x), a[i] = 0;
			while (x > 1) a[i] ^= val[pr[e[x]]], x /= pr[e[x]];
		}
		for (int i = 0;i <= k; ++i) poi[i] = 1;
		int ans = 0;
		for (int i = 1;i <= n; ++i) {
			memset(tp, 0, sizeof(tp));
			int fl = 0;
			for (int j = 0;j <= k; ++j) 
				if (poi[j] > n) { fl = 1; break; }
			if (fl) break;
			ans++;
			for (int j = 0;j <= k; ++j) {
				mp.clear();
				int tt = j;
				for (int t = poi[j];t <= n; ++t) {
					if (mp.count(a[t])) ++tt;
					else mp[a[t]] = 1;
					if (tt > k) break;
					Mx(tp[tt], t + 1);
				}
			}
			memcpy(poi, tp, sizeof(tp));
		}
		write(ans);
	}
	return 0;
}