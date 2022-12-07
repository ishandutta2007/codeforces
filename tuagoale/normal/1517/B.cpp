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

const int N = 205;
struct node {
	int v, x, y;
	bool operator < (const node &i) const {
		return v < i.v;
	}
}c[N * N];
int vis[N][N], st[N], m, n;
int b[N][N], cnt, T;
int main() {
	for (read(T); T; T--) {
		read(n), read(m), memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (int i = 1;i <= n; ++i) {
			for (int j = 1;j <= m; ++j)
				read(b[i][j]), c[++cnt] = (node){b[i][j], i, j};
		}
		sort(c + 1, c + cnt + 1);
		for (int i = 1;i <= m; ++i) 
			vis[c[i].x][c[i].y] = i;
		for (int i = 1;i <= n; ++i) {
			memset(st, 0, sizeof(st));
			for (int j = 1;j <= m; ++j)
				if (vis[i][j]) st[vis[i][j]] = b[i][j];
			int nw = 1;
			for (int j = 1;j <= m; ++j) {
				if (st[j]) write(st[j], ' '); 
				else {
					while (vis[i][nw]) ++nw;
					write(b[i][nw], ' '), ++nw;
				}
			}
			puts("");
		}
	}
	return 0;
}