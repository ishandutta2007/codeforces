#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}
const int N=200050;
const int O=2*N;
const int L=20;
int p[O],par[O][L],dtr[O][L],n,m,q,tot;
vector<int> E[O];
int lid[O],rid[O],tid,dfs_ord[O];
int Find(int x){return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int u,int v,int w){
	u=Find(u);v=Find(v);
	dtr[u][0]=dtr[v][0]=w;
	par[u][0]=par[v][0]=++tot;
	p[u]=p[v]=p[tot]=tot;
	E[tot].pb(u);
	E[tot].pb(v);
}
void DFS(int u){
	for(int i=1;i<L;++i){
		par[u][i]=par[par[u][i-1]][i-1];
		dtr[u][i]=min(dtr[u][i-1],dtr[par[u][i-1]][i-1]);
	}
	if(E[u].empty())lid[u]=++tid,dfs_ord[lid[u]]=u;
	else lid[u]=tid+1;
	for(int v:E[u]){
		DFS(v);
	}
	rid[u]=tid;
}
const int M=2*N;
int val[N];
int ls[M],rs[M],tsz,root;
pii mx[M];
void Build(int&c,int ss,int se){
	c=++tsz;
	if(ss==se){
		mx[c]={val[dfs_ord[ss]],dfs_ord[ss]};
		return;
	}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
void Set(int c,int ss,int se,int qi,int x){
	if(ss==se){mx[c]={0,x};return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
pii Get(int c,int ss,int se,int qs,int qe){
	if(qs>qe||ss>qe||qs>se)return {0,0};
	if(qs<=ss&&qe>=se)return mx[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
const int H=500050;
pii edges[H];
int t[H],qu[H],idx[H],ord[H];
int main(){
	rd(n,m,q);
	for(int i=1;i<=n;i++)p[i]=i;
	tot=n;
	ra(val,n);
	ra(edges,m);
	ra(t,qu,q);
	for(int i=1;i<=m;i++)idx[i]=q+1,ord[i]=i;
	for(int i=1;i<=q;i++){
		if(t[i]==2){
			idx[qu[i]]=i;
		}
	}
	sort(ord+1,ord+1+m,[&](int i,int j){return idx[i]>idx[j];});
	for(int z=1;z<=m;z++){
		int i=ord[z];
		if(Find(edges[i].first)!=Find(edges[i].second)){
			int u,v;tie(u,v)=edges[i];
			Union(u,v,idx[i]);
		}
	}
	for(int i=1;i<=tot;i++)if(par[i][0]==0)DFS(i);
	Build(root,1,n);
	for(int i=1;i<=q;i++){
		if(t[i]==1){
			int u=qu[i];
			for(int j=L-1;~j;--j){
				if(dtr[u][j]>=i){
					u=par[u][j];
				}
			}
			pii ans=Get(root,1,n,lid[u],rid[u]);
			printf("%i\n",ans.first);
			Set(root,1,n,lid[ans.second],ans.second);
		}
	}
	return 0;
}