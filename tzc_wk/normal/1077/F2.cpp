#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,x,a[5015],dp[5015][5015],ans=-1,deq[5015],head,tail;
signed main(){
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)	cin>>a[i];
	memset(dp,128,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=x;i++){
		head=1,tail=0;
		deq[++tail]=0;
		for(int j=1;j<=n;j++){
			while(head<=tail&&deq[head]+k<j)					head++;
			dp[i][j]=dp[i-1][deq[head]]+a[j];
			while(head<=tail&&dp[i-1][deq[tail]]<=dp[i-1][j])	tail--;
            deq[++tail]=j;
		}
	}
	for(int i=n;i>=n-k+1;i--)	ans=max(ans,dp[x][i]);
	cout<<ans<<endl;
}