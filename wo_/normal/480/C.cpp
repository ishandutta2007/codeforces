#include<cstdio>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

long long dp[5050][5050];

int N,A,B,K;

int main(){
	scanf("%d%d%d%d",&N,&A,&B,&K);
	A--;B--;
	dp[A][0]=1;
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j++){
			if(abs(j-B)<=1) continue;
			if(j<B){
				int d=B-j;
				int tmp=j-d+1;
				tmp=max(tmp,0);
				dp[tmp][i+1]=(dp[tmp][i+1]+dp[j][i])%mod;
				dp[B][i+1]=(dp[B][i+1]-dp[j][i])%mod;
			}else{
				int d=j-B;
				int tmp=j+d;
				dp[B+1][i+1]=(dp[B+1][i+1]+dp[j][i])%mod;
				tmp=min(tmp,N);
				dp[tmp][i+1]=(dp[tmp][i+1]-dp[j][i])%mod;
			}
		}
		for(int j=1;j<N;j++){
			dp[j][i+1]+=dp[j-1][i+1];
			dp[j][i+1]%=mod;
		}
		for(int j=0;j<N;j++){
			if(abs(j-B)<=1) continue;
			dp[j][i+1]-=dp[j][i];
			dp[j][i+1]%=mod;
		}
	}
	long long ans=0;
	for(int i=0;i<N;i++){
		ans+=dp[i][K];
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}