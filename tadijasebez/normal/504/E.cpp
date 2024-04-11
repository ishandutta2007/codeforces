#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=300050;
const int M=2*N;
char s[M];
int tot,sa[M],id[M],fwid[N],bwid[N];
vector<pair<int,int> > Bucket[M];
bool comp(int a, int b){ return id[a]<id[b];}
void BuildSuffixArray()
{
	s[++tot]='a'+26;
	int i,j,k;
	for(i=1;i<=tot;i++) id[i]=s[i]-'a'+1,sa[i]=i;
	sort(sa+1,sa+1+tot,comp);
	for(j=0;j<20;j++)
	{
		for(i=1;i<=tot;i++)
		{
			if(sa[i]<=1<<j) continue;
			Bucket[id[sa[i]-(1<<j)]].pb(mp(sa[i]-(1<<j),id[sa[i]]));
		}
		for(i=1;i<=tot;i++)
		{
			if(sa[i]+(1<<j)>tot) Bucket[id[sa[i]]].pb(mp(sa[i],0));
		}
		int sz=0,c=0;
		for(i=0;i<=tot;i++)
		{
			for(k=0;k<Bucket[i].size();k++)
			{
				sa[++sz]=Bucket[i][k].first;
				id[sa[sz]]=c+1;
				c+=(k+1==Bucket[i].size())||(Bucket[i][k].second!=Bucket[i][k+1].second);
			}
			Bucket[i].clear();
		}
		if(c==tot) break;
	}
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int lcp[M];
void BuildLCPArray()
{
	int i,k=0,j;
	for(i=1;i<=tot;i++)
	{
		if(id[i]==tot) continue;
		j=sa[id[i]+1];
		while(max(i,j)+k<=tot && s[i+k]==s[j+k]) k++;
		lcp[id[i]]=k;
		if(k>0) k--;
	}
}
int logs[M];
void Preprocess(){ for(int i=2;i<M;i++) logs[i]=logs[i>>1]+1;}
int rmq[M][21];
void BuildSparseTable()
{
	int i,j;
	for(i=1;i<=tot;i++) rmq[i][0]=lcp[i];
	for(j=1;j<21;j++)
	{
		for(i=1;i<=tot-(1<<j)+1;i++)
		{
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
		}
	}
}
void Swap(int &a, int &b){ a^=b;b^=a;a^=b;}
int RMQ(int l, int r)
{
	l=id[l];
	r=id[r];
	if(l>r) Swap(l,r);
	if(l==r) return tot-sa[l]+1;
	r--;
	int k=logs[r-l+1];
	return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
int sz[N],dep[N],par[N][19];
vector<int> E[N];
void DFS(int u, int p)
{
	dep[u]=dep[p]+1;
	sz[u]=1;
	par[u][0]=p;
	int i;
	for(i=1;i<19;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),sz[u]+=sz[v];
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=18;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=18;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
int Chain[N];
vector<int> Head,Tail[N];
void HLD(int u, int p)
{
	if(!Chain[u])
	{
		Chain[u]=Head.size();
		Head.pb(u);
	}
	Tail[Chain[u]].pb(u);
	int i,HC=0;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && sz[v]>sz[HC]) HC=v;
	}
	if(HC)
	{
		Chain[HC]=Chain[u];
		HLD(HC,u);
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(v!=p && v!=HC) HLD(v,u);
		}
	}
}
char ch[N];
void BuildString()
{
	int i,j;
	for(i=1;i<Head.size();i++)
	{
		for(j=Tail[i].size()-1;~j;j--)
		{
			int v=Tail[i][j];
			fwid[v]=++tot;
			s[tot]=ch[v];
		}
		for(j=0;j<Tail[i].size();j++)
		{
			int v=Tail[i][j];
			bwid[v]=++tot;
			s[tot]=ch[v];
		}
	}
}
vector<pair<int,int> > Take(int u, int v)
{
	vector<pair<int,int> > ret,tmp;
	int lca=LCA(u,v),i;
	while(Chain[u]!=Chain[lca])
	{
		ret.pb(mp(fwid[u],fwid[Head[Chain[u]]]));
		u=par[Head[Chain[u]]][0];
	}
	while(Chain[v]!=Chain[lca])
	{
		tmp.pb(mp(bwid[Head[Chain[v]]],bwid[v]));
		v=par[Head[Chain[v]]][0];
	}
	if(v!=lca) ret.pb(mp(bwid[lca],bwid[v]));
	else ret.pb(mp(fwid[u],fwid[lca]));
	for(i=tmp.size()-1;~i;i--) ret.pb(tmp[i]);
	return ret;
}
int main()
{
	Head.pb(69&-69);
	int n,q,i,j,u,v,a,b,c,d,k;
	scanf("%i",&n);
	scanf("%s",ch+1);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	HLD(1,0);
	BuildString();
	BuildSuffixArray();
	BuildLCPArray();
	Preprocess();
	BuildSparseTable();
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i %i",&a,&b,&c,&d);
		if(ch[a]!=ch[c]){ printf("0\n");continue;}
		vector<pair<int,int> > tmp1,tmp2;
		tmp1=Take(a,b);
		tmp2=Take(c,d);
		i=0;j=0;
		int ans=0;
		while(i<tmp1.size() && j<tmp2.size())
		{
			int sol=RMQ(tmp1[i].first,tmp2[j].first);
			sol=min(sol,tmp1[i].second-tmp1[i].first+1);
			sol=min(sol,tmp2[j].second-tmp2[j].first+1);
			ans+=sol;
			tmp1[i].first+=sol;
			tmp2[j].first+=sol;
			bool ok=0;
			if(tmp1[i].first>tmp1[i].second) i++,ok=1;
			if(tmp2[j].first>tmp2[j].second) j++,ok=1;
			if(!ok) break;
		}
		printf("%i\n",ans);
	}
	return 0;
}