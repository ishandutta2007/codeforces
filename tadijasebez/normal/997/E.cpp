//	2004 <3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=120050;
const int M=4*N;
const int LOG=20;
int tsz,mn[M],lzy[M];
void pull(int c){mn[c]=min(mn[c<<1],mn[c<<1|1]);}
void upd(int c,int x){mn[c]+=x;lzy[c]+=x;}
void push(int c){upd(c<<1,lzy[c]);upd(c<<1|1,lzy[c]);lzy[c]=0;}
void Add(int c,int ss,int se,int qs,int qe,int x){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se)return upd(c,x);
	push(c);int mid=ss+se>>1;
	Add(c<<1,ss,mid,qs,qe,x);
	Add(c<<1|1,mid+1,se,qs,qe,x);
	pull(c);
}
int Get(int c,int ss,int se,int qi){
	if(ss==se)return mn[c];
	push(c);int mid=ss+se>>1;
	return qi<=mid?Get(c<<1,ss,mid,qi):Get(c<<1|1,mid+1,se,qi);
}
int Fir(int c,int ss,int se){
	if(ss==se)return ss;
	push(c);int mid=ss+se>>1;
	return mn[c<<1]==0?Fir(c<<1,ss,mid):Fir(c<<1|1,mid+1,se);
}
int n,a[N],smn[N],smx[N],tmn,tmx;
int tot,L[M],R[M],stk[M],typ[M],top,idx[N];
vector<int> E[M];
void Build(){
	for(int i=1;i<=n;i++){
		for(;tmn&&a[smn[tmn]]>a[i];tmn--)Add(1,1,n,smn[tmn-1]+1,smn[tmn],a[smn[tmn]]);
		Add(1,1,n,smn[tmn]+1,i,-a[i]);smn[++tmn]=i;
		for(;tmx&&a[smx[tmx]]<a[i];tmx--)Add(1,1,n,smx[tmx-1]+1,smx[tmx],-a[smx[tmx]]);
		Add(1,1,n,smx[tmx]+1,i,a[i]);smx[++tmx]=i;
		int ptr=Fir(1,1,n),now=++tot;
		L[now]=R[now]=i;idx[i]=now;
		while(top&&L[stk[top]]>=ptr){
			if(typ[stk[top]]&&!Get(1,1,n,L[E[stk[top]][1]])){
				E[stk[top]].pb(now);R[stk[top]]=i;now=stk[top--];
			}else if(!Get(1,1,n,L[stk[top]])){
				typ[++tot]=1;E[tot].pb(stk[top]);E[tot].pb(now);
				L[tot]=L[stk[top]];R[tot]=i;top--;now=tot;
			}else{
				tot++;E[tot].pb(now);
				do E[tot].pb(stk[top]);while(Get(1,1,n,L[stk[top--]]));
				reverse(E[tot].begin(),E[tot].end());
				L[tot]=L[E[tot][0]];R[tot]=i;
				now=tot;
			}
		}
		stk[++top]=now;
		Add(1,1,n,1,i,-1);
	}
}
ll sub_dp[M],dp_l[M],dp_r[M];
ll c2(int x){return (ll)x*(x-1)/2;}
int pl[M],par[M][LOG],dep[M];
vector<ll> P[M];
void DFS(int u,int p){
	sub_dp[u]=typ[u]?c2(E[u].size()):1;P[u].pb(0);dep[u]=dep[p]+1;
	par[u][0]=p;for(int i=1;i<LOG;i++)par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u])DFS(v,u),sub_dp[u]+=sub_dp[v],P[u].pb(sub_dp[v]);
	for(int i=1;i<P[u].size();i++)P[u][i]+=P[u][i-1],pl[E[u][i-1]]=i;
}
void LRDP(int u){
	ll sum_l=0,sum_r=0;
	for(int i=0;i<E[u].size();i++){
		dp_l[E[u][i]]=dp_l[u]+sum_l;
		if(typ[u])dp_l[E[u][i]]+=c2(i);
		sum_l+=sub_dp[E[u][i]];
		dp_r[E[u][E[u].size()-i-1]]=dp_r[u]+sum_r;
		if(typ[u])dp_r[E[u][E[u].size()-i-1]]+=c2(i);
		sum_r+=sub_dp[E[u][E[u].size()-i-1]];
	}
	for(int v:E[u])LRDP(v);
}
int LCA(int u,int v){
	if(u==0||v==n+1)return stk[top];
	u=idx[u];v=idx[v];
	if(dep[u]<dep[v])swap(u,v);
	for(int i=LOG-1;~i;i--)if(dep[par[u][i]]>=dep[v])u=par[u][i];
	for(int i=LOG-1;~i;i--)if(par[u][i]!=par[v][i])u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int up(int u,int k){for(int i=0;i<LOG;i++)if(k>>i&1)u=par[u][i];return u;}
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	Build();
	DFS(stk[top],0);
	LRDP(stk[top]);
	int q;
	scanf("%i",&q);
	while(q--){
		int l,r;
		scanf("%i %i",&l,&r);
		l--;r++;
		if(l==0&&r==n+1)printf("%lld\n",sub_dp[stk[top]]);
		else if(l==0)printf("%lld\n",dp_l[idx[r]]);
		else if(r==n+1)printf("%lld\n",dp_r[idx[l]]);
		else{
			int lca=LCA(l,r);
			l=idx[l];r=idx[r];
			int x=up(l,dep[l]-dep[lca]-1);
			int y=up(r,dep[r]-dep[lca]-1);
			ll ans=dp_r[l]-dp_r[x]+dp_l[r]-dp_l[y];
			ans+=P[lca][pl[y]-1]-P[lca][pl[x]];
			if(typ[lca]==1)ans+=c2(pl[y]-pl[x]-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}