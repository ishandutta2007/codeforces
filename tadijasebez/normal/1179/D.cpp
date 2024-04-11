#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=500050;
const ll inf=9e18;
struct Line{
	ll k,n;
	Line(){}
	Line(ll a,ll b):k(a),n(b){}
	ll Get(ll x){return x*k+n;}
};
int root[N],tsz,ls[N],rs[N];
Line line[N];
void Set(int &c,int ss,int se,Line k){
	if(!c){c=++tsz;ls[c]=rs[c]=0;line[c]=k;return;}
	ll A=k.Get(ss),B=line[c].Get(ss),C=k.Get(se),D=line[c].Get(se);
	if(A<=B && C<=D)return;
	if(A>=B && C>=D){line[c]=k;return;}
	if(A>B)swap(line[c],k);
	int mid=ss+se>>1;
	if(line[c].Get(mid)<=k.Get(mid))Set(rs[c],mid+1,se,k);
	else swap(line[c],k),Set(ls[c],ss,mid,k);
}
ll Get(int c,int ss,int se,int qi){
	if(!c)return -inf;
	ll ans=line[c].Get(qi);
	if(ss==se)return ans;
	int mid=ss+se>>1;
	if(qi<=mid)return max(ans,Get(ls[c],ss,mid,qi));
	else return max(ans,Get(rs[c],mid+1,se,qi));
}
int sz[N],n;
ll dp[N],ans;
vector<int> E[N];
void SZ(int u,int p){sz[u]=1;for(int v:E[u])if(v!=p)SZ(v,u),sz[u]+=sz[v];}
void DFS(int u,int p){
	dp[u]=(ll)sz[u]*(n-sz[u]);
	for(int v:E[u])if(v!=p){
		DFS(v,u);
		ans=max(ans,dp[v]);
		dp[u]=max(dp[u],dp[v]+(ll)(n-sz[u])*(sz[u]-sz[v]));
		ans=max(ans,dp[v]+Get(root[u],1,n,sz[v]));
		Set(root[u],1,n,Line(-sz[v],dp[v]));
	}
}
int main(){
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	SZ(1,0);
	DFS(1,0);
	printf("%lld\n",ans+(ll)n*(n-1)/2);
	return 0;
}