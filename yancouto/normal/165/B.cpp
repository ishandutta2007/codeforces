#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int k;

ll go(ll v) {
	ll sum = 0;
	while(v > 0) {
		sum += v;
		v /= k;
	}
	return sum;
}

int main() {
	int n;
	scanf("%d %d", &n, &k);
	ll l = 1, r = 1e15;
	while(l < r) {
		ll m = (l + r) / 2;
		if(go(m) >= n) r = m;
		else l = m + 1;
	}
	printf("%lld\n", l);
}