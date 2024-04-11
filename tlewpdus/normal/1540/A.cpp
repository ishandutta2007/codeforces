#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N;
ll D[100100];

int main () {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%lld",&D[i]);
		sort(D,D+N);
		ll S = 0;
		ll ans = 0;
		for (int i=1;i<N;i++) {
			ans += D[i]*(i-1)-S;
			S += D[i-1];
		}
		printf("%lld\n",-ans);
	}

	return 0;
}