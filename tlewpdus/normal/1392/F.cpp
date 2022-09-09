#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;
ll H[1000100];
ll ans[1000100];

int main() {
	scanf("%d",&n);
	ll sum = 0;
	for (int i=0;i<n;i++) scanf("%lld",&H[i]), sum += H[i];
	ll s = 0, e = (sum+n-1)/n;
	while(s<=e) {
		ll m = (s+e)/2;
		if (n*(2*m+n-1)/2 <= sum) s = m+1;
		else e = m-1;
	}
	iota(ans,ans+n,e);
	ll ts = 0;
	for (int i=0;i<n;i++) ts += ans[i];
	for (int i=0;i<sum-ts;i++) ans[i]++;
	for (int i=0;i<n;i++) printf("%lld ",ans[i]);puts("");

	return 0;
}