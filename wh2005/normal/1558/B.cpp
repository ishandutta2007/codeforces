#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 4e6+9;
int n;ll mod;
int dp[N],sum[N],S[N];


int main(){
	scanf("%d%lld",&n,&mod);
	dp[1]=1;
	for(int i=1;i<=n;i++){
		(sum[i]+=sum[i-1])%=mod;
		(dp[i]+=S[i-1])%=mod;
		(dp[i]+=sum[i])%=mod;
		for(int j=2;j*i<=n;j++){
			(sum[j*i]+=dp[i])%=mod;
			if(j*i+j<=n) (sum[j*(i+1)]+=mod-dp[i])%=mod;	
		}
		S[i]=(S[i-1]+dp[i])%mod;
	}
	printf("%d\n",dp[n]);
	return 0;
}