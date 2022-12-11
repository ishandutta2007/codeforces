#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int max_n=5000;
int dp[max_n+1][max_n+1],sum1[max_n+1][max_n+1];
void test(){
	int n,mod;
	scanf("%d%d",&n,&mod);
	dp[1][1]=1,sum1[0][1]=0,sum1[1][1]=1,sum1[1][2]=0;
	for(int i=2; i<=n; ++i){
		dp[i][1]=1,sum1[i][1]=(1+sum1[i-1][2])%mod;
		for(int j=2; j<=i; ++j){
			int now=0;
			if((j-1)*2>=i)
				now=(i-j)%mod;
			else
				now=((j-1)+sum1[i-(j-1)-j][1])%mod;
//			fprintf(stderr,"%d %d: %d\n",i,j,now);
			now=(ll(dp[j-1][j-1])*now+dp[i][j-1])%mod;
//			fprintf(stderr,"%d %d: %d\n",i,j,now);
			dp[i][j]=now;
			sum1[i][j]=now+(j<=i-2?sum1[i-1][j+1]:0);
			if(sum1[i][j]>=mod)
				sum1[i][j]-=mod;
		}
	}
	printf("%d\n",dp[n][n]);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}