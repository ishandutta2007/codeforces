#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long dp[2020][2020];
long long sum[2020][2020];

char ch[2020];
int K;
int N;

long long solve(){
	for(int i=0;i<2020;i++) for(int j=0;j<2020;j++){
		dp[i][j]=0;
		sum[i][j]=0;
	}
	dp[0][0]=1;
	sum[0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<2020;j++){
			int coe_la=26-(ch[i]-'a')-1;
			int coe_sm=ch[i]-'a';
			int t=N-i;
			for(int k=1;i-k+1>=0&&j-k*t>=0;k++){
				long long prv=dp[i-k+1][j-k*t];
				dp[i+1][j]+=prv*coe_la;
				dp[i+1][j]%=mod;
			}
			dp[i+1][j]+=sum[i][j]*coe_sm;
			dp[i+1][j]%=mod;
			
			sum[i+1][j]=sum[i][j]+dp[i+1][j];
			sum[i+1][j]%=mod;
		}
	}
	return sum[N][K];
}

int main(){
	scanf("%d%d",&N,&K);
	scanf("%s",ch);
	long long ans=solve();
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}