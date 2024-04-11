#include<bits/stdc++.h>
using namespace std;
int n,r,f[100],s[100],p[100];
long double dp[55][10005];
bool check(long double x){
	for(int i=0;i<=r;i++)dp[n][i]=0;
	for(int i=r+1;i<=10000;i++)dp[n][i]=x;
	for(int i=n-1;i>=0;i--){
		for(int o=0;o<=r;o++){
			dp[i][o]=min(x,(dp[i+1][o+f[i+1]]+f[i+1])*p[i+1]*0.01+(s[i+1]+dp[i+1][o+s[i+1]])*(1.0-p[i+1]*0.01));
		}
		for(int o=r+1;o<=10000;o++){
			dp[i][o]=x;
		}
	}
	return dp[0][0]<x;
}
int main(){
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&f[i],&s[i],&p[i]);
	}
	int t=0;
	long double l=0,r=1e9,mid,ans=0;
	while(t<=128){
		t++;
		mid=(l+r)/2;
		if(check(mid))r=mid,ans=mid;
		else l=mid;
	}
	printf("%.9Lf",ans);
	return 0;
}