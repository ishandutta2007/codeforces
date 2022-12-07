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

#include <cmath>
const int N = 5005;
int T, n, a[N], s[N];
ll dp[N];
int main() {
//	freopen ("hs.in","r",stdin);
	for (read(T); T; T--) {
		read(n); memset(dp, 0, sizeof(dp));
		for (int i = 1;i <= n; ++i) read(a[i]);
		for (int i = 1;i <= n; ++i) read(s[i]);
		ll ans = 0;
		for (int i = 2;i <= n; ++i) {
			for (int t = i - 1;t >= 1; --t) if (a[i] != a[t]) {
				ll tm = dp[i];
				Mx(tm, dp[t] + abs(s[t] - s[i]));
				Mx(dp[t], dp[i] + abs(s[t] - s[i]));
				dp[i] = tm;
			}
		}
		for (int i = 1;i <= n; ++i) Mx(ans, dp[i]);
		write(ans);
	}
	return 0;
}