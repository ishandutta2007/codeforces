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
#define maxn 100005
using namespace std;
const int mo = 998244353;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
ll l[maxn];
char s[maxn];
int main() {
	n = read();
	ru(i, 1, n) scanf("%lld", &l[i]);
	scanf("%s", s + 1);
	ll sum = 0, need = 0;
	ll hav1 = 0, hav2 = 0;
	ru(i, 1, n) {
		hav1 |= s[i] == 'W';
		if(s[i] == 'G') hav2 += 2 * l[i];
		
		if(s[i] == 'W') sum += l[i], need += 3 * l[i];
		else sum -= l[i], need += l[i];
		if(sum < 0) {
			ll t = min(hav2, -sum);
			hav2 -= t, sum += t, need += 2 * t;
			
			need += (5 - 2 * hav1) * (-sum), sum = 0;
		}
	}
	printf("%lld\n", need - sum);
	return 0;
}