#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll ans;
vector<ll> g[3010];
struct cmp {
	bool operator () (ll x,ll y) {
		return x>y;
	}
};
priority_queue<ll,vector<ll>,cmp> q;
ll solve(int x) {
	ll res=0;
	int cnt=x-g[1].size();
	while (!q.empty()) q.pop();
	for (int i=2;i<=m;i++) {
		int j=0;
		if (g[i].size()>=x) {
			while (j<=g[i].size()-x)
				res+=g[i][j],j++,cnt--;
		}
		while (j<g[i].size()) q.push(g[i][j]),j++;
	}
	while (cnt>0)
		res+=q.top(),q.pop(),cnt--;
    return res;
}
int main() {
//	freopen("1.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
	}
	for (int i=1;i<=m;i++)
		sort(g[i].begin(),g[i].end());
	ans=1e18;
	for (int i=1;i<=n;i++)
		ans=min(ans,solve(i));
	printf("%lld\n",ans);
	return 0;
}