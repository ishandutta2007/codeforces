#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, k;
vector<int> lis[200100];
int sz[200100], dep[200100];

void dfs(int here, int p) {
	sz[here] = 1;
	dep[here] = dep[p]+1;
	for (int &there : lis[here]) {
		if (there!=p) {
			dfs(there,here);
			sz[here] += sz[there];
		}
	}
}
int ord[200100];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b);
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	dfs(1,0);
	iota(ord,ord+n,1);
	sort(ord,ord+n,[](int a, int b){return sz[a]-dep[a]>sz[b]-dep[b];});
	ll ans = 0;
	for (int id=0;id<n-k;id++) {
		int i = ord[id];
		ans += sz[i]-dep[i];
	}
	printf("%lld\n",ans);

	return 0;
}