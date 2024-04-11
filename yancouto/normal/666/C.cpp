#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINEJUDGE
#	define LLD "%I64d"
#	define debug(...) fprintf(stderr, ...)
#else
#	define LLD "%lld"
#	define debug(...) {}
#endif
const int N = 112345;

char s[N];
ll p25[N], p26[N], fat[N], ifa[N];
int n;

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

ll solve2(int n, int m) {
	if(n < 0 || m < 0 || n > m) return 0;
	return mod(mod(fat[m] * ifa[n]) * ifa[m - n]);
}

ll maybe(int n, int m) {
	ll tot = 0;
	for(int i = n; i <= m; i++)
		tot += mod(mod(solve2(n - 1, i - 1) * p25[i - n]) * p26[m - i]);
	return tot;
}

int p[N], pn, ans[N];
vector<pii> qs;
int main() {
	int i, j, n, m, op, q;
	p25[0] = p26[0] = 1, fat[0] = 1, ifa[0] = 1;
	for(i = 1; i < N; i++) {
		p25[i] = mod(p25[i - 1] * 25ll);
		p26[i] = mod(p26[i - 1] * 26ll);
		fat[i] = mod(fat[i - 1] * ll(i));
		ifa[i] = fexp(fat[i], modn - 2);
	}
	scanf("%d", &q);
	scanf("%s", s);
	n = strlen(s);
	for(i = 0; i < q; i++) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%s", s);
			n = strlen(s);
		} else {
			scanf("%d", &m);
			qs.pb(pii(n, m));
			p[pn] = pn;
			pn++;
		}
	}
	sort(p, p + pn, [](int i, int j) { return qs[i] < qs[j]; });
	ll cur = 0;
	int r;
	for(i = 0; i < qs.size(); i++) {
		if(!i || qs[p[i - 1]].fst != qs[p[i]].fst)
			r = 0, cur = 0, n = qs[p[i]].fst;
		while(r < qs[p[i]].snd) {
			r++;
			cur = mod(26ll * cur + solve2(n - 1, r - 1) * p25[r - n]);
		}
		ans[p[i]] = cur;
	}
	for(i = 0; i < qs.size(); i++)
		printf("%d\n", ans[i]);
}