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
ll L[100100], R[100100], C[100100];

int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%lld%lld%lld",&L[i],&R[i],&C[i]);
		}
		ll mini = LINF, maxi = -1, lmin = LINF, rmin = LINF, lrmin = LINF;
		for (int i=0;i<N;i++) {
			if (L[i]<mini) lmin = C[i];
			else if (L[i]==mini) lmin = min(lmin,C[i]);
			if (R[i]>maxi) rmin = C[i];
			else if (R[i]==maxi) rmin = min(rmin,C[i]);
			if (L[i]<mini||R[i]>maxi) lrmin = LINF;
			if (L[i]<=mini&&R[i]>=maxi) lrmin = min(lrmin,C[i]);
			mini = min(mini,L[i]);
			maxi = max(maxi,R[i]);
			printf("%lld\n",min(lmin+rmin,lrmin));
		}
	}

	return 0;
}