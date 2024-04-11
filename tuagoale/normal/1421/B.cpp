
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

const int N = 405;
int bit[N][N], T, n;
int dx[6], dy[6], vis[N][N];

bool in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y];
}

void work(int x, int y, int fl) {
	vis[x][y] = 1;
	if (in(x + 1, y) && bit[x][y] != !fl) work(x + 1, y, fl);
	if (in(x - 1, y) && bit[x][y] != !fl) work(x - 1, y, fl);
	if (in(x, y - 1) && bit[x][y] != !fl) work(x, y - 1, fl);
	if (in(x, y + 1) && bit[x][y] != !fl) work(x, y + 1, fl);
}

bool work(void) {
	memset(vis, 0, sizeof(vis));
	work(1, 1, 0);
	if (vis[n][n]) return 1;
	memset(vis, 0, sizeof(vis));
	work(1, 1, 1);
	if (vis[n][n]) return 1;
	return 0;
}

char s[N];
int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 1;i <= n; i++) {
			scanf ("%s", s + 1);
			for (int j = 1;j <= n; j++) bit[i][j] = s[j] - '0';
		}
		bit[n][n] = 2;
		dx[1] = 1, dx[2] = 2, dy[1] = 2, dy[2] = 1;
		dx[3] = n, dx[4] = n - 1, dy[3] = n - 1, dy[4] = n;
		for (int i = 0;i <= 15; i++) {
			int cnt = 0;
			for (int j = 1;j <= 4; j++)
				if ((i >> (j - 1)) & 1) cnt++, bit[dx[j]][dy[j]] ^= 1;
			if (cnt <= 2 && !work()) {
				write(cnt);
				for (int j = 1;j <= 4; j++)
					if ((i >> (j - 1)) & 1) {
						write(dx[j], ' '), write(dy[j]);
					}
				break;
			}
			for (int j = 1;j <= 4; j++)
				if ((i >> (j - 1)) & 1) cnt++, bit[dx[j]][dy[j]] ^= 1;
		}
	}
	return 0;
}