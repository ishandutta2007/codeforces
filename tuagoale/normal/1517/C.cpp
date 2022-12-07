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

const int N = 1005;
int vis[N][N], cnt, p[N], n, nw;
void dfs(int x, int y) {
	if (!cnt) return;
	vis[x][y] = nw, --cnt;
	if (!vis[x][y - 1]) dfs(x, y - 1);
	if (!vis[x - 1][y]) dfs(x - 1, y);
}

int main() {
	read(n);
	for (int i = 1;i <= n; ++i) read(p[i]);
	for (int i = 0;i <= n; ++i) vis[0][i] = vis[i][0] = 1;
	for (int i = n;i >= 1; --i) 
		cnt = p[i], nw = p[i], dfs(i, n - i + 1);
	for (int i = 1;i <= n; ++i, puts(""))
		for (int j = 1;j <= i; ++j)
			write(vis[j][n - i + 1], ' ');
	return 0;
}