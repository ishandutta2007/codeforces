#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N, Q;
ll C[110], CS[110];
ll B[110];
ll T[110];
ll X[100100];
ll D[110][10100];

ll solve(ll X) {
	memset(D,0,sizeof(D));
	D[0][0] = 1;
	ll base = 0;
	for (int i=0;i<N;i++) {
		for (ll j=max(-base, 0LL);j<=CS[i];j++) {
			for (int k=0;k<=C[i+1];k++) {
				D[i+1][j+k] = (D[i+1][j+k]+D[i][j])%MOD;
			}
		}
		base -= T[i]+X;
	}
	ll ans = 0;
	for (ll j=max(-base,0LL);j<=CS[N];j++) ans = (ans+D[N][j])%MOD;
	return ans;
}

int main () {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%lld",&C[i]);
	for (int i=1;i<=N;i++) CS[i] = CS[i-1]+C[i];
	for (int i=1;i<=N-1;i++) scanf("%lld",&B[i]);
	for (int i=1;i<=N-1;i++) T[i] = T[i-1]+B[i];
	scanf("%d",&Q);
	for (int i=0;i<Q;i++) scanf("%lld",&X[i]);
	for (int i=0;i<Q;i++) {
		printf("%lld\n",solve(X[i]));
	}

	return 0;
}