#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,t,dp[5001][5001],in[5001];
const ll INF=1e14;
vector<pair<ll,ll> > g[5001],rev[5001];
vector<ll> seq;
bool used[5001];
void TopoSort(){
	for(ll i=1;i<=n;i++){
		ll nxt=0;
		for(ll j=1;j<=n;j++){
			if(in[j]==0&&!used[j]){
				nxt=j;
				break;
			} 
		}
		used[nxt]=1;
		seq.push_back(nxt);
		for(ll j=0;j<g[nxt].size();j++)	in[g[nxt][j].first]--;
	}
}
int main(){
	scanf("%d%d%I64d",&n,&m,&t);
	for(ll i=0;i<m;i++){
		int u,v;
		ll w;
		scanf("%d%d%I64d",&u,&v,&w);
		g[u].push_back({v,w});
		rev[v].push_back({u,w});
		in[v]++;
	}
//	for(int i=1;i<=n;i++)	cout<<in[i]<<" ";
	TopoSort();
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=5000;j++){
			dp[i][j]=INF;
		}
	}
	dp[1][1]=0;
	for(int i=0;i<seq.size();i++){
		for(int j=0;j<g[seq[i]].size();j++){
			for(int k=2;k<=n;k++){
				dp[g[seq[i]][j].first][k]=
				min(dp[seq[i]][k-1]+g[seq[i]][j].second,
				dp[g[seq[i]][j].first][k]);
			}
		}
	}
	ll ans=INF;
	for(int i=2;i<=n;i++){
		if(dp[n][i]<=t)	ans=i;
	}
	printf("%I64d\n",ans);
	vector<int> ansv;
	int cur=n,q=ans;
	ansv.push_back(n);
	while(cur!=1){
		q--;
		for(int i=0;i<rev[cur].size();i++){
			if(dp[rev[cur][i].first][q]+rev[cur][i].second==dp[cur][q+1]){
				ansv.push_back(rev[cur][i].first);
				cur=rev[cur][i].first;
				break;
			}
		}
	}
	reverse(ansv.begin(),ansv.end());
	for(int i=0;i<ansv.size();i++)	printf("%d ",ansv[i]);
}