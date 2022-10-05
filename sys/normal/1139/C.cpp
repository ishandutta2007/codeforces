#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005,p=1e9+7;
int n,k,a[Maxn],b[Maxn],c[Maxn],fa[Maxn],siz[Maxn];
bool vis[Maxn]; 
int get_fa(int x)
{
	return x==fa[x]?x:fa[x]=get_fa(fa[x]);
}
void merge(int x,int y)
{
	int a=get_fa(x),b=get_fa(y);
	fa[a]=b;
	siz[b]+=siz[a];
}
long long fast_pow(long long x,long long y)
{
	long long now=x,ans=1;
	while(y)
	{
		if(y&1) ans=(ans*now)%p;
		now=(now*now)%p;
		y>>=1;
	}
	return ans;
}
long long ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(!c[i]) merge(a[i],b[i]);
	}
	for(int i=1;i<=n;i++)
		if(!vis[get_fa(i)])
		{
			vis[get_fa(i)]=true;
			ans+=fast_pow(siz[get_fa(i)],k);
			ans%=p;
		}
	printf("%lld",(fast_pow(n,k)-ans+p)%p);
	return 0;
}