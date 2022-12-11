#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int T,nr,ng,nb;
int r[maxn],g[maxn],b[maxn];
ll ans;
ll sqr(ll x)
{
	return x*x;
}
void work(int nr,int ng,int nb,int *r,int *g,int *b)
{
	for(int i=1;i<=nr;++i)
	{
		ll x=r[i];
		int k1=lower_bound(g+1,g+ng+1,r[i])-g,t1=upper_bound(b+1,b+nb+1,r[i])-b-1;
		int k2=lower_bound(b+1,b+nb+1,r[i])-b,t2=upper_bound(g+1,g+ng+1,r[i])-g-1;
		if(1<=k1&&k1<=ng&&1<=t1&&t1<=nb)ans=min(ans,sqr(x-g[k1])+sqr(x-b[t1])+sqr(b[t1]-g[k1]));
		if(1&&k2&&k2<=nb&&1<=t2&&t2<=ng)ans=min(ans,sqr(x-b[k2])+sqr(x-g[t2])+sqr(b[k2]-g[t2]));
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&nr,&ng,&nb);
		for(int i=1;i<=nr;++i)scanf("%d",&r[i]);
		for(int i=1;i<=ng;++i)scanf("%d",&g[i]);
		for(int i=1;i<=nb;++i)scanf("%d",&b[i]);
		sort(r+1,r+nr+1);
		sort(g+1,g+ng+1);
		sort(b+1,b+nb+1);
		nr=unique(r+1,r+nr+1)-r-1;
		ng=unique(g+1,g+ng+1)-g-1;
		nb=unique(b+1,b+nb+1)-b-1; 
		ans=(ll)5e18;
		work(nr,ng,nb,r,g,b);
		work(ng,nr,nb,g,r,b);
		work(nb,nr,ng,b,r,g);
		cout<<ans<<endl;
	}
}