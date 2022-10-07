#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
using namespace std;
struct Tree
{
	ll maxv[80005];
	void pushup(int x)
	{
		maxv[x]=max(maxv[lc],maxv[rc]);
	}
	void update(int x,int l,int r,int p,ll v)
	{
		if(l==r)
		{
			maxv[x]=v;
			return;
		}
		if(p<=mid)update(lc,l,mid,p,v);
		else update(rc,mid+1,r,p,v);
		pushup(x);
	}
	ll ask(int x,int l,int r,int from,int to)
	{
		if(from>to)return -1e12;
		if(l>=from&&r<=to)return maxv[x];
		ll ans=-1e12;
		if(from<=mid)ans=max(ans,ask(lc,l,mid,from,to));
		if(to>mid)ans=max(ans,ask(rc,mid+1,r,from,to));
		return ans;
	}
};
Tree t1,t2,t3;
int n,m,l;
ll a[55][20005],s[55][20005],f[20005];
int main()
{
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    s[i][j]=s[i][j-1]+a[i][j];
	for(int i=1;i<=80000;i++)
	  t1.maxv[i]=t2.maxv[i]=t3.maxv[i]=-1e12;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+l-1<=m;j++)
		{
			f[j]=max(t1.ask(1,1,m,1,j-l),t1.ask(1,1,m,j+l,m));
			f[j]=max(f[j],t2.ask(1,1,m,j-l+1,j)+s[i][j-1]);
			f[j]=max(f[j],t3.ask(1,1,m,j+1,j+l)-s[i][j+l-1]);
			f[j]=max(f[j],0ll);
		}
		for(int j=1;j+l-1<=m;j++)
		{
			f[j]=f[j]+s[i][j+l-1]-s[i][j-1]+s[i+1][j+l-1]-s[i+1][j-1];
			t1.update(1,1,m,j,f[j]);
			t2.update(1,1,m,j,f[j]-s[i+1][j+l-1]);
			t3.update(1,1,m,j,f[j]+s[i+1][j-1]);
		}
	}
	printf("%lld\n",t1.ask(1,1,n,1,n));
	return 0;
}