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

ll calc(ll t) {
	ll ans = A[0]*A[N-1]+t*(A[0]+A[N-1]);
	for (int i=1;i<N-1;i++) {
		ans += min(A[0]*A[i]+t*(A[0]+A[i]),A[i]*A[N-1]+t*(A[i]+A[N-1]));
	}
	return ans;
}

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%lld",&A[i]);
		sort(A,A+N);
		ll sum = 0;
		for (int i=0;i<N;i++) sum += A[i];
		if ((N-2)*A[0]+sum>0 || (N-2)*A[N-1]+sum<0) {
			puts("INF");
			continue;
		}
		ll s = -5e6, e = 5e6;
		while(s<=e) {
			ll m = (s+e)/2;
			if (calc(m)<calc(m+1)) s = m+1;
			else e = m-1;
		}
		printf("%lld\n",calc(s));
	}

	return 0;
}