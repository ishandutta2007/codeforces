// author: xay5421
// created: Mon Oct  4 21:40:18 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
const int N=10005,INF=0X3F3F3F3F;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		vector<int>a(n);
		rep(i,0,n-1)scanf("%d",&a[i]);
		int m=*max_element(a.begin(),a.end())*2+1;
		vector<int>dp(m+1,INF);
		dp[0]=0;
		rep(i,0,n-1){
			vector<int>ndp(m+1,INF);
			rep(j,0,m){
				umin(ndp[max(0,j-a[i])],dp[j]+a[i]);
				if(j+a[i]<=m)umin(ndp[j+a[i]],max(0,dp[j]-a[i]));
			}
			dp=ndp;
		}
		int ans=INF;
		rep(i,0,m){
			ans=min(ans,i+dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}