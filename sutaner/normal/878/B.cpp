#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 200019
#define maxr 100000
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, k, m;
int a[maxn];
pii sta[maxn];
int cnt = 0;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("878B.in", "r", stdin);
	#endif
	read(n), read(k), read(m);
	ll ans = (ll)n * m;
	rep(i, 1, n) read(a[i]);
	rep(i, 1, n){
		if (!cnt || sta[cnt].fi != a[i]) sta[++cnt] = pii(a[i], 1);
		else {
			sta[cnt].se++;
			if (sta[cnt].se == k) ans -= (ll)m * k, cnt--;
		}
	}
	int l = 1, r = cnt;
	while (l < r){
		if (sta[l].fi != sta[r].fi) break; 
		else if ((sta[l].se + sta[r].se) % k != 0){
			ans -= (ll)(m - 1) * ((sta[l].se + sta[r].se) / k * k);
			break;
		}
		else {
			ans -= (ll)(m - 1) * ((sta[l].se + sta[r].se) / k * k);
			l++, r--;
		}
	}
	if (l == r) {
		if ((ll)sta[l].se * m % k == 0) ans = 0; 
		else ans -= (ll)m * sta[l].se / k * k;
	}
	printf("%lld", ans);
	/*ll ans = (ll)n * m;
	rep(i, 1, n) read(a[i]);
	ll red = 0; int pre = 0, suf = 0;
	rep(i, 1, n){
		int now = a[i], _i = i;
		while (i <= n && a[i] == now) i++;
		if (_i == 1) pre = i - _i;
		if (i == n + 1) suf = i - _i;
		if (_i != 1 && i != n + 1) red += (i - _i) / k * k; 
		i--;
	}
	if (pre == n) {
		red = (ll)n * m / k * k;
	}
	else {
		if (a[1] == a[n]) red = red * m + pre / k * k + suf / k * k + (ll)(m - 1) * ((pre + suf) / k * k);
		else red = (ll)(red + pre / k * k + suf / k * k) * m;
	}
	printf("%lld", ans - red);*/
	return 0;
}