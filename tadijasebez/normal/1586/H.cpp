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

const int N=400050;

int go[N][2],fa[N],val[N],sum[N],tag[N],sz[N],tsz;
int mxe[N],mye[N],mym[N],mrk[N];
int best[N],rev_best[N];
multiset<int> vals[N];
void pull(int x){
	//sum[x]=sum[go[x][0]]+val[x]+sum[go[x][1]];
	//sz[x]=sz[go[x][0]]+1+sz[go[x][1]];

	mxe[x]=max(mxe[go[x][0]],max(mye[x],mxe[go[x][1]]));
	mrk[x]=mrk[go[x][0]]+mym[x]+mrk[go[x][1]];

	best[x]=max(best[go[x][0]],best[go[x][1]]);
	if(mrk[go[x][1]]+mym[x]>0){
		best[x]=max(best[x],mye[x]);
		best[x]=max(best[x],mxe[go[x][0]]);
	}
	if(vals[x].size()){
		best[x]=max(best[x],*vals[x].rbegin());
	}

	rev_best[x]=max(rev_best[go[x][0]],rev_best[go[x][1]]);
	if(mrk[go[x][0]]+mym[x]>0){
		rev_best[x]=max(rev_best[x],mye[x]);
		rev_best[x]=max(rev_best[x],mxe[go[x][1]]);
	}
	if(vals[x].size()){
		rev_best[x]=max(rev_best[x],*vals[x].rbegin());
	}
}
void upd(int x){
	if(x){
		swap(go[x][0],go[x][1]);
		swap(best[x],rev_best[x]);
		tag[x]^=1;
	}
}
void push(int x){if(tag[x])upd(go[x][0]),upd(go[x][1]),tag[x]=0;}
int pd(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q)go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
	if(w)fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
void cl(int x){if(~pd(x))cl(fa[x]);push(x);}
void splay(int x){for(cl(x);~pd(x);rot(x))if(~pd(fa[x]))rot(pd(x)==pd(fa[x])?fa[x]:x);}
void atc(int x,int y){
	if(go[x][1]){
		vals[x].insert(best[go[x][1]]);
		mym[x]+=mrk[go[x][1]];
	}
	if(y){
		vals[x].erase(vals[x].find(best[y]));
		mym[x]-=mrk[y];
	}
	go[x][1]=y;
	pull(x);
}
void access(int x){
	for(splay(x),atc(x,0);fa[x];rot(x))splay(fa[x]),atc(fa[x],x);
}
void mkrt(int x){access(x);upd(x);}

int e[N],ord[N];
struct edge{
	int u,v,c,t;
	edge(){}
	edge(int _u,int _v,int _c,int _t):u(_u),v(_v),c(_c),t(_t){}
	bool operator < (edge other) const {
		return c>other.c;
	}
}edges[N];

int p[N],ee[N];
int Find(int x){return p[x]==x?x:p[x]=Find(p[x]);}
vector<int> marked[N];
void AddEdge(int u,int v,int t){
	int a=u,b=v;
	u=Find(u);
	v=Find(v);
	if(ee[u]>ee[v]){
		for(int i:marked[v]){
			mkrt(i);
			mym[i]--;
			pull(i);
		}
		marked[v].clear();
	}else if(ee[v]>ee[u]){
		for(int i:marked[u]){
			mkrt(i);
			mym[i]--;
			pull(i);
		}
		marked[u].clear();
	}
	if(marked[u].size()>marked[v].size()){
		swap(u,v);
	}
	for(int i:marked[u]){
		marked[v].pb(i);
	}
	marked[u].clear();
	p[u]=v;
	ee[v]=max(ee[u],ee[v]);

	tsz++;
	mye[tsz]=t;

	mkrt(a);
	fa[a]=tsz;
	go[tsz][1]=a;
	fa[a]=tsz;

	access(b);
	go[tsz][0]=b;
	fa[b]=tsz;

	pull(tsz);
}

pii Solve(int u){
	int eee=ee[Find(u)];
	mkrt(u);
	int ans=best[u];
	return {eee,ans};
}

int qrd[N],qc[N],st[N];
pii ans[N];
int main(){
	int n,q;
	rd(n,q);
	ra(e,n);
	for(int i=1;i<=n;i++){
		mym[i]=1;
		marked[i]={i};
		p[i]=i;
		ee[i]=e[i];
	}
	tsz=n;
	for(int i=1;i<n;i++){
		int u,v,c,t;
		rd(u,v,c,t);
		ord[i]=i;
		edges[i]=edge(u,v,c,t);
	}
	sort(ord+1,ord+n,[&](int i,int j){return edges[i]<edges[j];});
	for(int i=1;i<=q;i++){
		qrd[i]=i;
		rd(qc[i],st[i]);
	}
	sort(qrd+1,qrd+1+q,[&](int i,int j){return qc[i]>qc[j];});
	int ptr=1;
	for(int i=1;i<=q;i++){
		int qi=qrd[i];
		while(ptr<n&&edges[ord[ptr]].c>=qc[qi]){
			//printf("Add Edge %i\n",ord[ptr]);
			AddEdge(edges[ord[ptr]].u,edges[ord[ptr]].v,edges[ord[ptr]].t);
			ptr++;
		}
		//printf("Answer %i\n",qi);
		ans[qi]=Solve(st[qi]);
	}
	for(int i=1;i<=q;i++){
		printf("%i %i\n",ans[i].first,ans[i].second);
	}
	return 0;
}