#include<iostream>
#include<cstdio>
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
int qz[800001],dp[800001][2];
int f[800001];
struct tree
{
	int l,r,maxn1,maxn2;
}a[1200004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	a[k].maxn1=-100000000;
	a[k].maxn2=-100000000;
	if(l==r)return;
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
}
void change(int x,int k,int y,int z)
{
	if(a[k].l==a[k].r)
	{
		a[k].maxn1=y;
		a[k].maxn2=z;
		return;
	}
	if(x<=a[k<<1].r)change(x,k<<1,y,z);
	else change(x,k<<1|1,y,z);
	a[k].maxn1=max(a[k<<1].maxn1,a[k<<1|1].maxn1);
	a[k].maxn2=max(a[k<<1].maxn2,a[k<<1|1].maxn2);
}
int query1(int l,int r,int k)
{
	if(a[k].l>r||a[k].r<l)return -1000000000;
	if(a[k].l>=l&&a[k].r<=r)return a[k].maxn1;
	return max(query1(l,r,k<<1),query1(l,r,k<<1|1));
}
int query2(int l,int r,int k)
{
	if(a[k].l>r||a[k].r<l)return -1000000000;
	if(a[k].l>=l&&a[k].r<=r)return a[k].maxn2;
	return max(query2(l,r,k<<1),query2(l,r,k<<1|1));
}
signed main()
{
	int t,n,q;
	int ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		for(int i=1;i<=n;i++)qz[i]=read();
		build(1,n,1);
		dp[1][0]=qz[1];
		dp[1][1]=-100000000;
		change(1,1,qz[1],-1000000000);
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=max(query2(1,i-1,1),0LL)+qz[i];
			dp[i][1]=query1(1,i-1,1)-qz[i];
			change(i,1,dp[i][0],dp[i][1]);
		}
		ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,dp[i][0]);
		printf("%lld\n",ans);
	} 
	return 0;
}