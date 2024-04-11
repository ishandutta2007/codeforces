#include <bits/stdc++.h>
using namespace std;
int a[1005];
int dp[100005];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,x;
	cin>>n>>x;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i]*=(n-i+1);
	}
	for(int i=1;i<=n;i++)
		for(int j=x;j>=a[i];j--)
			dp[j]=max(dp[j],dp[j-a[i]]+1);
	cout<<dp[x]<<endl;
	return 0;
}