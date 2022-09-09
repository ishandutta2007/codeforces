#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N;
vector<int> lis[100100];
ll A[100100][2];
ll D[100100][2];

void idfs(int here, int p) {
	D[here][0] = D[here][1] = 0;
	for (int &there : lis[here]) {
		if (there!=p) {
			idfs(there,here);
			D[here][0] += max(D[there][0]+abs(A[there][0]-A[here][0]),D[there][1]+abs(A[there][1]-A[here][0]));
			D[here][1] += max(D[there][0]+abs(A[there][0]-A[here][1]),D[there][1]+abs(A[there][1]-A[here][1]));
		}
	}
}

int main () {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%lld%lld",&A[i][0],&A[i][1]);
		for (int i=0;i<N-1;i++) {
			int u, v;
			scanf("%d%d",&u,&v); --u; --v;
			lis[u].push_back(v);
			lis[v].push_back(u);
		}
		idfs(0,-1);
		printf("%lld\n",max(D[0][0],D[0][1]));
		for (int i=0;i<N;i++) lis[i].clear();
	}

	return 0;
}