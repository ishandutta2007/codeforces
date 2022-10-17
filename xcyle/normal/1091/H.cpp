/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define N 200000
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, vis[N + 10], prime[N + 10], cnt;
int a[N + 10], tot;
int SG[N + 10];
bitset<N + 10> bas, val[105];
void init() {
	vis[1] = 1;
	ru(i, 2, N) if(!vis[i]) {
		prime[++cnt] = i;
		ru(j, 2, N / i) vis[i * j] = 1;
	}
	ru(i, 1, cnt) {
		ru(j, i, cnt) {
			if((ll)prime[i] * prime[j] > N) break;
			vis[prime[i] * prime[j]] = 0;
		}
	}
	vis[read()] = 1;
	ru(i, 1, N) if(!vis[i]) bas[i] = 1;
	ru(i, 0, N) {
		while(val[SG[i]][i]) SG[i]++;
		val[SG[i]] |= (bas << i);
	}
}
int main() {
	n = read();
	init();
	int res = 0;
	ru(i, 1, n) {
		int a = read(), b = read(), c = read();
		res ^= SG[b - a - 1] ^ SG[c - b - 1];
	}
	if(res) printf("Alice\nBob");
	else printf("Bob\nAlice\n");
	return 0;
}