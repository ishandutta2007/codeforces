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

const int N = 500500;
int a[N], T[N], pre[N], st[N], ed[N], dp[N], cnt[N], n;
int main() {
	read(n);
	for (int i = 1;i <= n; ++i) {
		read(a[i]), ed[a[i]] = i, pre[i] = T[a[i]];
		if (!st[a[i]]) st[a[i]] = i;
		T[a[i]] = i, cnt[a[i]]++;
	}
	int ans = 0;
	for (int i = 1;i <= n; ++i) {
		Mx(dp[i], dp[i-1]);
		if (ed[a[i]] != i) continue;
		int x = i, t = 1;
		Mx(dp[i], dp[st[a[i]] - 1] + cnt[a[i]]);
		
		while (x) Mx(ans, dp[x-1] + t), ++t, x = pre[x];
	}
	write(n - ans);
	return 0;
}