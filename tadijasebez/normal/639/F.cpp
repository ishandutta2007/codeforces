#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
const int L=19;
vector<pair<int,int> > G[N];
vector<int> E[N];
bool e_was[N*2],in[N];
int disc[N],low[N],nid,comp[N],cmz,chu[N];
stack<int> s;
void BCC(int u, int p)
{
	disc[u]=low[u]=++nid;
	in[u]=1;s.push(u);
	for(auto e:G[u])
	{
		int v=e.first;
		int i=e.second;
		//printf("(%i -> %i)\n",u,v);
		if(!disc[v])
		{
			e_was[i]=1;
			BCC(v,u);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v] && (p!=v || !e_was[i])) low[u]=min(low[u],disc[v]);
	}
	if(disc[u]==low[u])
	{
		int v;
		cmz++;
		do
		{
			v=s.top();
			s.pop();
			comp[v]=cmz;
			in[v]=0;
		}while(v!=u);
	}
}
struct DSU
{
	int p[N];
	void init(){ for(int i=0;i<N;i++) p[i]=i;}
	DSU(){ init();}
	int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
	bool Same(int x, int y){ return Find(x)==Find(y);}
	void Union(int x, int y){ p[Find(x)]=Find(y);}
} Tree;
int dep[N],par[N][L],sz[N],lid[N],rid[N],tid;
void DFS(int u, int p)
{
	sz[u]=1;
	dep[u]=dep[p]+1;
	par[u][0]=p;
	lid[u]=++tid;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u]) if(v!=p) DFS(v,u),sz[u]+=sz[v];
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	for(int i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int head[N],csz[N];
void HLD(int u, int p)
{
	if(!head[u]) head[u]=u;
	csz[head[u]]++;
	int HC=0;
	for(int v:E[u]) if(v!=p && sz[v]>sz[HC]) v=HC;
	for(int v:E[u]) if(v!=p) head[v]=v==HC?head[u]:v,HLD(v,u);
}
bool cmp(int u, int v){ return lid[u]<lid[v];}
const int M=2*N;
int ls[M],rs[M],tsz,root[N],lzy[M],sum[M];
void Push(int c, int ss, int se)
{
	if(!lzy[c]) return;
	if(!ls[c]) ls[c]=++tsz;
	if(!rs[c]) rs[c]=++tsz;
	int mid=ss+se>>1;
	sum[rs[c]]=(se-mid)*(lzy[c]-1);
	sum[ls[c]]=(mid-ss+1)*(lzy[c]-1);
	lzy[ls[c]]=lzy[rs[c]]=lzy[c];
	lzy[c]=0;
}
void Set(int &c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ lzy[c]=f+1;sum[c]=(se-ss+1)*f;return;}
	int mid=ss+se>>1;
	Push(c,ss,se);
	Set(ls[c],ss,mid,qs,qe,f);
	Set(rs[c],mid+1,se,qs,qe,f);
	sum[c]=sum[ls[c]]+sum[rs[c]];
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe || !c) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	Push(c,ss,se);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
void SetUp(int u, int lca, int f)
{
	int i;
	for(i=u;head[i]!=head[lca];i=par[head[i]][0])
	{
		Set(root[head[i]],1,csz[head[i]],1,dep[i]-dep[head[i]]+1,f);
	}
	Set(root[head[i]],1,csz[head[i]],dep[lca]-dep[head[i]]+2,dep[i]-dep[head[i]]+1,f);
}
void SetPath(int u, int v, int f)
{
	int lca=LCA(u,v);
	if(lca==0) return;
	SetUp(u,lca,f);
	SetUp(v,lca,f);
}
int Dist(int u, int v)
{
	int lca=LCA(u,v);
	if(lca==0) return 0;
	return dep[u]+dep[v]-2*dep[lca];
}
int GetUp(int u, int lca)
{
	int ans=0,i;
	for(i=u;head[i]!=head[lca];i=par[head[i]][0])
	{
		ans+=Get(root[head[i]],1,csz[head[i]],1,dep[i]-dep[head[i]]+1);
	}
	ans+=Get(root[head[i]],1,csz[head[i]],dep[lca]-dep[head[i]]+2,dep[i]-dep[head[i]]+1);
	return ans;
}
int GetPath(int u, int v)
{
	int lca=LCA(u,v);
	if(lca==0) return 0;
	return GetUp(u,lca)+GetUp(v,lca);
}
ll cnt=0;
int n;
int Rotate(int x)
{
	x=(x+cnt)%n;
	if(x==0) x=n;
	return x;
}
int main()
{
	int m,q,i,u,v;
	scanf("%i %i %i",&n,&m,&q);
	vector<pair<int,int> > edges;
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),G[u].pb(mp(v,i)),G[v].pb(mp(u,i)),edges.pb(mp(u,v));
	for(i=1;i<=n;i++) if(!disc[i]) BCC(i,0);
	for(i=1;i<=n;i++) G[i].clear();
	for(auto p:edges)
	{
		u=comp[p.first];
		v=comp[p.second];
		if(!Tree.Same(u,v)) E[u].pb(v),E[v].pb(u),Tree.Union(u,v);
	}
	for(i=1;i<=cmz;i++) if(Tree.p[i]==i) DFS(i,0),HLD(i,0);
	//printf("comp:");for(i=1;i<=n;i++) printf("%i ",comp[i]);printf("\n");
	//printf("stack:%i\n",s.size());
	int qn=0;
	while(q--)
	{
		int a,b;
		scanf("%i %i",&a,&b);
		vector<pair<int,int> > es(b);
		vector<int> st(a),all,id;
		for(int &f:st) scanf("%i",&f),f=Rotate(f),f=comp[f],all.pb(f);
		for(auto &f:es) scanf("%i %i",&f.first,&f.second),f.first=Rotate(f.first),f.second=Rotate(f.second);
		for(auto f:es)
		{
			u=comp[f.first];
			v=comp[f.second];
			all.pb(u);all.pb(v);
			//SetPath(u,v,1);
		}
		sort(all.begin(),all.end(),cmp);
		int sz=all.size();
		for(i=1;i<sz;i++) if(LCA(all[i],all[i-1])!=0) all.pb(LCA(all[i],all[i-1]));
		sort(all.begin(),all.end());
		all.resize(unique(all.begin(),all.end())-all.begin());
		id=all;
		sort(all.begin(),all.end(),cmp);
		int ecnt=0;
		//printf("all:");for(i:all) printf("%i ",i);printf("\n");
		//printf("id:");for(i:id) printf("%i ",i);printf("\n");
		for(i=1;i<all.size();i++)
		{
			u=all[i];v=all[i-1];
			int lca=LCA(u,v);
			if(lca==0) continue;
			ecnt++;
			u=lower_bound(id.begin(),id.end(),u)-id.begin()+1;
			lca=lower_bound(id.begin(),id.end(),lca)-id.begin()+1;
			G[lca].pb(mp(u,ecnt));
			G[u].pb(mp(lca,ecnt));
		}
		for(auto f:es)
		{
			u=comp[f.first];
			v=comp[f.second];
			//printf("(%i %i)\n",u,v);
			u=lower_bound(id.begin(),id.end(),u)-id.begin()+1;
			v=lower_bound(id.begin(),id.end(),v)-id.begin()+1;
			//printf("(%i %i)\n",u,v);
			ecnt++;
			G[u].pb(mp(v,ecnt));
			G[v].pb(mp(u,ecnt));
		}
		for(i=1;i<=id.size();i++) chu[i]=comp[i];
		for(i=1;i<=ecnt;i++) e_was[i]=0;
		for(i=1;i<=id.size();i++) disc[i]=low[i]=in[i]=0,comp[i]=0;
		nid=0;cmz=0;
		for(i=1;i<=id.size();i++) if(!disc[i]) BCC(i,0);
		bool ok=1;
		int cp=0;
		for(int f:st)
		{
			int p=lower_bound(id.begin(),id.end(),f)-id.begin()+1;
			if(!cp) cp=comp[p];
			if(cp!=comp[p]) ok=0;
		}
		for(i=1;i<=id.size();i++) comp[i]=chu[i],G[i].clear();
		/*sort(st.begin(),st.end(),cmp);
		bool ok=1;
		for(i=1;i<st.size();i++)
		{
			u=st[i];
			v=st[i-1];
			if(Dist(u,v)!=GetPath(u,v)){ ok=0;break;}
		}
		for(auto f:es)
		{
			u=comp[f.first];
			v=comp[f.second];
			SetPath(u,v,0);
		}*/
		printf("%s\n",ok?"YES":"NO");
		qn++;
		if(ok) cnt+=qn;
	}
	return 0;
}