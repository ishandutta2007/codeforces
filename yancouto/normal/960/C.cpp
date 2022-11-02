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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif
int n;

int main() {
	int i, j;
	ll x, d;
	scanf("%lld %lld", &x, &d);
	ll cur = 1;
	vector<ll> ans;
	for(i = 30; i >= 1; i--)
		while(x >= (1ll << i) - 1ll) {
			for(j = 0; j < i; j++) ans.pb(cur);
			cur += 1e9+1;
			x -= (1ll << i) - 1ll;
		}
	printf("%d\n", int(ans.size()));
	for(ll x : ans)
		printf("%lld ", x);
	putchar('\n');
}