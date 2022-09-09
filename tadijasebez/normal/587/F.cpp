#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=100050;
const int S=317;
vector<int> nodes[N];
char s[N];
int go[N][26],root,tsz,link[N],x[N],lid[N],rid[N],tid;
void Add(int &c, int lvl, int sz, int id)
{
	if(!c) c=++tsz;
	nodes[id].pb(c);
	if(lvl>=sz) return;
	Add(go[c][s[lvl]-'a'],lvl+1,sz,id);
}
vector<int> E[N];
void DFSID(int u){ lid[u]=++tid;for(int i=0;i<E[u].size();i++) DFSID(E[u][i]);rid[u]=tid;}
void Build()
{
	queue<int> q;
	int i;link[1]=1;
	for(i=0;i<26;i++)
	{
		if(go[1][i])
		{
			link[go[1][i]]=1;
			q.push(go[1][i]);
		}
		else go[1][i]=1;
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(i=0;i<26;i++)
		{
			if(go[u][i])
			{
				link[go[u][i]]=go[link[u]][i];
				q.push(go[u][i]);
			}
			else go[u][i]=go[link[u]][i];
		}
	}
	for(i=2;i<=tsz;i++) E[link[i]].pb(i);
	DFSID(1);
}
int l[N],r[N],k[N],n;
ll sol[N];
vector<int> Heavy[N],Light;
void Init(){ for(int i=1;i<=tsz;i++) x[i]=0;}
void DFS(int u){ for(int i=0;i<E[u].size();i++) DFS(E[u][i]),x[u]+=x[E[u][i]];}
vector<pair<int,int> > events[N];
void SolveHeavy(int u)
{
	int i,j;Init();
	for(i=0;i<nodes[u].size();i++) x[nodes[u][i]]++;
	DFS(1);for(i=0;i<=n;i++) events[i].clear();
	for(i=0;i<Heavy[u].size();i++)
	{
		int id=Heavy[u][i];
		events[l[id]-1].pb(mp(id,-1));
		events[r[id]].pb(mp(id,1));
	}
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=x[nodes[i].back()];
		for(j=0;j<events[i].size();j++)
		{
			int id=events[i][j].first;
			int f=events[i][j].second;
			sol[id]+=sum*f;
		}
	}
}
struct RMQ
{
	ll a[N],Block[N];
	RMQ(){}
	void Init(){ for(int i=0;i<N;i++) a[i]=Block[i]=0;}
	void Set(int l, int r, int x)
	{
		int L=l/S,i;
		int R=r/S;
		if(L==R) for(i=l;i<=r;i++) a[i]+=x;
		else
		{
			for(i=l;i<(L+1)*S;i++) a[i]+=x;
			for(i=L+1;i<R;i++) Block[i]+=x;
			for(i=R*S;i<=r;i++) a[i]+=x;
		}
	}
	ll Get(int x){ return a[x]+Block[x/S];}
} RMQ;
void SolveLight()
{
	int i,j,o;RMQ.Init();
	for(i=0;i<=n;i++) events[i].clear();
	for(i=0;i<Light.size();i++)
	{
		int id=Light[i];
		events[l[id]-1].pb(mp(id,-1));
		events[r[id]].pb(mp(id,1));
	}
	for(i=1;i<=n;i++)
	{
		RMQ.Set(lid[nodes[i].back()],rid[nodes[i].back()],1);
		for(j=0;j<events[i].size();j++)
		{
			int id=events[i][j].first;
			int f=events[i][j].second;
			for(o=0;o<nodes[k[id]].size();o++)
			{
				sol[id]+=f*RMQ.Get(lid[nodes[k[id]][o]]);
			}
		}
	}
}
int main()
{
	int q,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		Add(root,0,strlen(s),i);
	}
	Build();
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&l[i],&r[i],&k[i]);
		if(nodes[k[i]].size()>S) Heavy[k[i]].pb(i);
		else Light.pb(i);
	}
	for(i=1;i<=n;i++) if(Heavy[i].size()) SolveHeavy(i);
	SolveLight();
	for(i=1;i<=q;i++) printf("%lld\n",sol[i]);
	return 0;
}