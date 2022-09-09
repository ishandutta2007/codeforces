#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=50050;
const int M=2*N;
const int K=800050;
const int S=600;
bool on[N],heavy[N];
int sol[N],deg[N],mx[N];
vector<pair<int,int> > edges;
vector<pair<char,pair<int,int> > > Qs;
int E[N],H[N];
int fir[M],nxt[K],prv[K],f[K],tsz,rsz;
map<int,int> id[M];
void Add(int &c, int x)
{
	if(!c) c=++rsz;
	tsz++;
	if(fir[c]) prv[fir[c]]=tsz;
	nxt[tsz]=fir[c];
	f[tsz]=x;
	fir[c]=tsz;
	id[c][x]=tsz;
}
void Del(int c, int x)
{
	int tmp=id[c][x];
	if(prv[tmp]) nxt[prv[tmp]]=nxt[tmp];
	if(nxt[tmp]) prv[nxt[tmp]]=prv[tmp];
	if(fir[c]==tmp) fir[c]=nxt[tmp];
}
void AddEdge(int u, int v)
{
	Add(E[u],v);
	Add(E[v],u);
	if(heavy[u]){ Add(H[v],u);if(on[v]) sol[u]++;}
	if(heavy[v]){ Add(H[u],v);if(on[u]) sol[v]++;}
}
void DelEdge(int u, int v)
{
	Del(E[u],v);
	Del(E[v],u);
	if(heavy[u]){ Del(H[v],u);if(on[v]) sol[u]--;}
	if(heavy[v]){ Del(H[u],v);if(on[u]) sol[v]--;}
}
void Off(int u)
{
	on[u]=0;
	for(int i=fir[H[u]];i;i=nxt[i]) sol[f[i]]--;
}
void On(int u)
{
	on[u]=1;
	for(int i=fir[H[u]];i;i=nxt[i]) sol[f[i]]++;
}
int Get(int u)
{
	if(heavy[u]) return sol[u];
	int ans=0;
	for(int i=fir[E[u]];i;i=nxt[i]) ans+=on[f[i]];
	return ans;
}
int main()
{
	int n,m,q,o,i,x,y;char t;
	scanf("%i %i %i",&n,&m,&q);
	scanf("%i",&o);while(o--) scanf("%i",&x),on[x]=1;
	while(m--) scanf("%i %i",&x,&y),deg[x]++,deg[y]++,edges.pb(mp(x,y));
	for(i=1;i<=n;i++) mx[i]=deg[i];
	while(q--)
	{
		scanf("\n%c",&t);
		if(t=='O') scanf("%i",&x);
		if(t=='F') scanf("%i",&x);
		if(t=='A') scanf("%i %i",&x,&y),deg[x]++,deg[y]++,mx[x]=max(mx[x],deg[x]),mx[y]=max(mx[y],deg[y]);
		if(t=='D') scanf("%i %i",&x,&y),deg[x]--,deg[y]--;
		if(t=='C') scanf("%i",&x);
		Qs.pb(mp(t,mp(x,y)));
	}
	for(i=1;i<=n;i++) if(mx[i]>=S) heavy[i]=1;
	for(auto p:edges) AddEdge(p.first,p.second);
	for(auto p:Qs)
	{
		if(p.first=='O') On(p.second.first);
		if(p.first=='F') Off(p.second.first);
		if(p.first=='A') AddEdge(p.second.first,p.second.second);
		if(p.first=='D') DelEdge(p.second.first,p.second.second);
		if(p.first=='C') printf("%i\n",Get(p.second.first));
	}
	return 0;
}