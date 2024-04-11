#include <bits/stdc++.h>
using namespace std;

bitset<500005> dp;
int N, D, ans, i, j, x, d, s=1;

int main(){
	dp[0] = 1;
	for(scanf("%d%d",&N,&D),i=0;i<N;i++){
		scanf("%d",&x);
		for(j=500000;j>=x;j--)
			dp[j]=(dp[j]||dp[j-x]);
	}
	while(s){
		for(s=0,i=min(ans+D,500000);i>ans;i--){
			if(dp[i]){
				s=i-ans; break;
			}
		}
		ans += s; d++;
	}
	printf("%d %d\n",ans,d-1);
	return 0;
}