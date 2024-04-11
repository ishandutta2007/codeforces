#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
char S[3010], T[3010];
int D[6010][6010];

int main() {
	scanf(" %s",S+1);
	n = strlen(S+1);
	scanf(" %s",T+1);
	m = strlen(T+1);
	for (int i=1;i<=n+m+1;i++) {
		D[i][i-1] = 1;
	}
	ll ans = 0;
	for (int l=0;l<n;l++) {
		for (int s=1;s+l<=n+m+1;s++) {
			int e = s+l;
			if (s>m||S[l+1]==T[s]) D[s][e] += D[s+1][e];
			if (e>m||S[l+1]==T[e]) D[s][e] += D[s][e-1];
			D[s][e] %= MOD;
			if (s==1&&e>=m) ans += D[s][e];
		}
	}
	printf("%lld\n",ans%MOD);

	return 0;
}