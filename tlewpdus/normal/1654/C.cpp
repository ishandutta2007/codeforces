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
ll A[200100];

bool test(ll X) {
	priority_queue<ll> pq;
	pq.push(X);
	int idx = N-1;
	while(!pq.empty() && idx>=0 && pq.size() <= N) {
		ll x = pq.top(); pq.pop();
//		printf("%lld!\n",x);
		if (A[idx]==x) {
			idx--;
			continue;
		}
		if (x>1) {
			pq.push(x / 2);
			pq.push((x + 1) / 2);
		}
	}
	return idx<0;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		ll sum = 0;
		for (int i=0;i<N;i++) {
			scanf("%lld",&A[i]);
			sum += A[i];
		}
		sort(A,A+N);
		if (test(sum)) puts("YES");
		else puts("NO");
	}

	return 0;
}