#include<iostream>
#include<cstdio>
#define mod 998244353
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
int dp[200005],zh[200005];
int ndp[200005];
int qans[200005];
int main()
{
	int n,k,het=0;
	n=read();
	k=read();
	dp[0]=1;
	for(int i=0;;i++)
	{
		het+=(k+i);
		if(het>n)break;
		for(int j=0;j<=n;j++)ndp[j]=0;
		for(int j=k+i;j<=n;j++)ndp[j]=((ndp[j]+ndp[j-k-i])%mod+dp[j-k-i])%mod;
		for(int j=0;j<=n;j++)dp[j]=ndp[j],qans[j]=(qans[j]+dp[j])%mod;
	}
	for(int i=1;i<=n;i++)printf("%d ",qans[i]);
	printf("\n");
	return 0;
}