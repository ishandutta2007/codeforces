#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=2*N;
const int S=1000;
const int K=S*2+50;
const int L=17;
vector<int> E[N];
int par[N][L],Qs[N],lim[N],add[K],id[N];
bool use[N],act[N];
int cnt[M];
void CountingSort(vector<int> &a, vector<int> &pre)
{
	int mn=N,mx=-N;
	for(int i:a) cnt[i+N]++,mx=max(mx,i),mn=min(mn,i);
	pre.clear();
	pre.pb(0);
	a.clear();
	a.pb(-N);
	for(int i=mn+N;i<=mx+N;i++) if(cnt[i])
	{
		pre.pb(pre.back()+cnt[i]);
		a.pb(i-N);
		cnt[i]=0;
	}
	a.pb(N);
	pre.pb(pre.back());
}
int lid[N],rid[N],tid,dep[N];
void DFS(int u){ lid[u]=++tid;dep[u]=dep[par[u][0]]+1;for(int v:E[u]) DFS(v);rid[u]=tid;}
bool comp(int i, int j){ return lid[i]<lid[j];}
vector<int> bl[K],pre[K];
int ptr[K];
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	for(int i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int ans=0,up[N];
int main()
{
	int n,q,i,j,u;
	scanf("%i %i",&n,&q);
	for(i=2;i<=n;i++) scanf("%i",&par[i][0]),E[par[i][0]].pb(i);
	for(j=1;j<L;j++) for(i=1;i<=n;i++) par[i][j]=par[par[i][j-1]][j-1];
	for(i=1;i<=n;i++) scanf("%i",&lim[i]),act[i]=1;
	for(i=1;i<=q;i++) scanf("%i",&Qs[i]);
	DFS(1);
	for(j=1;j<=q;j+=S)
	{
		vector<int> nod;
		for(i=1;i<=n;i++) use[i]=0;
		for(i=j;i<min(j+S,q+1);i++) if(!use[abs(Qs[i])]) nod.pb(abs(Qs[i])),use[abs(Qs[i])]=1;
		sort(nod.begin(),nod.end(),comp);
		int sz=nod.size();
		for(i=1;i<sz;i++) if(!use[LCA(nod[i-1],nod[i])]) nod.pb(LCA(nod[i-1],nod[i])),use[LCA(nod[i-1],nod[i])]=1;
		if(!use[1]) use[1]=1,nod.pb(1);
		int tsz=0;
		for(i:nod) if(i!=1)
		{
			id[i]=++tsz;
			bl[id[i]].clear();
			for(u=par[i][0];!use[u];u=par[u][0])
			{
				if(act[u]) bl[id[i]].pb(lim[u]);
			}
			CountingSort(bl[id[i]],pre[id[i]]);
			for(ptr[id[i]]=0;bl[id[i]][ptr[id[i]]+1]<0;ptr[id[i]]++);
			add[id[i]]=0;
			up[i]=u;
		}
		for(i=j;i<min(j+S,q+1);i++)
		{
			if(Qs[i]>0)
			{
				act[Qs[i]]=0;
				if(lim[Qs[i]]<0) ans--;
				for(u=Qs[i];u;u=up[u])
				{
					if(u!=Qs[i]) lim[u]--;
					if(u!=Qs[i] && act[u] && lim[u]==-1) ans++;
					if(u!=1)
					{
						add[id[u]]--;
						while(bl[id[u]][ptr[id[u]]+1]<-add[id[u]])
							ans-=pre[id[u]][ptr[id[u]]]-pre[id[u]][ptr[id[u]]+1],
							ptr[id[u]]++;
					}
				}
			}
			else
			{
				Qs[i]=-Qs[i];
				act[Qs[i]]=1;
				if(lim[Qs[i]]<0) ans++;
				for(u=Qs[i];u;u=up[u])
				{
					if(u!=Qs[i]) lim[u]++;
					if(u!=Qs[i] && act[u] && lim[u]==0) ans--;
					if(u!=1)
					{
						add[id[u]]++;
						while(bl[id[u]][ptr[id[u]]]>=-add[id[u]])
							ans-=pre[id[u]][ptr[id[u]]]-pre[id[u]][ptr[id[u]]-1],
							ptr[id[u]]--;
					}
				}
			}
			printf("%i ",ans);
		}
		for(i:nod) if(i!=1)
		{
			for(u=par[i][0];!use[u];u=par[u][0])
			{
				lim[u]+=add[id[i]];
			}
		}
		for(i=1;i<=tsz;i++) bl[i].clear(),pre[i].clear();
	}
	return 0;
}