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

const int N = 2005, M = 100500;
int T, n, m, v[N][N], st[M], tp;
char s[N];
int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		for (int i = 1;i <= n; ++i) {
			scanf ("%s", s + 1);
			for (int j = 1;j <= n; ++j) 
				if (i != j) v[i][j] = s[j] == 'a';
		}
		bool fl = 0;
		for (int i = 1;i <= n && !fl; ++i) {
			for (int j = 1;j <= n && !fl; ++j)
				if (i != j && (v[i][j] == v[j][i] || (m & 1) || m < 2)) {
					puts("YES");
					for (int k = 1;k <= m + 1; ++k)
						write(k & 1 ? i : j, ' ');
					puts("");
					fl = 1;
				}
		}
		if (fl) continue;
		if (n <= 2) { puts("NO"); continue; }
		for (int i = 1;i <= n; ++i) {
			int t1 = -1, t2 = -1;
			for (int j = 1;j <= n; ++j) if (i != j) {
				if (t1 == -1) { t1 = j; continue; }
				if (v[i][j] != v[i][t1]) { t2 = j; break; }
			}
			if (t2 == -1) continue;
			tp = 0;
			st[++tp] = i;
			while (tp - 1 <= m / 2 + 20) 
				st[++tp] = t1, st[++tp] = i, st[++tp] = t2, st[++tp] = i;
			Mn(tp, m / 2 + 1);
			puts("YES");
			for (int i = m / 2 + 1;i >= 1; --i)
				write(st[i + 2], ' ');
			for (int i = 2;i <= m / 2 + 1; ++i) 
				write(st[i], ' ');
			puts("");
			break;
		}
	}
	return 0;
}

/*

1
3 2
*ab
b*a
ab*

*/