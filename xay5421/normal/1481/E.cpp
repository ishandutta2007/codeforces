// author: xay5421
// created: Sat Feb  6 20:47:05 2021
#include<bits/stdc++.h>
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	vector<int>a(n+1,0);
	rep(i,1,n)scanf("%d",&a[i]);
	vector<pair<int,int> >pos(n+1,make_pair(-1,-1));
	rep(i,1,n){
		if(pos[a[i]].X==-1)pos[a[i]].X=i;
		pos[a[i]].Y=i;
	}
	vector<int>dp(n+2,0),cnt(n+1,0);
	per(i,n,1){
		dp[i]=dp[i+1];
		++cnt[a[i]];
		if(i==pos[a[i]].X){
			dp[i]=max(dp[i],dp[pos[a[i]].Y+1]+cnt[a[i]]);
		}else{
			dp[i]=max(dp[i],cnt[a[i]]);
		}
	}
	printf("%d\n",n-dp[1]);
	return 0;
}