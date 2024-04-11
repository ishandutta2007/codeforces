#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,a[315],b[315],t[315],sum,dp[2][150015],deq[150015],ans=LLONG_MAX;
signed main(){
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++){
		memset(dp[i&1],63,sizeof(dp[i&1]));
		cin>>a[i]>>b[i]>>t[i];
		sum+=b[i];
		int x=t[i]-t[i-1];
		int left=1,right=0;
		for(int j=1;j<=n;j++){
			while(left<=right&&deq[left]<j-x*d)							left++;
			while(left<=right&&dp[(i&1)^1][deq[right]]>=dp[(i&1)^1][j])	right--;
			deq[++right]=j;
			dp[i&1][j]=min(dp[i&1][j],dp[(i&1)^1][deq[left]]+abs(a[i]-j));
		}
		memset(deq,0,sizeof(deq));
		left=1,right=0;
		for(int j=n;j>=1;j--){
			while(left<=right&&deq[left]>j+x*d)							left++;
			while(left<=right&&dp[(i&1)^1][deq[right]]>=dp[(i&1)^1][j])	right--;
			deq[++right]=j;
			dp[i&1][j]=min(dp[i&1][j],dp[(i&1)^1][deq[left]]+abs(a[i]-j));
		}
	}
	for(int i=1;i<=n;i++)	ans=min(ans,dp[m&1][i]);
	cout<<sum-ans<<endl;
}