#include <bits/stdc++.h>
using namespace std;
int dp[105][105][27];
int cost[27][27];
int k,n,g;
string s;
int main(){
	cin>>s>>k>>g;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=g;i++){
		char c1,c2;int val;
		cin>>c1>>c2>>val;
		cost[c1-'a'][c2-'a']=val;
	}
	memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[1][0][s[1]-'a']=0;
    for(int i=0;i<26;i++) 	if(i+'a'!=s[1])	dp[1][1][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int x=0;x<26;x++)
				for(int y=0;y<26;y++){
					int val=dp[i][j][x]+cost[x][y];
					if(s[i+1]!=y+'a')
						dp[i+1][j+1][y]=max(dp[i+1][j+1][y],val);
					else
						dp[i+1][j][y]=max(dp[i+1][j][y],val);
			}
    int ans=-0x3f3f3f3f;
    for(int i=0;i<=k;i++)
		for(int j=0;j<26;j++)
			ans=max(ans,dp[n][i][j]);
    printf("%d\n",ans);
    return 0;
}