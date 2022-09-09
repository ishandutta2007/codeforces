#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lc ls[c]
#define rc rs[c]
void ckmn(ll &x,ll y){x=min(x,y);}
const int N=400050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll a[M],b[M],wait[M],lzy[M];
void pull(int c){
	if(a[lc]*b[lc]>a[rc]*b[rc])a[c]=a[lc],b[c]=b[lc];
	else a[c]=a[rc],b[c]=b[rc];
	wait[c]=min(wait[lc],wait[rc]);
	if(b[lc]!=b[rc]){
		ll tme=(a[lc]*b[lc]-a[rc]*b[rc])/(b[rc]-b[lc]);
		if(tme>=0)ckmn(wait[c],tme);
	}
}
void upd(int c,ll x){wait[c]-=x;a[c]+=x;lzy[c]+=x;}
void push(int c){upd(lc,lzy[c]);upd(rc,lzy[c]);lzy[c]=0;}
int A[N],B[N];
void Build(int &c,int ss,int se){
	c=++tsz;
	if(ss==se){
		wait[c]=1e9;
		a[c]=A[ss/2];
		b[c]=B[ss/2]*((ss&1)?1:-1);
		return;
	}
	int mid=ss+se>>1;
	Build(lc,ss,mid);
	Build(rc,mid+1,se);
	pull(c);
}
void Add(int c,int ss,int se,int qs,int qe,ll x){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se&&wait[c]>=x){upd(c,x);return;}
	push(c);
	int mid=ss+se>>1;
	Add(lc,ss,mid,qs,qe,x);
	Add(rc,mid+1,se,qs,qe,x);
	pull(c);
}
ll Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return a[c]*b[c];
	push(c);
	int mid=ss+se>>1;
	return max(Get(lc,ss,mid,qs,qe),Get(rc,mid+1,se,qs,qe));
}
int _a[N],_b[N],lid[N],rid[N],tid,par[N];
vector<int> E[N];
void DFS(int u){
	_a[u]+=_a[par[u]];
	_b[u]+=_b[par[u]];
	lid[u]=tid++;
	A[lid[u]]=_a[u];
	B[lid[u]]=_b[u];
	for(int v:E[u])DFS(v);
	rid[u]=tid;
}
int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=2;i<=n;i++)scanf("%i",&par[i]),E[par[i]].pb(i);
	for(int i=1;i<=n;i++)scanf("%i",&_a[i]);
	for(int i=1;i<=n;i++)scanf("%i",&_b[i]);
	DFS(1);
	int lim=tid*2-1;
	Build(root,0,lim);
	while(q--){
		int t,u,x;
		scanf("%i %i",&t,&u);
		if(t==1)scanf("%i",&x),Add(root,0,lim,lid[u]*2,rid[u]*2-1,x);
		else printf("%lld\n",Get(root,0,lim,lid[u]*2,rid[u]*2-1));
	}
	return 0;
}