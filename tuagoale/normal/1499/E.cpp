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

const int P = 998244353;
const int N = 1005;
ll f[N][N][2][2], ans; 
char a[N], b[N];
int m, n;
int main() {
	scanf ("%s", a + 1), scanf ("%s", b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	auto Add = [&](ll &x, ll y) { x = (x + y) % P; };
	for (int i = 1;i <= n + 1; ++i) {
		for (int j = 1;j <= m + 1; ++j) {
			f[i + 1][j][0][0]++;
			f[i][j + 1][0][1]++;
			if (a[i] != a[i - 1]) 
				Add(f[i + 1][j][0][0], f[i][j][0][0]), Add(f[i + 1][j][1][0], f[i][j][1][0]);
			if (a[i] != b[j - 1])
				Add(f[i + 1][j][1][0], (f[i][j][0][1] + f[i][j][1][1]));
			if (b[j] != b[j-1]) 
				Add(f[i][j + 1][0][1], f[i][j][0][1]), Add(f[i][j + 1][1][1], f[i][j][1][1]);
			if (b[j] != a[i-1]) 
				Add(f[i][j + 1][1][1], (f[i][j][0][0] + f[i][j][1][0]));
			ans += f[i][j][1][0] + f[i][j][1][1];
		}
	}
	write(ans % P);
	return 0;
}