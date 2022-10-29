#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
//#define N 300000
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

LL n,k,rec;
LL dp[90][90][2],numsp[110],pw2[100];
int t;

int main(){
	CL(numsp);CL(dp);
	rep(i,1,100){
		numsp[i]=1+numsp[i-1]*4;
		if(numsp[i]>1e18){
			rec=i;break;
		}
	}
	pw2[0]=1;rep(i,1,rec)pw2[i]=pw2[i-1]*2;
	rep(i,1,rec)rep(j,i,rec)dp[i][j][0]=dp[i-1][j][0]+pw2[i]-1;
	rep(i,1,rec)rep(j,i,rec)dp[i][j][1]=max(i==j?numsp[j]:numsp[i+1]-dp[i+1][j][0]+dp[i][j][0],numsp[j-1]+1);
	/*
	rep(i,1,5)rep(j,1,5){
		printf("i=%d j=%d min=%lld max=%lld\n",i,j,dp[i][j][0],dp[i][j][1]);
	}*/
	
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(n>rec){
			cout<<"YES "<<n-1<<endl;continue;
		}else if(k>numsp[n]){
			cout<<"NO"<<endl;continue;
		}
		int i=1;
		while(dp[i][n][0]<=k&&i<=n){
			if(dp[i][n][0]<=k&&dp[i][n][1]>=k)break;
			++i;
		}
		if(dp[i][n][0]<=k)cout<<"YES "<<n-i<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}