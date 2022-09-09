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
	for (int i=1;i<=N;i++) {
		base += T[i-1]+X;
		for (ll j=0;j<min(max(base,0LL),CS[i]+1);j++) D[i][j] = 0;
		for (ll j=max(base,0LL);j<=CS[i];j++) {
			D[i][j] = ((j>CS[i-1]?D[i-1][CS[i-1]]:D[i-1][j])-(j>=C[i]+1?D[i-1][j-C[i]-1]:0)+MOD)%MOD;
		}
		for (ll j=1;j<=CS[i];j++) D[i][j] = (D[i][j-1]+D[i][j])%MOD;
	}
	return (D[N][CS[N]]%MOD+MOD)%MOD;
}

ll TQ[150];
int main () {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%lld",&C[i]);
	for (int i=1;i<=N;i++) CS[i] = CS[i-1]+C[i];
	for (int i=1;i<=N-1;i++) scanf("%lld",&B[i]);
	for (int i=1;i<=N-1;i++) T[i] = T[i-1]+B[i];
	scanf("%d",&Q);
	for (int i=0;i<Q;i++) scanf("%lld",&X[i]);
	ll Xmin = LINF;
	ll TS = 0;
	for (int i=0;i<N;i++) {
		TS += T[i];
		Xmin = min(Xmin, -TS/(i+1)-1);
	}
	Xmin-=3;
	for (int i=0;i<120;i++) TQ[i] = solve(Xmin+i);
	for (int i=0;i<Q;i++) {
		if (X[i]<Xmin) printf("%lld\n",TQ[0]);
		else if (X[i]<Xmin+115) printf("%lld\n",TQ[X[i]-Xmin]);
		else printf("0\n");
	}

	return 0;
}