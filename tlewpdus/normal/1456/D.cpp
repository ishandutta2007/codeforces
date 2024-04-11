#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int N;
int D[5010], E[5010];
ll T[5010], X[5010], ET[5010];

ll poss(int s, int e, int i, ll st) {
	ll t1 = abs(X[s]-X[i]);
	ll t2 = abs(X[i]-X[e]);
	if (t2>T[e]-T[e-1]) return -1;
	if (t1+t2>T[e]-st) return -1;
	return max(st+t1,T[e-1]);
}

int main() {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) {
		scanf("%lld%lld",&T[i],&X[i]);
	}
	T[0] = X[0] = 0;
	D[0] = 0;
	E[0] = 1; ET[0] = 0;
	for (int i=1;i<=N;i++) {
		D[i] = 0;
		for (int j=i-2;j>=0;j--) {
			if (D[j]&&poss(j-1,j+1,i,T[j-1])>=0) {
				D[i] = 1;
				break;
			}
			if (E[j]&&poss(j,j+1,i,ET[j])>=0) {
				D[i] = 1;
				break;
			}
			if (j&&abs(X[j+1]-X[j])>T[j+1]-T[j]) break;
		}
		E[i] = 0;
		ET[i] = LINF;
		if (D[i-1]) {
			ll t = poss(i-2,i,i,T[i-2]);
			if (t>=0) {
				E[i] = 1;
				ET[i] = min(ET[i],t);
			}
		}
		if (E[i-1]) {
//			printf("%d, %d, %d, %lld\n",i-1,i,i,ET[i-1]);
			ll t = poss(i-1,i,i,ET[i-1]);
//			printf("%lld!\n",t);
			if (t>=0) {
				E[i] = 1;
				ET[i] = min(ET[i],t);
			}
		}
//		printf("%d : %d, %d, %lld\n",i,D[i],E[i],ET[i]);
	}
	if (D[N]||E[N]) {
		puts("YES");
	}
	else puts("NO");

	return 0;
}