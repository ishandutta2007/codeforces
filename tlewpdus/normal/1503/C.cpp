#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

int N;
pll A[100100];

int main() {
	scanf("%d",&N);
	ll sco = 0;
	for (int i=0;i<N;i++) {
		scanf("%lld%lld",&A[i].first,&A[i].second);
		sco += A[i].second;
	}
	sort(A,A+N);
	int i=0, j = 1;
	while (i<N) {
		ll T = A[i].first+A[i].second;
		int rj = j;
		while(j<N&&A[j].first<=T) j++;
		if (j==N) break;
		int mj = j;
		ll mt = T;
		for (int k=rj;k<j;k++) {
			if (mt<A[k].first+A[k].second) {
				mt=A[k].first+A[k].second;
				mj = k;
			}
		}
		if (mj==j) sco += A[j].first-T;
		i = mj;
	}
	printf("%lld\n",sco);

	return 0;
}