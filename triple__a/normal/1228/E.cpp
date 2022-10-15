#include<bits/stdc++.h>
using namespace std;

const int maxn=307;
const int mod=1e9+7;
int n,k;
long long dp[maxn][maxn],C[maxn][maxn],pwk[maxn],pwkm[maxn];

long long quick_power(long long x,long long y){
	if (x==k) return pwk[y];
	return pwkm[y];
}

long long gm(long long u){
	return (u%mod+mod)%mod;
}

void pre_calc(){
	for (int i=1;i<=n;++i){
		C[i][i]=C[i][0]=1;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	pwk[0]=pwkm[0]=1;
	for (int i=1;i<=n;++i){
		pwk[i]=(pwk[i-1]*k)%mod;
		pwkm[i]=(pwkm[i-1]*(k-1))%mod;
	}
}

int main(){
	cin>>n>>k;
	pre_calc(); 
	for (int i=1;i<=n;++i){
		dp[1][i]=(C[n][i]*quick_power(k-1,n-i))%mod;
	}
	for (int i=2;i<=n;++i){
		for (int j=1;j<=n;++j){
			long long sum=0;
			for (int r=1;r<j;++r){
				long long u=(dp[i-1][r]*C[n-r][j-r])%mod,v=(quick_power(k-1,n-j)*quick_power(k,r))%mod;
				sum+=u*v%mod;
				sum=sum%mod;
			}
			sum+=(((dp[i-1][j]*gm(quick_power(k,j)-quick_power(k-1,j)))%mod)*quick_power(k-1,n-j))%mod; 
			dp[i][j]=sum%mod;
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}