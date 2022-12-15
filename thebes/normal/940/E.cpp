#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> s;
int n, k, i, arr[100005];
long long dp[100005], tot;

int main(){
	for(scanf("%d%d",&n,&k),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=n;i>=1;i--){
		s.insert({arr[i],i}); tot += arr[i];
		if(s.size()>k) s.erase({arr[i+k],i+k}),tot-=arr[i+k];
		if(s.size()==k)	dp[i] = min(arr[i]+dp[i+1],dp[i+k]-s.begin()->first+tot);
		else dp[i] = tot;
	}
	printf("%lld\n",dp[1]);
	return 0;
}