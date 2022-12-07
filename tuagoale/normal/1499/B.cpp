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
int pr[N], af[N], T, n;
char s[N];
int main() {
	for (read(T); T; T--) {
		scanf ("%s", s + 1), n = strlen(s + 1);
		pr[0] = af[n + 1] = 1, s[n + 1] = 0;
		for (int i = 1;i <= n; ++i) 
			if (s[i] == '1') pr[i] = s[i] != s[i - 1] && pr[i - 1];
			else pr[i] = pr[i-1];
		for (int i = n;i >= 1; --i)
			if (s[i] == '0') af[i] = s[i] != s[i + 1] && af[i + 1];
			else af[i] = af[i + 1];
		int fl = 0;
		for (int i = 0;i <= n; ++i)
			if (pr[i] && af[i + 1]) fl = 1;
		puts(fl ? "YES" : "NO");
	}
	return 0;
}