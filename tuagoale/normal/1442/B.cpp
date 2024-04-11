
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

const int N = 200050;
const int P = 998244353;
int rev[N], a[N], b[N], turn[N], n, k, T;
int main() {
//	freopen ("hs.in","r",stdin);
	for (read(T); T; T--) {
		read(n), read(k);
		for (int i = 1;i <= n; i++) read(a[i]), turn[i] = 0, rev[a[i]] = i;
		for (int i = 1;i <= k; i++) read(b[i]), turn[b[i]] = i;
		int tmp = 1; turn[0] = n + 1; a[n + 1] = 0;
		for (int i = 1;i <= k; i++) {
			int x = rev[b[i]];
			int t = (turn[a[x-1]] > i) + (turn[a[x+1]] > i);
			if (t == 0) tmp = tmp + tmp, tmp >= P && (tmp -= P);
			if (t == 2) tmp = 0;
		}
		write(tmp);
	}
	return 0;
}