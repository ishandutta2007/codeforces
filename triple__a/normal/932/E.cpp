#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long LL;

const int mod=1e9+7;

const int maxm=5007;

LL dp[maxm][maxm];

int qp(int n,int k){
	if (k<0) return 0;
	LL ans=1,u=n;
	while (k){
		if (k&1){
			ans=(ans*u)%mod;
		}
		u=(u*u)%mod;
		k>>=1;
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	for (int i=0;i<=k;++i){
		dp[i][0]=qp(2,n-i);
	}
	for (int i=1;i<=k;++i){
		for (int j=0;j<=k-i;++j){
			dp[j][i]=((n-j)*dp[j+1][i-1]+j*dp[j][i-1])%mod; 
		}
	}
	cout<<dp[0][k]<<endl;
	return 0;	
}