//Pasted
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int N=2e5+10;
const ll Inf=1e12;
#define pb push_back
#define sz(a) int(a.size())
 
int n,c[N],h[N];
ll f[N][2];
vi E[N];
 
void dfs(int u,int fa) {
	ll sum0=0;
	vector<ll> vec;
	for(auto v:E[u])
		if(v!=fa) dfs(v,u),sum0+=f[v][0],vec.pb(f[v][1]-f[v][0]);
	sort(vec.begin(),vec.end());
	for(int t=0;t<min(u,2);t++) {
		f[u][t]=Inf;
		if(u>1) {
			if((!t&&h[fa]>h[u])||(t&&h[fa]<h[u])) continue;
		}
		int out=t+sz(vec);ll sum=sum0;
		for(int i=0;i<=sz(vec);i++) {
			if(i) sum+=vec[i-1];
			f[u][t]=min(f[u][t],sum+1ll*max(out,sz(vec)+(u>1)-out)*c[u]);
			--out;
		}
	}
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1,u,v;i<n;i++) cin>>u>>v,E[u].pb(v),E[v].pb(u);
	dfs(1,0);cout<<f[1][0];
	return 0;
}