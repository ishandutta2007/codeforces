#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int M=2*N;
pair<int,int> operator + (pair<int,int> a, int b){ return {a.first+b,a.second};}
pair<int,int> max(pair<int,int> a, pair<int,int> b){ return a>b?a:b;}
pair<int,int> mx[M];
int ls[M],rs[M],tsz,root,lzy[M];
vector<int> E[N];
int par[N],dep[N],lid[N],rid[N],tid,nod[N];
bool was[N];
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=0;
	if(ss==se){ mx[c]={dep[nod[ss]],nod[ss]};return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
void Add(int c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]+=f;mx[c]=mx[c]+f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
void DFS(int u, int p)
{
	par[u]=p;
	dep[u]=dep[p]+1;
	lid[u]=++tid;
	nod[tid]=u;
	for(int v:E[u]) if(v!=p) DFS(v,u);
	rid[u]=tid;
}
int main()
{
	int n,i,u,v,r=1;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	tid=0;
	for(i=1;i<=n;i++) if(dep[i]>dep[r]) r=i;
	DFS(r,0);
	Build(root,1,n);
	printf("1 ");
	Add(root,1,n,lid[r],rid[r],-1);
	was[r]=1;
	int ans=1;
	for(i=2;i<=n;i++)
	{
		u=mx[root].second;
		while(!was[u])
		{
			ans++;
			was[u]=1;
			Add(root,1,n,lid[u],rid[u],-1);
			u=par[u];
		}
		printf("%i ",ans);
	}
	return 0;
}