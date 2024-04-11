#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;

int main() {
	int TT;

	scanf("%d",&TT);
	while(TT--) {
		scanf("%d%d",&N,&M);
		vector<ll> sums;
		ll mini = LINF, maxi = 0;
		int loc = 0;
		for (int i=0;i<N;i++) {
			ll sum = 0;
			for (int j=0;j<M;j++) {
				ll a;
				scanf("%lld",&a);
				sum += a*(M-j);
			}
			maxi = max(maxi, sum);
			if (mini>sum) {
				mini=sum;
				loc=i;
			}
		}

		printf("%d %lld\n",loc+1, maxi-mini);
	}

	return 0;
}