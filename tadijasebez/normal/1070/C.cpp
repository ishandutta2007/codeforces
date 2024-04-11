#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
const int M=2*N;
const ll inf=1e15+7;
ll sum[M],lzy[M];
int id[M],ls[M],rs[M],tsz,root;
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=sum[c]=0;id[c]=ss;
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ lzy[c]+=f;sum[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	sum[c]=max(sum[ls[c]],sum[rs[c]])+lzy[c];
	if(sum[c]==sum[ls[c]]+lzy[c]) id[c]=id[ls[c]];
	else id[c]=id[rs[c]];
}
struct BIT
{
	ll sum[N];
	void init(){ for(int i=0;i<N;i++) sum[i]=0;}
	BIT(){ init();}
	void Set(int i, ll f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	void Set(int l, int r, ll f){ Set(l,f);Set(r+1,-f);}
	ll Get(int i){ ll ret=0;for(;i;i-=i&-i) ret+=sum[i];return ret;}
} BT;
int l[N],r[N],c[N],p[N],ord[N];
bool comp(int i, int j){ return p[i]<p[j];}
bool done[N];
int main()
{
	int n,k,m,i,j;
	scanf("%i %i %i",&n,&k,&m);
	Build(root,1,n);
	for(i=1;i<=m;i++) scanf("%i %i %i %i",&l[i],&r[i],&c[i],&p[i]),ord[i]=i;
	sort(ord+1,ord+1+m,comp);
	ll ans=0;
	for(j=1;j<=m;j++)
	{
		i=ord[j];
		BT.Set(l[i],r[i],(ll)c[i]*p[i]);
		Add(root,1,n,l[i],r[i],c[i]);
		while(sum[root]>=k)
		{
            int x=id[root];
			ans+=BT.Get(x)-(ll)p[i]*(sum[root]-k);
			Add(root,1,n,x,x,-inf);
			done[x]=1;
		}
	}
	for(i=1;i<=n;i++) if(!done[i]) ans+=BT.Get(i);
	printf("%lld\n",ans);
	return 0;
}