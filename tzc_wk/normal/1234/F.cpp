#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n,dp[(1<<20)+15],ans;
bool used[25];
int main(){
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		int mask=0;
		for(int j=i;j<=n;j++){
			if(used[s[j]-'a'])	break;
			used[s[j]-'a']=1;
			mask|=(1<<(s[j]-'a'));
			dp[mask]=__builtin_popcount(mask);
		}
	}
	for(int i=0;i<(1<<20);i++){
		for(int j=0;j<20;j++){
			if(i>>j&1){
				dp[i]=max(dp[i],dp[i^(1<<j)]);
			}
		}
	}
	for(int i=0;i<(1<<20);i++){
		if(dp[i]==__builtin_popcount(i)){
			ans=max(ans,dp[i]+dp[~i&((1<<20)-1)]);
		}
	}
	cout<<ans<<endl;
	return 0;
}