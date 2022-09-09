#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
const int N=150050;
vector<int> E[N];
int par[N],head[N],hc[N],sz[N],lid[N],rid[N],tid,n;
void DFS(int u, int p)
{
	par[u]=p;
	sz[u]=1;
	lid[u]=++tid;
	for(int v:E[u]) if(v!=p)
	{
		DFS(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[hc[u]]) hc[u]=v;
	}
	rid[u]=tid;
}
void HLD(int u, int p)
{
	if(!head[u]) head[u]=u;
	if(hc[u]) head[hc[u]]=head[u];
	for(int v:E[u]) if(v!=p) HLD(v,u);
}
const int M=2*N;
int ls[M],rs[M],tsz,root,sum[M];
void Add(int &c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ sum[c]=add(sum[c],f);return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
}
int Get(int c, int ss, int se, int qi)
{
	if(ss==se) return sum[c];
	int mid=ss+se>>1;
	return add(sum[c],(qi<=mid?Get(ls[c],ss,mid,qi):Get(rs[c],mid+1,se,qi)));
}
int weg[N];
void Add(int u, int f)
{
	weg[u]=add(weg[u],f);
	if(hc[u]) Add(root,1,n,lid[hc[u]],rid[hc[u]],mul(f,n-sz[hc[u]]));
	if(par[u]) Add(root,1,n,1,lid[u]-1,mul(f,sz[u])),Add(root,1,n,rid[u]+1,n,mul(f,sz[u]));
}
int in;
int Get(int u)
{
	int ans=add(Get(root,1,n,lid[u]),mul(n,weg[u]));
	for(;u;u=par[head[u]]) ans=add(ans,mul(weg[par[head[u]]],n-sz[head[u]]));
	return mul(ans,in);
}
int main()
{
	int q;
	scanf("%i %i",&n,&q);
	for(int i=1,u,v;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);HLD(1,0);in=inv(n);
	while(q--)
	{
		int t,x,d;
		scanf("%i %i",&t,&x);
		if(t==1) scanf("%i",&d),Add(x,d);
		else printf("%i\n",Get(x));
	}
	return 0;
}