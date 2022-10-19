#include<bits/stdc++.h>
using namespace std;
const int N=400005,mod=1e9+7;
int n,m,a[N],b[N],d[N],tr[N<<2],dp[N],vis[N],p[N],s,t;
void upd(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		tr[k]=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) upd(k<<1,l,mid,x,v);
	else upd(k<<1|1,mid+1,r,x,v);
	tr[k]=(tr[k<<1]+tr[k<<1|1])%mod;
}
int ask(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return (ask(k<<1,l,mid,a,mid)+ask(k<<1|1,mid+1,r,mid+1,b))%mod;
}
void del(int x)
{
	x=abs(x);
	if(vis[x])
		return;
	vis[x]=1;
	s=(s+mod-dp[x]-1)%mod;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		d[a[i]]=i;
		d[b[i]]=-i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n*2;i++)
	{
		if(d[i]<0)
		{
			int x=-d[i];
			dp[x]=ask(1,1,n*2,a[x],b[x]);
			upd(1,1,n*2,a[x],(dp[x]+1)%mod);
		}
	}
	sort(p+1,p+m+1,[&](int x,int y){return b[x]>b[y];});
	for(int i=1;i<=n;i++)
		s=(s+dp[i]+1)%mod;
	for(int i=1,j=n*2,q=1;q<=m;q++)
	{
		int x=p[q];
		if(vis[x])
			continue;
		while(j>=b[x])
			del(d[j--]);
		t=(t+s+1)%mod;
		while(i<=a[x])
			del(d[i++]);
	}
	printf("%d\n",t);
	return 0;
}