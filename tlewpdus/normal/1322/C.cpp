#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

ll P = 847219;
ll M[2] = {1403001989, 1403001997};

int n, m;
ll C[500100];
vector<int> lis[500100];
map<pll,ll> mpi;

ll gcd(ll a, ll b) {
	return a?gcd(b%a,a):b;
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lld",&C[i]);
		for (int i=0;i<m;i++) {
			int a, b;
			scanf("%d%d",&a,&b);
			lis[b].push_back(a);
		}
		for (int i=1;i<=n;i++) {
			if (lis[i].empty()) continue;
			sort(lis[i].begin(),lis[i].end());
			ll sum[2] = {0,0};
			for (int &v : lis[i]) {
				sum[0] = (sum[0]*P+v)%M[0];
				sum[1] = (sum[1]*P+v)%M[1];
			}
			mpi[{sum[0]*M[1]+sum[2],lis[i].size()}]+=C[i];
		}
		ll g = 0;
		auto it = mpi.begin();
		while(it!=mpi.end()) {
			g = gcd(g,it->second);
			it++;
		}
		printf("%lld\n",g);
		for (int i=1;i<=n;i++) lis[i].clear();
		mpi.clear();
	}

	return 0;
}