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

const int N = 200500;
int a[N], cnt[N], m, n, T;
int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		memset(cnt, 0, m * 4 + 20);
		for (int i = 1;i <= n; ++i) read(a[i]), cnt[a[i] % m] ++;
		int ans = n;
		if (cnt[0]) ans -= cnt[0] - 1;
		if (m % 2 == 0 && cnt[m / 2]) ans -= cnt[m / 2] - 1;
		for (int i = 1;i * 2 < m; ++i) {
			if (cnt[i] == cnt[m - i] && cnt[i]) ans -= cnt[i] * 2 - 1;
			else if (cnt[i]) ans -= 2 * min(cnt[i], cnt[m - i]);
		}
		write(ans);
	}
	return 0;
}

/*

1
2 2
2 4


*/