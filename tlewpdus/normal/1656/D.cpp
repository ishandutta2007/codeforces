#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

ll N;
int A[100100];
const ll MM = 2e9;

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%lld",&N);
		ll t = 1;
		ll K = N;
		while(K%2==0) {
			K/=2;
			t*=2;
		}
		t*=2;
		if (t<MM&&t*(t+1)/2<=N) {
			printf("%lld\n",t);
			continue;
		}
		if (K>1) {
			printf("%lld\n",K);
		}
		else puts("-1");
	}

	return 0;
}