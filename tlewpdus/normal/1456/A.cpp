#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int N, P, K;
ll X, Y;
int A[100100];
int B[100100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d%d",&N,&P,&K);
		for (int i=0;i<N;i++) {
			char c;
			scanf(" %c",&c);
			A[i] = c-'0';
		}
		scanf("%lld%lld",&X,&Y);
		P--;
		for (int i=N-1;i>=0;i--) {
			B[i] = (i+K<N?B[i+K]:0)+(1-A[i]);
		}
		ll ans = LINF;
		for (int i=N-1;i>=P;i--) {
			ans = min(ans,B[i]*X+Y*(i-P));
		}
		printf("%lld\n",ans);
	}

	return 0;
}