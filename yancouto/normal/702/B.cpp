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
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int a[112345];

int main() {
	int i, n;
	scanf("%d", &n);
	map<int, int> mp;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	ll tot = 0;
	for(auto e : mp)
		if((e.fst & (e.fst - 1)) == 0)
			tot += (ll(e.snd) * ll(e.snd - 1)) / 2;
	for(i = 0; i < n; i++)
		for(ll j = 2; j <= 2000000000; j <<= 1) {
			if(j <= 2*a[i]) continue;
			ll x = j - a[i];
			tot += mp[x];
		}
	printf("%lld\n", tot);
}