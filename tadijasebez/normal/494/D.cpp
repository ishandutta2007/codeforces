#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=6*N;
const int mod=1e9+7;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
int sum_1[N],sum_2[N],lid[N],rid[N],tid,dfn[N],dep[N],n;
vector<pair<int,int>> E[N];
void DFS(int u, int p)
{
	lid[u]=++tid;
	dfn[tid]=u;
	sum_1[tid]=add(sum_1[tid-1],dep[u]);
	sum_2[tid]=add(sum_2[tid-1],mul(dep[u],dep[u]));
	for(auto e:E[u]) if(e.first!=p) dep[e.first]=add(dep[u],e.second),DFS(e.first,u);
	rid[u]=tid;
}
int root[3],tsz,ls[M],rs[M],sum[M],lzy_mul[M],lzy[M];
bool persistent;
struct Node{ int c,sum,lzy_mul,lzy;};
vector<Node> bck;
void upd(int c, int ss, int se, int x)
{
	if(persistent) bck.pb({c,sum[c],lzy_mul[c],lzy[c]});
	sum[c]=mul(x,se-ss+1);lzy[c]=x;lzy_mul[c]=1;
}
void upd_mul(int c, int x)
{
	if(persistent) bck.pb({c,sum[c],lzy_mul[c],lzy[c]});
	sum[c]=mul(sum[c],x);
	if(lzy[c]!=-1) lzy[c]=mul(lzy[c],x);
	else lzy_mul[c]=mul(lzy_mul[c],x);
}
void push(int c, int ss, int se)
{
	if(!ls[c]) ls[c]=++tsz,lzy[ls[c]]=-1,lzy_mul[ls[c]]=1;
	if(!rs[c]) rs[c]=++tsz,lzy[rs[c]]=-1,lzy_mul[rs[c]]=1;
	if(lzy_mul[c]!=1)
	{
		if(persistent) bck.pb({c,sum[c],lzy_mul[c],lzy[c]});
		upd_mul(ls[c],lzy_mul[c]);
		upd_mul(rs[c],lzy_mul[c]);
		lzy_mul[c]=1;
	}
	if(lzy[c]!=-1)
	{
		if(persistent) bck.pb({c,sum[c],lzy_mul[c],lzy[c]});
		int mid=ss+se>>1;
		upd(ls[c],ss,mid,lzy[c]);
		upd(rs[c],mid+1,se,lzy[c]);
		lzy[c]=-1;
	}
}
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz,lzy_mul[c]=1,lzy[c]=-1;
	if(qs<=ss && qe>=se){ upd(c,ss,se,val);return;}
	push(c,ss,se);
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	if(persistent) bck.pb({c,sum[c],lzy_mul[c],lzy[c]});
	sum[c]=add(sum[ls[c]],sum[rs[c]]);
}
void Mul(int &c, int ss, int se, int qs, int qe, int val)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz,lzy_mul[c]=1,lzy[c]=-1;
	if(qs<=ss && qe>=se){ upd_mul(c,val);return;}
	push(c,ss,se);
	int mid=ss+se>>1;
	Mul(ls[c],ss,mid,qs,qe,val);
	Mul(rs[c],mid+1,se,qs,qe,val);
	if(persistent) bck.pb({c,sum[c],lzy_mul[c],lzy[c]});
	sum[c]=add(sum[ls[c]],sum[rs[c]]);
}
int Get(int &c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(!c) c=++tsz,lzy_mul[c]=1,lzy[c]=-1;
	if(qs<=ss && qe>=se) return sum[c];
	push(c,ss,se);
	int mid=ss+se>>1;
	return add(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
void Back(int sz)
{
	while(bck.size()>sz)
	{
		sum[bck.back().c]=bck.back().sum;
		lzy_mul[bck.back().c]=bck.back().lzy_mul;
		lzy[bck.back().c]=bck.back().lzy;
		bck.pop_back();
	}
}
vector<int> Qs[N];
int a[N],b[N],ans[N];
int Solve(int u, int l, int r)
{
	if(l>r) return 0;
	int ans=mul(mul(dep[u],dep[u]),r-l+1);
	//printf("%i ",ans);
	ans=add(ans,sub(sum_2[r],sum_2[l-1]));
	//printf("%i ",ans);
	int lca_2=Get(root[0],1,n,l,r);
	ans=add(ans,mul(4,lca_2));
	//printf("%i ",ans);
	int dep_v=sub(sum_1[r],sum_1[l-1]);
	ans=add(ans,mul(2,mul(dep_v,dep[u])));
	//printf("%i ",ans);
	int lca=Get(root[1],1,n,l,r);
	ans=add(ans,mul(sub(0,4),mul(lca,dep[u])));
	//printf("%i ",ans);
	ans=add(ans,mul(sub(0,4),Get(root[2],1,n,l,r)));
	//printf("%i (%i %i) %i\n",u,l,r,ans);
	return ans;
}
void Solve(int u, int p)
{
	Set(root[0],1,n,lid[u],rid[u],mul(dep[u],dep[u]));
	Set(root[1],1,n,lid[u],rid[u],dep[u]);
	int sz=bck.size();
	persistent=1;
	Mul(root[2],1,n,lid[u],rid[u],dep[u]);
	for(int i:Qs[u])
	{
		ans[i]=sub(sub(Solve(u,lid[b[i]],rid[b[i]]),Solve(u,1,lid[b[i]]-1)),Solve(u,rid[b[i]]+1,n));
	}
	//printf("Solve %i\n",u);
	//for(int i=1;i<=n;i++) printf("%i ",Get(root[0],1,n,i,i));printf("\n");
	//for(int i=1;i<=n;i++) printf("%i ",Get(root[1],1,n,i,i));printf("\n");
	//for(int i=1;i<=n;i++) printf("%i ",Get(root[2],1,n,i,i));printf("\n");
	persistent=0;
	for(auto e:E[u]) if(e.first!=p)
	{
		int v=e.first;
		Back(sz);
		persistent=1;
		Mul(root[2],1,n,lid[u],lid[v]-1,dep[u]);
		Mul(root[2],1,n,rid[v]+1,rid[u],dep[u]);
		persistent=0;
		Solve(v,u);
		Set(root[0],1,n,lid[v],rid[v],mul(dep[u],dep[u]));
		Set(root[1],1,n,lid[v],rid[v],dep[u]);
	}
	Back(sz);
	//if(u==1)
	//{
	//	printf("Before %i\n",u);
	//	for(int i=1;i<=n;i++) printf("%i ",Get(root[0],1,n,i,i));printf("\n");
	//	for(int i=1;i<=n;i++) printf("%i ",Get(root[1],1,n,i,i));printf("\n");
	//	for(int i=1;i<=n;i++) printf("%i ",Get(root[2],1,n,i,i));printf("\n");
	//}
	//Mul(root[2],1,n,lid[u],rid[u],mul(inv(dep[u]),p?inv(dep[p]):1));
}
int main()
{
	int u,v,w,q;
	scanf("%i",&n);
	for(int i=1;i<n;i++) scanf("%i %i %i",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	DFS(1,0);
	for(int i=1;i<=n;i++) Set(root[2],1,n,lid[i],lid[i],dep[i]);
	//for(int i=1;i<=n;i++) printf("%i ",Get(root[0],1,n,i,i));printf("\n");
	//for(int i=1;i<=n;i++) printf("%i ",Get(root[1],1,n,i,i));printf("\n");
	//for(int i=1;i<=n;i++) printf("%i ",Get(root[2],1,n,i,i));printf("\n");
	scanf("%i",&q);
	for(int i=1;i<=q;i++) scanf("%i %i",&a[i],&b[i]),Qs[a[i]].pb(i);
	Solve(1,0);
	for(int i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}