#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
const int N = 312345;
ll t[N], w[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%lld %lld", &t[i], &w[i]);
	int cur = 1;
	multiset<ll> kill;
	multiset<pll> ot;
	for(i = 1; i < n; i++)
		if(t[i] > t[0]) {
			cur++;
			kill.insert(w[i] - t[i] + 1ll);
		} else ot.insert(pll(t[i], w[i]));
	kill.insert(1.5e18);
	ot.insert(pll(-1.5e18, -1));
	int best = cur;
	while(t[0] > 0) {
		ll nxkill = *kill.begin();
		ll nxrise = t[0] - ot.rbegin()->fst + 1;
		if(nxkill > t[0]) break;
		if(nxkill <= nxrise) {
			t[0] -= nxkill;
			cur--;
			kill.erase(kill.begin());
			assert(!kill.empty());
		} else {
			t[0] -= nxrise;
			kill.erase(kill.begin());
			kill.insert(nxkill - nxrise);
		}
		while(ot.rbegin()->fst > t[0]) {
			cur++;
			pll p = *ot.rbegin();
			ot.erase(ot.find(p));
			kill.insert(p.snd - p.fst + 1ll);
		}
		best = min(best, cur);
	}
	printf("%d\n", best);
}