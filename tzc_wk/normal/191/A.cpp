#include <bits/stdc++.h>
using namespace std;
int n;
char s[500001][13];
int len[500001];
int dp[28][28];
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n); 
    for(int i=0;i<n;i++){
		scanf("%s",s[i]);
    	len[i]=strlen(s[i]);
    }
	for(int i=0;i<n;i++){
		int x=s[i][0]-'a';
		int y=s[i][len[i]-1]-'a';
		for(int j=0;j<26;j++)
			if(dp[j][x]!=-1)
				dp[j][y]=max(dp[j][x]+len[i],dp[j][y]);
		dp[x][y]=max(dp[x][y],len[i]);
	}
	int ans=0;
	for(int i=0;i<26;i++ )
		for(int j=0;j<26;j++)
			if(i==j)
				ans=max(ans,dp[i][j]);
	printf("%d\n",ans);
}