#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
ll best = LLONG_MAX;

int ac[10], p[10];
int a[200][10];

bool ok(ll e) {
	//bool deb = ::p[0] == 0 && ::p[1] == 2 && ::p[2] == 1 && ::p[3] == 2 && ::p[4] == 5 && e == 3;
	for(int i = 0; i < 5; i++) {
		ll mnk = 0, mxk = e;
		ll x = ac[i], y = n;
		if(p[i] != 5) {
			ll q = (1 << (p[i] + 1));
			if(y + e - x * q >= 0)
				mnk = max(mnk, (y + e - x * q) / q + 1ll);
			//if(deb) printf("%d + %d - %d * %d / %d + 1\n", y, e, x, q, q);
		}
		if(p[i] != 0) {
			ll q = (1 << p[i]);
			if(y + e - x * q >= 0)
				mxk = min(mxk, (y + e - x * q) / q);
			else mxk = -1;
			//if(deb) printf("%d + %d - %d * %d / %d + 1\n", y, e, x, q, q);
		}
		//if(deb) printf("[%d]: %d <= k <= %d\n", i, mnk, mxk);
		if(mnk > mxk) return false;
		if(mnk != 0 && a[0][i] == -1) return false;
	}
	return true;
}

bool win() {
	ll v = 0, p = 0;
	for(int i = 0; i < 5; i++) {
		if(a[0][i] != -1) v += (::p[i] + 1) * 500 * (250 - a[0][i]);
		if(a[1][i] != -1) p += (::p[i] + 1) * 500 * (250 - a[1][i]);
	}
	return v > p;
}

ll solve() {
	if(!win()) return LLONG_MAX;
	for(int x = 0; x < 300; x++)
		if(ok(x)) return x;
	if(!ok(modn)) return LLONG_MAX;
	int l = 300, r = modn;
	while(l < r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m + 1;
	}
	return l;
	//return LLONG_MAX;
}

void go(int i) {
	//bool deb = ::p[0] == 0 && ::p[1] == 2 && ::p[2] == 1 && ::p[3] == 2 && ::p[4] == 5;
	//if(i == 5 && win()) {
	//	//if(p[0] != 3 || p[1] || p[2] || p[3] || p[4]) return;
	//	ll x = solve();
	//	for(int i = 0; i < 5; i++) printf("%d ", p[i]);
	//	printf("= %lld\n", x);
	//}
	if(i == 5){ best = min(best, solve()); return; }
	for(int j = 0; j < 6; j++) {
		p[i] = j;
		go(i + 1);
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
			ac[j] += (a[i][j] != -1);
		}
	go(0);
	if(best > modn) puts("-1");
	else printf("%lld\n", best);
}