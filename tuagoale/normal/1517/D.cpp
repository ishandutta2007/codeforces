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

const int N = 505;
const ll inf = 1e18;
int m, n, k;
int L[N][N], D[N][N]; ll dis[23][N][N];
int main() {
	read(n), read(m), read(k);
	for (int i = 1;i <= n; ++i) 
		for (int j = 1;j < m; ++j)
			read(L[i][j]);
	for (int i = 1;i < n; ++i)
		for (int j = 1;j <= m; ++j)
			read(D[i][j]);
	memset(dis, 0x3f, sizeof(dis));
	memset(dis[0], 0, sizeof(dis[0]));
	for (int i = 0;i < k; i += 2) {
		for (int x = 1;x <= n; ++x)
			for (int y = 1;y <= m; ++y) {
				if (x < n) {
					Mn(dis[i + 2][x][y], dis[i][x + 1][y] + D[x][y] * 2);
					Mn(dis[i + 2][x + 1][y], dis[i][x][y] + D[x][y] * 2);
				}
				if (y < m) {
					Mn(dis[i + 2][x][y], dis[i][x][y + 1] + L[x][y] * 2);
					Mn(dis[i + 2][x][y + 1], dis[i][x][y] + L[x][y] * 2); 
				}
			}
	}
	for (int i = 1;i <= n; ++i, puts(""))
		for (int j = 1;j <= m; ++j)
			write(dis[k][i][j] < inf ? dis[k][i][j] : -1, ' ');
	return 0;
}