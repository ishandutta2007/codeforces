#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[20],dp[20][20],cnt;
int dfs(int pos,int sum,bool limit){
	if(pos==-1)	return 1;
	if(!limit&&dp[pos][sum]!=-1)	return dp[pos][sum];
	int up=(limit)?a[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		if(i==0)		ans+=dfs(pos-1,sum,(limit&&(i==a[pos])));
		else if(sum!=3)	ans+=dfs(pos-1,sum+1,(limit&&(i==a[pos])));
	}
	if(!limit)	dp[pos][sum]=ans;
	return ans;
}
int solve(int x){
	cnt=0;
	while(x){
		a[cnt++]=x%10;
		x/=10;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(cnt-1,0,1);
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		int l,r;
		cin>>l>>r;
		cout<<solve(r)-solve(l-1)<<endl;
	}
}