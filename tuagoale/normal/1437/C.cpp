
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

#include <cmath>
const int N = 405;
int dp[N][N], t[N], T, n;
int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1;i <= n; i++) read(t[i]);
		sort(t + 1, t + n + 1);
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1;i <= n + n; i++) {
			for (int j = n;j >= 0; j--) {
				Mn(dp[i][j], dp[i-1][j-1] + abs(i - t[j]));
				Mn(dp[i][j], dp[i-1][j]);
			}
		}
		write(dp[n+n][n]);
	}
	return 0;
}