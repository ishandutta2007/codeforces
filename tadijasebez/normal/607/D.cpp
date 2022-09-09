#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int mod=1e9+7;
const int N=200050;
const int M=2*N;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return pow(x,mod-2);}
vector<int> E[N];
int lid[N],rid[N],tid,deg[N];
void DFS(int u)
{
	lid[u]=++tid;
	for(int v:E[u]) DFS(v);
	rid[u]=tid;
}
int ls[M],rs[M],tsz,root,lzy_mul[M],lzy_add[M],sum[M];
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy_mul[c]=1;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Push(int c)
{
	if(lzy_mul[c]==1) return;
	sum[ls[c]]=mul(sum[ls[c]],lzy_mul[c]);
	lzy_mul[ls[c]]=mul(lzy_mul[ls[c]],lzy_mul[c]);
	sum[rs[c]]=mul(sum[rs[c]],lzy_mul[c]);
	lzy_mul[rs[c]]=mul(lzy_mul[rs[c]],lzy_mul[c]);
	lzy_mul[c]=1;
}
void Mul(int c, int ss, int se, int qs, int qe, int f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ sum[c]=mul(sum[c],f);lzy_mul[c]=mul(lzy_mul[c],f);return;}
	int mid=ss+se>>1;
	Push(c);
	Mul(ls[c],ss,mid,qs,qe,f);
	Mul(rs[c],mid+1,se,qs,qe,f);
	sum[c]=add(sum[ls[c]],sum[rs[c]]);
}
void Set(int c, int ss, int se, int qi, int f)
{
	if(ss==se){ lzy_add[c]=f;sum[c]=mul(lzy_add[c],lzy_mul[c]);return;}
	int mid=ss+se>>1;
	Push(c);
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
	sum[c]=add(sum[ls[c]],sum[rs[c]]);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	Push(c);
	return add(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int GetMul(int c, int ss, int se, int qi)
{
	if(ss==se) return lzy_mul[c];
	int mid=ss+se>>1;
	Push(c);
	if(qi<=mid) return GetMul(ls[c],ss,mid,qi);
	else return GetMul(rs[c],mid+1,se,qi);
}
int main()
{
	vector<pair<int,pair<int,int>>> Qs;
	int q,v1;
	scanf("%i %i",&v1,&q);
	int n=1;
	while(q--)
	{
		int t,u,v;
		scanf("%i %i",&t,&u);
		if(t==1) scanf("%i",&v),n++,E[u].pb(n);
		Qs.pb(mp(t,mp(u,v)));
	}
	int lim=n;
	DFS(1);
	Build(root,1,lim);
	for(int i=1;i<=n;i++) deg[i]=1;
	n=1;
	Set(root,1,lim,lid[1],v1);
	for(auto Q:Qs)
	{
		int t=Q.first,u=Q.second.first,v=Q.second.second;
		if(t==1)
		{
			n++;
			Mul(root,1,lim,lid[u],rid[u],inv(deg[u]));
			deg[u]++;
			Mul(root,1,lim,lid[u],rid[u],deg[u]);
			Set(root,1,lim,lid[n],v);
		}
		else
		{
			int ml=mul(GetMul(root,1,lim,lid[u]),inv(deg[u]));
			int sm=Get(root,1,lim,lid[u],rid[u]);
			sm=mul(sm,inv(ml));
			printf("%i\n",sm);
		}
	}
	return 0;
}