#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
int T, N, i, x, arr[MN]; ll ans;
pair<ll,ll> dp[MN][6];

int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%d",&arr[i]);
		}
		ans = -1LL<<60;
		for(i=0;i<=N;i++)
			dp[i][0] = {1, 1};
		for(int j=1;j<=5;j++)
			dp[0][j] = {-1LL<<40, 1LL<<40};
		for(int j=1;j<=5;j++){
			for(i=j;i<=N;i++){
				int fl = 0;
				if(i==j) fl = 1;
				if(arr[i]>=0){
					dp[i][j] = {1LL*dp[i-1][j-1].first*arr[i],1LL*dp[i-1][j-1].second*arr[i]};
					if(!fl){
						dp[i][j].first = max(dp[i][j].first,dp[i-1][j].first);
						dp[i][j].second = min(dp[i][j].second,dp[i-1][j].second);
					}
				}
				else{
					dp[i][j] = {1LL*dp[i-1][j-1].second*arr[i],1LL*dp[i-1][j-1].first*arr[i]};
					if(!fl){
						dp[i][j].first = max(dp[i][j].first,dp[i-1][j].first);
						dp[i][j].second = min(dp[i][j].second,dp[i-1][j].second);
					}
				}
				if(j==5) ans = max(ans, dp[i][j].first);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}