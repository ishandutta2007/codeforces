#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=20050;
const int M=2*N;
const int mod=958989859;
bool debug=0;
int powmod(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int modulo(int x){ return x<0?x+mod:x>=mod?x-mod:x;}
int po[N],ip[N];
void preprocess(){ po[0]=ip[0]=1;for(int i=1;i<N;i++) po[i]=(ll)po[i-1]*26%mod,ip[i]=powmod(po[i],mod-2);}
vector<pair<int,char> > E[N];
int fwhs[N],bwhs[N],dep[N],par[N][15];char ch[N];
void DFS(int u, int p, int d, int c)
{
	int i;
	dep[u]=dep[p]+1;
	ch[u]='a'+c-1;
	if(p)
	{
		fwhs[u]=modulo((ll)fwhs[p]*26%mod+c);
		bwhs[u]=modulo((ll)c*po[d]%mod+bwhs[p]);
		par[u][0]=p;
		for(i=1;i<15;i++) par[u][i]=par[par[u][i-1]][i-1];
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		char w=E[u][i].second;
		if(v!=p) DFS(v,u,d+1,w-'a'+1);
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=14;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=14;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int Dist(int u, int v){ return dep[u]+dep[v]-2*dep[LCA(u,v)];}
int Dist(int u, int v, int lca){ return dep[u]+dep[v]-2*dep[lca];}
int GetKthLetter(int u, int v, int k)
{
	int lca=LCA(u,v),i;
	if(Dist(u,lca,lca)<k)
	{
		k=Dist(u,v,lca)-k;
		for(i=14;~i;i--) if((k>>i)&1) v=par[v][i];
		return v;
	}
	k--;
	for(i=14;~i;i--) if((k>>i)&1) u=par[u][i];
	return u;
}
int GetKth(int u, int v, int k)
{
	int lca=LCA(u,v),i;
	if(Dist(u,lca,lca)<k)
	{
		k=Dist(u,v,lca)-k;
		for(i=14;~i;i--) if((k>>i)&1) v=par[v][i];
		return v;
	}
	for(i=14;~i;i--) if((k>>i)&1) u=par[u][i];
	return u;
}
int GetHash(int u, int v)
{
	int lca=LCA(u,v);
	int sol=modulo(fwhs[u]-(ll)fwhs[lca]*po[Dist(u,lca,lca)]%mod);
	sol=modulo(sol+(ll)modulo(bwhs[v]-bwhs[lca])*ip[max(dep[lca]-1,0)]%mod*po[Dist(u,lca,lca)]%mod);
	//if(debug) printf("GetHash(%i, %i)=%i\n",u,v,sol);
	return sol;
}
int Compare(int a, int b, int c, int d)
{
	int len1=Dist(a,b),len2=Dist(c,d),top=min(len1,len2),bot=1,ans=0,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		int h1=GetHash(a,GetKth(a,b,mid));
		int h2=GetHash(c,GetKth(c,d,mid));
		if(h1==h2) ans=mid,bot=mid+1;
		else top=mid-1;
	}
	if(ans==min(len1,len2)) return 0;
	return ch[GetKthLetter(a,b,ans+1)]<ch[GetKthLetter(c,d,ans+1)]?1:-1;
}
int sze[N];bool vis[N];
void DFS(int u, int p, int &n)
{
	n++;sze[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v]) DFS(v,u,n),sze[u]+=sze[v];
	}
}
int Find(int u, int p, int n)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v] && sze[v]>n/2) return Find(v,u,n);
	}
	return u;
}
int Find(int u){ int n=0;DFS(u,u,n);return Find(u,u,n);}
int go[M][26],sz[M],lo[M],cnt[M],hs[M],lvl[M],tsz,root[N];
vector<pair<int,int> > table[M];
map<int,int> idx[M];int tid;
void init()
{
	int i;
	for(i=0;i<=tsz;i++){ for(int j=0;j<26;j++) go[i][j]=0;sz[i]=lvl[i]=lo[i]=hs[i]=0;}tsz=0;
	for(i=0;i<=tid;i++) table[i].clear();tid=0;
}
int Move(int c, char w, int id)
{
	if(!go[c][w-'a'])
	{
		go[c][w-'a']=++tsz;
		lvl[tsz]=lvl[c]+1;
		if(!idx[id][lvl[tsz]]) idx[id][lvl[tsz]]=++tid;
		hs[tsz]=modulo(hs[c]+(ll)(w-'a'+1)*po[lvl[tsz]-1]%mod);
		table[idx[id][lvl[tsz]]].pb(mp(hs[tsz],tsz));
	}
	sz[go[c][w-'a']]++;
	return go[c][w-'a'];
}
void Build(int u, int p, int id, int c1, int c2)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		char w=E[u][i].second;
		if(v!=p && !vis[v]) Build(v,u,id,Move(c1,w,id),Move(c2,w,0));
	}
}
void BuildTrie(int c, int w)
{
	lo[c]=w+sz[c];int x=lo[c];cnt[c]=sz[c];
	for(int i=0;i<26;i++) if(go[c][i])
	{
		BuildTrie(go[c][i],x);
		sz[c]+=sz[go[c][i]];
		x+=sz[go[c][i]];
	}
}
pair<int,int> GetPlace(int id, int u, int v)
{
	int top=Dist(u,v),bot=1,mid;pair<int,int> ans=mp(0,root[id]);
	while(top>=bot)
	{
		mid=top+bot>>1;
		int h=GetHash(u,GetKth(u,v,mid));
		int lv=idx[id][mid];
		//if(debug) printf("mid:%i h:%i x:%i y:%i\n",mid,h,u,GetKth(u,v,mid));
		//if(debug) for(int j=0;j<table[lv].size();j++) printf("(%i %i)\n",table[lv][j].first,table[lv][j].second);
		int i=lower_bound(table[lv].begin(),table[lv].end(),mp(h,0))-table[lv].begin();
		if(i!=table[lv].size() && table[lv][i].first==h) ans=mp(mid,table[lv][i].second),bot=mid+1;
		else top=mid-1;
	}
	return ans;
}
int Count(int id, int u, int v)
{
	pair<int,int> tmp=GetPlace(id,u,v);
	int len=tmp.first;
	int nod=tmp.second;
	//if(debug) printf("u:%i v:%i id:%i len:%i nod:%i\n",u,v,id,len,nod);
	if(len==Dist(u,v)) return lo[nod]-cnt[nod];
	int sol=lo[nod];
	int at=GetKthLetter(u,v,len+1);
	for(int i=0;i<ch[at]-'a';i++) sol+=sz[go[nod][i]];
	return sol;
}
int qu[N],qv[N],sol[N];
vector<int> Qs[N];
void Solve(int u, int p, int cen, int id)
{
	int i;
	for(i=0;i<Qs[u].size();i++)
	{
		int j=Qs[u][i];
		int v=qv[j];
		int k=Compare(u,cen,u,v);
		if(k==1) sol[j]+=sz[root[0]]-sz[root[id]]+1;
		else if(k==0)
		{
			if(Dist(u,v)>Dist(u,cen))
			{
				sol[j]++;int h=GetKth(u,v,Dist(u,cen));
				sol[j]+=Count(0,h,v);
				sol[j]-=Count(id,h,v);
			}
		}
		//if(debug) printf("u:%i v:%i cen:%i sol:%i\n",u,v,cen,sol[j]);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && !vis[v]) Solve(v,u,cen,id);
	}
}
void Decompose(int u)
{
	u=Find(u);vis[u]=1;
	int i;
	init();root[0]=++tsz;idx[0].clear();
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		char w=E[u][i].second;
		if(!vis[v])
		{
			root[i+1]=++tsz;idx[i+1].clear();
			Build(v,u,i+1,Move(root[i+1],w,i+1),Move(root[0],w,0));
			BuildTrie(root[i+1],0);
		}
	}
	BuildTrie(root[0],0);
	for(i=1;i<=tid;i++) sort(table[i].begin(),table[i].end());
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(!vis[v]) Solve(v,u,u,i+1);
	}
	for(i=0;i<Qs[u].size();i++)
	{
		int j=Qs[u][i];
		int v=qv[j];
		sol[j]+=Count(0,u,v);
		//if(debug) printf("u:%i v:%i sol:%i\n",u,v,sol[j]);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(!vis[v]) Decompose(v);
	}
}
int main()
{
	preprocess();
	int n,q,i,u,v;char w;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++) scanf("%i %i %c",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	DFS(1,0,-1,0);
	for(i=1;i<=q;i++) scanf("%i %i",&qu[i],&qv[i]),Qs[qu[i]].pb(i);
	Decompose(1);
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	//if(debug) for(i=1;i<=n;i++) printf("%i fwhs:%i bwhs:%i\n",i,fwhs[i],bwhs[i]);
	if(debug) for(i=0;i<10;i++) printf("%i po:%i ip:%i\n",i,po[i],ip[i]);
	return 0;
}