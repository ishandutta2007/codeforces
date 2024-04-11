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
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
char s[205];
int buc[30];
void solve() {
	n = read(), k = read();
	scanf("%s", s + 1);
	ru(i, 0, 25) buc[i] = 0;
	ru(i, 1, n) buc[s[i] - 'a']++;
	ru(i, 1, k) {
		ru(j, 0, max(n / k, 25)) {
			if(!buc[j] || j == n / k) {
				printf("%c", 'a' + j);
				break;
			}
			else buc[j]--;
		}
	}
	printf("\n");
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}