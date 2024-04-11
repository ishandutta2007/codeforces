#include<iostream>
#include<cstdio>
#include<cstdlib>
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
int a[300005],fir[300005];
int dp[300005];
int f[300005],n;
void insert(int x,int k)
{
	while(x<=n)
	{
		f[x]=max(f[x],k);
		x+=((x)&(-x));
	}
}
int query(int k)
{
	int ans=-1000000000;
	while(k>=1)
	{
		ans=max(ans,f[k]);
		k-=((k)&(-k));
	}
	return ans;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)fir[i]=0,f[i]=-1000000000;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(fir[a[i]]==0)fir[a[i]]=i;
	}
	dp[1]=0;
	insert(n,-1);
	for(int i=2;i<=n;i++)
	{
	//	printf("%d %d\n",n+1-fir[a[i]],query(n+1-fir[a[i]]));
		dp[i]=max(query(n+1-fir[a[i]])+i-1,0);
		dp[i]=max(dp[i],dp[i-1]);
		insert(n+1-i,dp[i]-i);
		//printf("%d %d\n",fir[a[i]],dp[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}