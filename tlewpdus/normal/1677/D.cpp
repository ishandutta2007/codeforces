#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, K;
int V[1000100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&K);
		for (int i=0;i<N;i++) scanf("%d",&V[i]);
		bool bad = false;
		for (int i=N-1;i>N-1-K;i--) {
			if (V[i]==-1) V[i] = 0;
			if (V[i]!=0) bad = true;
		}
		if (bad) {
			puts("0");
			continue;
		}
		ll ans = 1;
		for (int i=1;i<=K;i++) ans = ans*i%MOD;
		for (int i=0;i<=N-1-K;i++) {
			if (V[i]==0) ans = ans*(K+1)%MOD;
			else if (V[i]==-1) {
				ans = ans*(K+1+i)%MOD;
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}