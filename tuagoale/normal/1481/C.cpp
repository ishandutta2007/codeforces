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

const int N = 200050;
int T, m, n;
vector<int> vec[N];
int a[N], b[N], c[N], cnt[N], ans[N];
int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		for (int i = 1;i <= n; ++i) read(a[i]);
		for (int i = 1;i <= n; ++i) {
			read(b[i]);
			if (a[i] != b[i]) {
				cnt[b[i]]++;
				vec[b[i]].push_back(i);
			}
		}
		for (int i = 1;i <= m; ++i) read(c[i]);
		int t = 0;
		for (int i = 1;i <= n; ++i) {
			if (c[m] == b[i]) {
				if (!t) t = i;
				if (c[m] != a[i]) t = i;
			}
		}
		if (!t) { 
			puts("NO"); 
			for (int i = 1;i <= n; ++i) {
				cnt[i] = 0;
				vec[i].clear();
			}
			continue; 
		}
		ans[m] = t;
		if (a[t] != b[t]) {
			vec[b[t]].pop_back();
			cnt[b[t]]--;
		}
		for (int i = 1;i < m; ++i) {
			cnt[c[i]]--;
			if (vec[c[i]].size()) ans[i] = vec[c[i]].back(), vec[c[i]].pop_back();
			else ans[i] = t;
		}
		int fl = 0;
		for (int i = 1;i <= n; ++i) {
			if (cnt[i] > 0) fl = 1;
			cnt[i] = 0;
			vec[i].clear();
		}
		if (fl) puts("NO");
		else {
			puts("YES");
			for (int i = 1;i <= m; ++i)
				write(ans[i], ' ');
			puts("");
		}
	}
	return 0;
}

/*

6
1 1
1
1
1
5 2
1 2 2 1 1
1 2 2 1 1
1 2
3 3
2 2 2
2 2 2
2 3 2
10 5
7 3 2 1 7 9 4 2 7 9
9 9 2 1 4 9 4 2 3 9
9 9 7 4 3
5 2
1 2 2 1 1
1 2 2 1 1
3 3
6 4
3 4 2 4 1 2
2 3 1 3 1 1
2 2 3 4


*/