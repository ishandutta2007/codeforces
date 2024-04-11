
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

ll T, x, y;
ll c[22];
int main() {
	for (read(T); T; T--) {
		read(x), read(y);
		for (int i = 1;i <= 6; i++) read(c[i]);
		for (int i = 1;i <= 10; i++) {
			Mn(c[2], c[1] + c[3]), Mn(c[1], c[6] + c[2]);
			Mn(c[6], c[5] + c[1]), Mn(c[4], c[3] + c[5]);
			Mn(c[3], c[4] + c[2]), Mn(c[5], c[6] + c[4]);
		}
		if (x <= 0 && y >= 0) {
			write(-x * c[3] + y * c[2]);
			continue;
		}
		if (x <= 0 && y <= 0) {
			x = -x, y = -y;
			ll t = min(x, y);
			if (x > y) write(t * c[4] + (x - t) * c[3]);
			else write(t * c[4] + (y - t) * c[5]);
			continue;
		}
		if (x >= 0 && y <= 0) {
			write(x * c[6] - y * c[5]);
			continue;
		}
		ll t = min(x, y);
		if (x > y) write(t * c[1] + (x - t) * c[6]);
		else write(t * c[1] + (y - t) * c[2]);
	}
	return 0;
}