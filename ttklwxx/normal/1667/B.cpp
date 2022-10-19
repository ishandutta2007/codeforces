#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int qzh[500005],a[500005],pos[500005],rk[500005];
struct tree
{
	int l,r,maxn;
}t[2000004];
void build(int l,int r,int k)
{
	t[k].l=l;
	t[k].r=r;
	t[k].maxn=-1121131433448687LL;
	if(l==r)
	{
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y)
{
	if(t[k].l==t[k].r)
	{
		t[k].maxn=max(t[k].maxn,y);
		return;
	}
	if(x<=t[k<<1].r)change(x,k<<1,y);
	else change(x,k<<1|1,y);
	t[k].maxn=max(t[k<<1].maxn,t[k<<1|1].maxn);
}
int query(int l,int r,int k)
{
	if(t[k].l>r||t[k].r<l)return -1121131433448687LL;
	if(t[k].l>=l&&t[k].r<=r)return t[k].maxn;
	return max(query(l,r,k<<1),query(l,r,k<<1|1)); 
}
bool bi(int x,int y)
{
	return qzh[x]<qzh[y];
}
int dp[500005];
signed main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		qzh[0]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			qzh[i]=qzh[i-1]+a[i];
		}
		for(int i=0;i<=n;i++)pos[i]=i;
		build(1,n+1,1);
		sort(pos,pos+n+1,bi);
		rk[pos[0]]=1;
		for(int i=1;i<=n;i++)
		{
			if(qzh[pos[i]]==qzh[pos[i-1]])rk[pos[i]]=rk[pos[i-1]];
			else rk[pos[i]]=rk[pos[i-1]]+1;
		} 
		change(rk[0],1,0);
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0)dp[i]=dp[i-1]+1;
			else if(a[i]==0)dp[i]=dp[i-1];
			else dp[i]=dp[i-1]-1;
			dp[i]=max(dp[i],query(1,rk[i]-1,1)+i);
			change(rk[i],1,dp[i]-i);
			//printf("orz%lld %lld %lld\n",i,dp[i],rk[i]);
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}