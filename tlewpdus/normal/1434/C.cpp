#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

ll a, b, c, d;

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a>b*c) {
			puts("-1");
			continue;
		}
		ll k = a/(b*d);
		printf("%lld\n",(k+1)*a-k*(k+1)/2*b*d);
	}

	return 0;
}