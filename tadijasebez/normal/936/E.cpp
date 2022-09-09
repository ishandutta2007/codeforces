#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=300050;
const int M=2*N;
const int L=20;
const int inf=1e9+7;
vector<int> E[N];
struct pt{ int x,y;bool operator < (pt b) const { return mp(x,y)<mp(b.x,b.y);}};
pt ps[N];
struct seg{ int x,y1,y2,id;} S[N];
void AddEdge(int u, int v){ E[u].pb(v);E[v].pb(u);}
int cen[N][L],h[N][L],dst[N][L],dep[N],my[N];
bool was[N];
int sz[N];
void DFS(int u, int p){ sz[u]=1;for(int v:E[u]) if(v!=p && !was[v]) DFS(v,u),sz[u]+=sz[v];}
int Find(int u, int p, int n){ for(int v:E[u]) if(v!=p && !was[v] && sz[v]*2>n) return Find(v,u,n);return u;}
int Find(int u){ DFS(u,u);return Find(u,u,sz[u]);}
void Solve(int u, int p, int c, int lvl)
{
	int lid=S[u].id,rid=S[u].id+S[u].y2-S[u].y1;
	for(int v:E[u]) if(v!=p && !was[v])
	{
		for(int i=0;i<=S[v].y2-S[v].y1;i++)
		{
			int y=S[v].y1+i,id=S[v].id+i;
			cen[id][lvl]=c;
			if(y<S[u].y1) h[id][lvl]=h[lid][lvl],dst[id][lvl]=dst[lid][lvl]+1+S[u].y1-y;
			else if(y>S[u].y2) h[id][lvl]=h[rid][lvl],dst[id][lvl]=dst[rid][lvl]+1+y-S[u].y2;
			else h[id][lvl]=h[lid+y-S[u].y1][lvl],dst[id][lvl]=dst[lid+y-S[u].y1][lvl]+1;
		}
		Solve(v,u,c,lvl);
	}
}
void Decompose(int u, int lvl)
{
	u=Find(u);was[u]=1;dep[u]=lvl;
	for(int i=0;i<=S[u].y2-S[u].y1;i++)
	{
		cen[S[u].id+i][lvl]=u;
		h[S[u].id+i][lvl]=i;
		dst[S[u].id+i][lvl]=0;
	}
	Solve(u,u,u,lvl);
	for(int v:E[u]) if(!was[v]) Decompose(v,lvl+1);
}
int ls[M],rs[M],lo[M],hi[M],root[N],tsz;
void SetLo(int &c, int ss, int se, int qs, int qe, int val)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz,lo[c]=hi[c]=inf;
	if(qs<=ss && qe>=se){ lo[c]=min(lo[c],val);return;}
	int mid=ss+se>>1;
	SetLo(ls[c],ss,mid,qs,qe,val);
	SetLo(rs[c],mid+1,se,qs,qe,val);
}
void SetHi(int &c, int ss, int se, int qs, int qe, int val)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz,lo[c]=hi[c]=inf;
	if(qs<=ss && qe>=se){ hi[c]=min(hi[c],val);return;}
	int mid=ss+se>>1;
	SetHi(ls[c],ss,mid,qs,qe,val);
	SetHi(rs[c],mid+1,se,qs,qe,val);
}
void Set(int u, int ss, int se, int dst, int h)
{
	SetLo(root[u],ss,se,ss,h,dst+h);
	SetHi(root[u],ss,se,h,se,dst-h);
}
int Get(int c, int ss, int se, int qi)
{
	int ans=min(lo[c]-qi,hi[c]+qi);
	if(ss==se) return ans;
	int mid=ss+se>>1;
	if(qi<=mid) return min(ans,Get(ls[c],ss,mid,qi));
	else return min(ans,Get(rs[c],mid+1,se,qi));
}
int main()
{
	hi[0]=lo[0]=inf;
	int n,q;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i %i",&ps[i].x,&ps[i].y);
	sort(ps+1,ps+1+n);
	map<pt,int> idx;
	int sz=0;
	for(int i=1;i<=n;i++) idx[ps[i]]=i;
	for(int i=1,j;i<=n;i=j)
	{
		sz++;
		for(j=i;j<=n && ps[i].x==ps[j].x && ps[i].y+j-i==ps[j].y;j++) my[j]=sz;
		S[sz]={ps[i].x,ps[i].y,ps[j-1].y,i};
	}
	for(int i=1,j=1;i<=sz;i++)
	{
		while(S[j].x<S[i].x-1) j++;
		while(S[j].x==S[i].x-1 && S[j].y2<S[i].y1) j++;
		while(S[j].x==S[i].x-1 && S[j].y1<=S[i].y2) AddEdge(j,i),j++;
		if(j>1) j--;
	}
	Decompose(1,1);
	scanf("%i",&q);
	int t;pt p;
	while(q--)
	{
		scanf("%i %i %i",&t,&p.x,&p.y);
		int id=idx[p];
		if(t==1)
		{
			for(int i=1;i<=dep[my[id]];i++)
			{
				int c=cen[id][i];
				Set(c,0,S[c].y2-S[c].y1,dst[id][i],h[id][i]);
			}
		}
		else
		{
			int ans=inf;
			for(int i=1;i<=dep[my[id]];i++)
			{
				int c=cen[id][i];
				ans=min(ans,dst[id][i]+Get(root[c],0,S[c].y2-S[c].y1,h[id][i]));
			}
			if(ans<inf/2) printf("%i\n",ans);
			else printf("-1\n");
		}
	}
	return 0;
}