
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

const int N = 300005;
int a[N], b[N], c[N], n, T;
int main() {
	for (read(T); T; T--) {
		read(n); int lef = 1e9, rig = 0;
		int fl = 0;
		for (int i = 1;i <= n; i++) {
			read(a[i]);
			if (a[i] < rig) fl = 1;
			a[i] -= rig;
			if (a[i] <= lef) lef = a[i];
			else {
				a[i] -= lef;
				rig += a[i];
			}
		}
		puts(!fl ? "YES" : "NO");
	}
	return 0;
}

/*

1
5
1 3 1 3 1


*/