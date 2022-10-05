#include <bits/stdc++.h>
using namespace std;
int n,m;
long long dp[200005];
int l,r,deq[200005];
char s[200005];
int main(){
	cin>>n>>m>>s+1;
	l=1;r=0;
	for(int i=1;i<=m;i++){
		if(s[i]=='1'){
			while(l<=r&&deq[r]>=i)	r--;
			deq[++r]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(l<=r&&deq[l]==i-m-1)	l++;
		dp[i]=dp[i-1]+i;
		if(s[i+m]=='1'&&i+m<=n){
			while(l<=r&&dp[max(deq[r]-m-1,0)]+deq[r]>dp[max(0,i-1)]+i+m)
				r--;
			deq[++r]=i+m;
		}
		if(l<=r)	dp[i]=min(dp[i],dp[max(deq[l]-m-1,0)]+deq[l]);
//		cout<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}