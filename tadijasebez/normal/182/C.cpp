#include <stdio.h>
#include <queue>
using namespace std;
#define ll long long
const int N=100050;
const int M=N*30*2;
const int inf=1e9+7;
int ls[M],rs[M],sz[M],root,tsz;
ll sum[M];
void Set(int &c, int ss, int se, int qi, int add, int f)
{
	if(!c) c=++tsz;
	sum[c]+=add;
	sz[c]+=f;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,add,f);
	else Set(rs[c],mid+1,se,qi,add,f);
}
ll min(ll a, ll b){ return a>b?b:a;}
ll Get(int c, int ss, int se, int k)
{
	//printf("(%i %i) %i\n",ss,se,k);
	if(!c || ss==se) return (ll)min(sz[c],k)*ss;
	int mid=ss+se>>1;
	if(sz[rs[c]]>=k) return Get(rs[c],mid+1,se,k);
	return sum[rs[c]]+Get(ls[c],ss,mid,k-sz[rs[c]]);
}
int a[N];
ll sol=0;
ll max(ll a, ll b){ return a>b?a:b;}
void run(int n, int k, int len)
{
	root=0;
	int i;ll ans=0;
	for(i=1;i<len;i++){ if(a[i]<0) Set(root,1,inf,-a[i],-a[i],1);ans+=a[i];}
	for(i=len;i<=n;i++)
	{
		if(a[i]<0) Set(root,1,inf,-a[i],-a[i],1);
		ans+=a[i];
		sol=max(sol,ans+Get(root,1,inf,k)*2);
		//printf("%i %lld\n",i,ans+Get(root,1,inf,k)*2);
		ans-=a[i-len+1];
		if(a[i-len+1]<0) Set(root,1,inf,-a[i-len+1],a[i-len+1],-1);
	}
}
int main()
{
	int n,i,k,len;
	scanf("%i %i",&n,&len);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	scanf("%i",&k);
	run(n,k,len);
	for(i=1;i<=n;i++) a[i]=-a[i];
	run(n,k,len);
	printf("%lld\n",sol);
	return 0;
}