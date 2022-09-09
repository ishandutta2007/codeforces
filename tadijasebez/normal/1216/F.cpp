#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
char s[N];
ll dp[N];
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	scanf("%s",s+1);
	deque<int> dq;
	dq.push_back(0);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+i;
		if(i>k && s[i-k]=='1'){
			while(dq.front()<i-2*k-1)dq.pop_front();
			dp[i]=min(dp[i],dp[dq.front()]+i-k);
		}
		while(dq.size() && dp[dq.back()]>dp[i])dq.pop_back();
		dq.push_back(i);
		if(i==n){
			for(int i=n-1;i>=1;i--)dp[i-1]=min(dp[i-1],dp[i]);
			for(int i=n;i>=n-k;i--)if(s[i]=='1')dp[n]=min(dp[n],dp[max(0,i-k-1)]+i);
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}