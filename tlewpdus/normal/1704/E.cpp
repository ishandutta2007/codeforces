#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
vector<int> lis[1010];
int deg[1010];
ll A[1010];

int main() {
	int TT;

	scanf("%d",&TT);
	while(TT--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) {
			scanf("%lld",&A[i]);
		}
		for (int i=0;i<M;i++) {
			int a, b;
			scanf("%d%d",&a,&b); a--; b--;
			lis[a].push_back(b);
			deg[b]++;
		}
		ll ans = -1;
		for (int i=0;i<N;i++) {
			vector<int> nonz;
			for (int j=0;j<N;j++) {
				if (A[j]) nonz.push_back(j);
			}
			if (nonz.empty()) {
				ans = i;
				break;
			}
			for (int &j : nonz) {
				for (int &k: lis[j]) {
					A[k]++;
				}
				A[j]--;
			}
		}
		if (ans==-1) ans = N;
		queue<int> q;
		for (int i=0;i<N;i++) {
			if (deg[i] == 0) q.push(i);
		}
		while(!q.empty()) {
			int here = q.front(); q.pop();
			for (int &there : lis[here]) {
				deg[there]--;
				A[there] = (A[there]+A[here])%MOD;
				if (deg[there]==0) q.push(there);
			}
			if (q.empty()) {
				ans += A[here];
			}
		}
		printf("%lld\n",ans%MOD);
		for (int i=0;i<N;i++) {
			lis[i].clear();
			deg[i] = 0;
		}
	}

	return 0;
}