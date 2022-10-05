#include <bits/stdc++.h>
using namespace std;
int n,k;
char s[1005];
const int DELTA=1002;
bool dp[1005][2005];
string ans;
inline void trans(int i,int j){
	if(s[i]=='D')		dp[i][j]|=dp[i-1][j];
	else if(s[i]=='W')	dp[i][j]|=dp[i-1][j-1];
	else if(s[i]=='L')	dp[i][j]|=dp[i-1][j+1];
	else				dp[i][j]|=(dp[i-1][j+1]|dp[i-1][j]|dp[i-1][j-1]);
}
inline void print(int i,int j){
	if(i==0)	return;
	if(s[i]=='D')		ans+="D",print(i-1,j);
	else if(s[i]=='W')	ans+="W",print(i-1,j-1);
	else if(s[i]=='L')	ans+="L",print(i-1,j+1);
	else{
		if(dp[i-1][j])			ans+="D",print(i-1,j);
		else if(dp[i-1][j-1])	ans+="W",print(i-1,j-1);
		else					ans+="L",print(i-1,j+1);
	}
}
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	dp[0][DELTA]=1;
	for(int i=1;i<n;i++){
		for(int j=DELTA-k+1;j<DELTA+k;j++){
			trans(i,j);
		}
	}
	trans(n,k+DELTA);
	trans(n,-k+DELTA);
	if(dp[n][k+DELTA])			print(n,k+DELTA);
	else if(dp[n][-k+DELTA])	print(n,-k+DELTA);
	else						return puts("NO"),0;
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}