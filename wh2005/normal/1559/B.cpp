#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int T,n;
char s[N];
int dp[N][2],pre[N][2],a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		memset(pre,0,sizeof(pre));
		memset(dp,0x3f,sizeof(dp));
		scanf("%d%s",&n,s+1);
		if(s[1]=='?'||s[1]=='B') dp[1][0]=0;
		if(s[1]=='?'||s[1]=='R') dp[1][1]=0;
		for(int i=2;i<=n;i++){
			if(s[i]=='?'||s[i]=='B'){
				if(dp[i-1][0]+1<dp[i-1][1]){
					dp[i][0]=dp[i-1][0]+1,pre[i][0]=0;
				}
				else dp[i][0]=dp[i-1][1],pre[i][0]=1;
				
//				dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]);
			}
			if(s[i]=='?'||s[i]=='R'){
				if(dp[i-1][1]+1<dp[i-1][0]){
					dp[i][1]=dp[i-1][1]+1,pre[i][1]=1;
				}				
				else dp[i][1]=dp[i-1][0],pre[i][1]=0;
//				dp[i][1]=min(dp[i-1][0],dp[i-1][1]+1);
			}
		}
//		printf("%d\n",min(dp[n][0],dp[n][1]));
		int t=0;
		if(dp[n][0]<dp[n][1]) t=0;
		else t=1;
		for(int i=n;i>=1;i--){
			a[i]=t;
			t=pre[i][t];
		}
		for(int i=1;i<=n;i++)
			if(!a[i]) printf("B");
			else printf("R");
		puts("");
	}
	return 0;
}