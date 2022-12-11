#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k; 
const int N=5e5+5;
const int M=5e5+5;
const int p=998244353;
int l[M],r[M],x[M];
int mark[N],Left[N];
int dp[N],sum[N];
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++) scanf("%d%d%d",l+i,r+i,x+i);
	int ans=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n+1;j++) mark[j]=Left[j]=0;
		for(int j=1;j<=m;j++)
		{
			if(x[j]&(1<<i-1)) mark[l[j]]++,mark[r[j]+1]--;
			else Left[r[j]+1]=max(Left[r[j]+1],l[j]);
		}
		for(int j=1;j<=n+1;j++)
		{
			mark[j]+=mark[j-1];
			Left[j]=max(Left[j],Left[j-1]);
		}
		dp[0]=sum[0]=1;
		for(int j=1;j<=n+1;j++)
		{
			int L=Left[j],R=j-1;
			dp[j]=mark[j]<=0&&L<=R?(sum[R]-sum[L-1])%p:0;
			sum[j]=(sum[j-1]+dp[j])%p;
		}
		ans=1ll*ans*dp[n+1]%p;
	}
	printf("%d",(ans%p+p)%p);
	return 0;
}