#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll D[1000100];

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

ll half = (MOD+1)/2;
ll sixi = ipow(6,MOD-2);
ll H(ll n, ll r) {
	if (r==2) {
		return n*(n+1)%MOD*half%MOD;
	}
	else if (r==3) {
		return n*(n+1)%MOD*(n+2)%MOD*sixi%MOD;
	}
	return n;
}

int main () {
	scanf("%d",&N);
	D[0] = 0;
	for (int i=1;i<=N+1;i++) {
		D[i] = (D[i-1]+1)*(D[i-1]+2)%MOD*half%MOD;
	}
	ll ans = 0;
	if (N==1) {
		puts("5");
		return 0;
	}
	for (int i=0;i<=N;i++) {
		ll add = 0;
		if (i==0) {
			add = (H(D[N]+1,3)-H(D[N-1]+1,3)-(D[N]-D[N-1]))%MOD;
		}
		else if (i==N) {
			add = (H(D[N]+1,3)-H(D[N-1]+1,3))%MOD;
		}
		else {
			ll t = (H(D[N-i]+1,2)-H(D[N-i-1]+1,2)-(D[N-i]-D[N-i-1]))%MOD;
			ll s = (D[i]-D[i-1])%MOD;
			add = t*s%MOD;
		}
//		printf("%d : %lld\n",i,add);
		ans += add;
	}
//	ans--;
	printf("%lld\n",((ans%MOD+MOD)%MOD));

	return 0;
}