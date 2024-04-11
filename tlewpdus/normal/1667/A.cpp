#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll A[5010];

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%lld",&A[i]);
	}
	ll ans = LINF;
	for (int i=0;i<N;i++) {
		ll sum = 0;
		ll pre = 0;
		for (int j=i+1;j<N;j++) {
			ll v = pre/A[j]+1;
			sum += v;
			pre = v*A[j];
		}
		pre = 0;
		for (int j=i-1;j>=0;j--) {
			ll v = pre/A[j]+1;
			sum += v;
			pre = v*A[j];
		}
		ans = min(ans,sum);
	}
	printf("%lld\n",ans);

	return 0;
}