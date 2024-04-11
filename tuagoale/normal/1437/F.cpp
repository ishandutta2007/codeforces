
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

const int N = 5005;
const int P = 998244353;
ll fac[N], inv[N], dp[N], a[N], n;
ll A(int n, int m) { return fac[n] * inv[n-m] % P; }
int cnt[N];
ll fpw(ll x, ll mi) {
	ll res = 1;
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

int main() {
	read(n);
	for (int i = 1;i <= n; i++) read(a[i]);
	fac[0] = 1;
	for (int i = 1;i <= n; i++)
		fac[i] = fac[i-1] * i % P;
	inv[n] = fpw(fac[n], P - 2);
	for (int i = n - 1; i >= 1; i--) 
		inv[i] = inv[i+1] * (i + 1) % P;
	inv[0] = dp[0] = 1, sort(a + 1, a + n + 1);
	int j = 0;
	if (a[n-1] * 2 > a[n]) return write(0), 0;
	for (int i = 1;i <= n; i++) { 
		while (j < n && a[j+1] * 2 <= a[i]) j++;
		cnt[i] = j, dp[i] = A(n - 1, cnt[i]); 
		for (int j = 1;j < i; j++) 
			if (a[j] * 2 <= a[i]) dp[i] = (dp[i] + dp[j] * A(n - cnt[j] - 2, cnt[i] - cnt[j] - 1)) % P;
	} 
	write(dp[n]);
	return 0;
}