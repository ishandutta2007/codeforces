#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
#define N 2005

int n,k;
char s[N];

int dp[4][N],sum[2][N][N],tmp,ans;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		dp[0][i]=dp[1][i]=inf;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++)
			if(s[j]=='B'){
				dp[0][i]=std::min(dp[0][i],j);
				dp[1][j]=std::min(dp[1][j],i);
				dp[2][i]=std::max(dp[2][i],j);
				dp[3][j]=std::max(dp[3][j],i);
			}
	}
	for(int opt=0;opt<=1;opt++)
		for(int i=1;i<=n;i++)
			if(dp[opt][i]==inf)
				tmp++;
			else
				for(int j=dp[opt+2][i]-k+1;j<=dp[opt][i];j++)
					sum[opt][i][j]=1;
	for(int opt=0;opt<=1;opt++)
		for(int i=2;i<=n;i++)
			for(int j=1;j<=n;j++)
				sum[opt][i][j]+=sum[opt][i-1][j];
	for(int i=1;i<=n-k+1;i++)
		for(int j=1;j<=n-k+1;j++)
			ans=std::max(ans,sum[0][i+k-1][j]-sum[0][i-1][j]+sum[1][j+k-1][i]-sum[1][j-1][i]);
	printf("%d",ans+tmp);
}