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
#define maxn 500005
using namespace std;
const int mo = 998244353;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], b[maxn];
ll pre[maxn];
int check(int t) {
	ru(i, 1, n) b[i] = a[i] - (i + t > n);
	sort(b + 1, b + n + 1);
	ru(i, 1, n) pre[i] = b[i] + pre[i - 1];
	rd(i, n, 1) {
		ll sum = pre[n] - pre[i - 1];
		int loc = upper_bound(b + 1, b + n + 1, n - i + 1) - b;
		sum -= (ll)max(0, i - loc) * (n - i + 1);
		sum -= pre[min(i - 1, loc - 1)];
		sum -= (ll)(n - i + 1) * (n - i);
		if(sum > 0) return 0;
	}
	return 1;
}
int main() {
	n = read();
	ru(i, 1, n) a[i] = read(); a[n + 1] = 1;
	sort(a + 1, a + n + 1);
	ll L = 0;
	ru(i, 1, n) pre[i] = a[i] + pre[i - 1];
	rd(i, n, 1) {
		ll sum = pre[n] - pre[i - 1];
		int loc = upper_bound(a + 1, a + n + 1, n - i + 1) - a;
		sum -= (ll)max(0, i - loc) * (n - i + 1);
		sum -= pre[min(i - 1, loc - 1)];
		sum -= (ll)(n - i + 1) * (n - i);
		L = max(L, sum);
	}
	if((pre[n] ^ L) & 1) L++;
	if(L > n || a[n - L + 1] == 0 || !check(L)) {
		printf("-1\n");
		return 0;
	}
	ll l = L, r = n;
	r -= ((l ^ r) & 1);
	while(l < r) {
		int m = (l + r) >> 1;
		if((m ^ l) & 1) m++;
		if(check(m)) {
			l = m;
		}
		else r = m - 2;
//		printf("%d %d\n", l, r);
	}
	for (int i = L; i <= r; i += 2){
		printf("%d ", i);
	}
	return 0;
}