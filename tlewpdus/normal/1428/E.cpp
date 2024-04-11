#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007; //998244353

int N, K;
ll A[100100];

ll cost(ll L, ll K) {
	if (L<K) return K;
	ll T = L/K;
	return T*T*(K-L%K)+(T+1)*(T+1)*(L%K);
}

ll tot = 0;
ll cur[100100];

int main() {
	priority_queue<pll> pq;
	scanf("%d%d",&N,&K);
	for (int i=0;i<N;i++) {
		scanf("%lld",&A[i]);
		tot += A[i]*A[i];
		pq.push({cost(A[i],1)-cost(A[i],2),i});
		cur[i] = 1;
	}
	for (int i=0;i<K-N;i++) {
		pll tmp = pq.top(); pq.pop();
		tot -= tmp.first;
		cur[tmp.second]++;
		pq.push({cost(A[tmp.second],cur[tmp.second])-cost(A[tmp.second],cur[tmp.second]+1),tmp.second});
	}
	printf("%lld\n",tot);

	return 0;
}