#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
int dp[1<<21],mt[27][27],n,k;
string s; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k>>s;
	for (int i=1;i<n;++i){
		if (s[i]==s[i-1]) continue;
		mt[s[i]-'a'][s[i-1]-'a']++;
		mt[s[i-1]-'a'][s[i]-'a']++;
	}
	dp[0]=0;
	for (int i=1;i<(1<<k);++i){
		dp[i]=0x7fffffff;
	}
	for (int i=0;i<(1<<k);++i){
		int t=0;
		for (int r=0;r<k;++r){
			if (i>>r&1) t++;
		}
		for (int r=0;r<k;++r){
			if (i>>r&1) continue;
			int sum=0;
			for (int j=0;j<k;++j){
				if (i>>j&1){
					sum+=mt[r][j];
				}
				else{
					sum-=mt[r][j];
				}
			}
			dp[i^(1<<r)]=min(dp[i^(1<<r)],dp[i]+t*sum);
		}
	} 
	cout<<dp[(1<<k)-1];
	return 0;
}