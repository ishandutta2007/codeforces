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

//#pragma GCC optimize(2)
const int N = 500500;
vector<int> vec[N];
int a[N<<1], b[N<<1], m, n, t; ll k, cir, T;
int cnt[N << 1], id[N], B[N<<1];
bool check(ll tim) {
	ll ans = tim;
	for (int i = 0;i < n; ++i) if (B[a[i]] && ((B[a[i]] - 1) % t == i % t)) {
		if (tim < i) continue;
		ll rd = (tim - i - 1) / cir;
		ll L = id[i], R = (tim - rd * cir - i - 1) / n;
		int t = id[B[a[i]] - 1];
		ans -= rd, R += L;
		if (t >= L && t <= R) --ans;
		if (t + T >= L && t + T <= R) --ans;
	}
	return ans < k;
}

int main() {
//	freopen ("hs.in","r",stdin);
	read(n), read(m), read(k);
	for (int i = 0;i < n; ++i) read(a[i]);
	for (int j = 0;j < m; ++j) read(b[j]);
	if (n > m) swap(n, m), swap(a, b);
	for (int j = 0;j < m; ++j) B[b[j]] = j + 1;
	t = __gcd(n, m), cir = 1ll * n * m / t, T = m / t;
	for (int i = 0;i < t; ++i) {
		vec[i].push_back(i), id[i] = 0; 
		int x = (i + n) % m;
		while (x != i) id[x] = vec[i].size(), vec[i].push_back(x), x = (x + n) % m;
	}
	ll l = 1, r = 1e18;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	write(l);
	return 0;
}