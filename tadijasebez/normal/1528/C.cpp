#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
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

const int N=300050;
vector<int> E[2][N];
int lid[N],rid[N],ord[N],tid,n;
int head[N],par[N],sz[N];
void DFS(int u,int t){
	sz[u]=1;
	for(int v:E[t][u]){
		DFS(v,t);
		sz[u]+=sz[v];
		par[v]=u;
	}
	}
void HLD(int u,int t){
	lid[u]=++tid;
	ord[tid]=u;
	if(!head[u])head[u]=u;
	int hc=0;
	for(int v:E[t][u])if(sz[v]>sz[hc])hc=v;
	if(hc){
		head[hc]=head[u];
		HLD(hc,t);
	}
	for(int v:E[t][u])if(v!=hc){
		HLD(v,t);
	}
	rid[u]=tid;
}
const int M=2*N;
int ls[M],rs[M],tsz,root;
/*struct Node{
	int sum,lef,rig;
	Node(){sum=0;}
	Node(int l,int r){
		sum=1;
		lef=l;
		rig=r;
	}
}node[M];
Node operator + (Node a,Node b){
	if(a.sum==0)return b;
	if(b.sum==0)return a;
	Node ans;
	ans.sum=a.sum+b.sum;
	if(a.rig>=b.lef){
		ans.sum--;
		if(a.sum==1&&b.sum==1){
			if(a.rig<b.rig)return a;
			else return b;
		}else{
			if(a.sum==1)ans.lef=b.lef;
			else ans.lef=a.lef;
			if(b.sum==1)ans.rig=min(a.rig,b.rig);
			else ans.rig=b.rig;
		}
	}else{
		ans.lef=a.lef;
		ans.rig=b.rig;
	}
	return ans;
}*/
int lzy[M],sum[M];
void Set(int&c,int ss,int se,int qi,int x){
	if(!c)c=++tsz;
	if(ss==se){
		sum[c]=x;
		//if(x==0)node[c]=Node();
		//else node[c]=Node(lid[ord[ss]],rid[ord[ss]]);
		return;
	}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	sum[c]=sum[ls[c]]*(lzy[ls[c]]==0)+sum[rs[c]]*(lzy[rs[c]]==0);
	//node[c]=node[ls[c]]+node[rs[c]];
}
void AddLzy(int&c,int ss,int se,int qs,int qe,int x){
	if(qs>qe||qs>se||ss>qe)return;
	if(!c)c=++tsz;
	if(qs<=ss&&qe>=se){
		lzy[c]+=x;
		return;
	}
	int mid=ss+se>>1;
	AddLzy(ls[c],ss,mid,qs,qe,x);
	AddLzy(rs[c],mid+1,se,qs,qe,x);
	sum[c]=sum[ls[c]]*(lzy[ls[c]]==0)+sum[rs[c]]*(lzy[rs[c]]==0);
}
void AddPath(int u,int x){
	while(u){
		AddLzy(root,1,n,lid[head[u]],lid[u],x);
		u=par[head[u]];
	}
}
void Add(int qi){
	Set(root,1,n,qi,1);
	AddPath(par[ord[qi]],1);
}
void Del(int qi){
	Set(root,1,n,qi,0);
	AddPath(par[ord[qi]],-1);
}
//int Get(){return node[root].sum;}
int Get(){return sum[root]*(lzy[root]==0);}
int ans=0;
void Go(int u,int t){
	Add(lid[u]);
	ckmx(ans,Get());
	for(int v:E[t][u]){
		Go(v,t);
	}
	Del(lid[u]);
}
int main(){
	for(int t=ri();t--;){
		n=ri();
		for(int i=2;i<=n;i++){
			int p=ri();
			E[0][p].pb(i);
		}
		for(int i=2;i<=n;i++){
			int p=ri();
			E[1][p].pb(i);
		}
		DFS(1,1);
		HLD(1,1);
		ans=0;
		Go(1,0);
		printf("%i\n",ans);
		for(int i=1;i<=n;i++){
			E[0][i].clear();
			E[1][i].clear();
			head[i]=par[i]=sz[i]=0;
			lid[i]=rid[i]=ord[i]=0;
		}
		tid=0;
		root=0;
	}
	return 0;
}