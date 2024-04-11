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
vector<pair<int, int> > vec[N * 30];
int a[N], b[N], n;
int main() {
	read(n);
	for (int i = 1;i <= n; ++i) read(a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1);
	for (int i = 1;i <= n; ++i) {
		if (b[i] == b[i + 3]) {
			int cnt = 0;
			puts("YES");
			for (int j = 1;cnt < 4 && j <= n; ++j)
				if (a[j] == b[i]) write(j, ' '), ++cnt;
			return 0; 
		}
	}
	for (int i = 1;i <= n; ++i) {
		for (int j = i + 1;j <= n; ++j) {
			int t = a[i] + a[j];
			vec[a[i] + a[j]].push_back(MP(i, j));
			for (int k = 0;k < vec[t].size(); ++k) {
				for (int kk = 0;kk < vec[t].size(); ++kk) if (kk != k) {
					int a = vec[t][kk].fi, b = vec[t][kk].se;
					if (a != i && a != j && b != i && b != j) {
						puts("YES");
						write(i, ' '), write(j, ' '), write(a, ' '), write(b);
						return 0;
					}
				}
			}
		}
	}
	puts("NO");
	return 0;
}