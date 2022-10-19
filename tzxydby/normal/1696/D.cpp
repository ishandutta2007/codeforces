#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,a[N],st[N],tp,f[N][2];
pair<int,int>mn[N<<2],mx[N<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		mn[k]=mx[k]={a[l],l};
		return;
	}
	int md=l+r>>1;
	build(k<<1,l,md);
	build(k<<1|1,md+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
pair<int,int> askmn(int k,int l,int r,int a,int b)
{
	if(a>b) return {-1,-1};
	if(l==a&&r==b)
		return mn[k];
	int md=l+r>>1;
	if(b<=md) return askmn(k<<1,l,md,a,b);
	else if(a>md) return askmn(k<<1|1,md+1,r,a,b);
	else return min(askmn(k<<1,l,md,a,md),askmn(k<<1|1,md+1,r,md+1,b));
}
pair<int,int> askmx(int k,int l,int r,int a,int b)
{
	if(a>b) return {-1,-1};
	if(l==a&&r==b)
		return mx[k];
	int md=l+r>>1;
	if(b<=md) return askmx(k<<1,l,md,a,b);
	else if(a>md) return askmx(k<<1|1,md+1,r,a,b);
	else return max(askmx(k<<1,l,md,a,md),askmx(k<<1|1,md+1,r,md+1,b));
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	tp=0;
	st[++tp]=n;
	for(int i=n-1;i>=1;i--)
	{
		while(tp&&a[i]<a[st[tp]])
			tp--;
		int p=(tp?st[tp]-1:n);
		f[i][0]=askmx(1,1,n,i+1,p).second;
		st[++tp]=i;
	}
	tp=0;
	st[++tp]=n;
	for(int i=n-1;i>=1;i--)
	{
		while(tp&&a[i]>a[st[tp]])
			tp--;
		int p=(tp?st[tp]-1:n);
		f[i][1]=askmn(1,1,n,i+1,p).second;
		st[++tp]=i;
	}
	int ans=n+1;
	for(int d=0;d<2;d++)
	{
		int c=0,p=1,x=d;
		while(p!=n)
		{
			if(f[p][x]==-1)
			{
				c=n+1;
				break;
			}
			p=f[p][x];
			c++;
			x^=1;
		}
		ans=min(ans,c);
	}
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}