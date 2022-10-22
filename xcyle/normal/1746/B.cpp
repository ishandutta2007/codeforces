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
#define maxn 1000005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn];
void solve() {
	n = read();
	int cnt[2] = {0, 0};
	ru(i, 1, n){
		 a[i] = read();
		 if(a[i] == 0) cnt[0]++;
	}
	if(cnt[0] == cnt[1]) {
		printf("%d\n", cnt[0]);
		return;
	}
	ru(i, 1, n) {
		if(a[i] == 0) cnt[0]--;
		else cnt[1]++;
		if(cnt[0] == cnt[1]) {
			printf("%d\n", cnt[0]);
			return;
		}
	}
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}