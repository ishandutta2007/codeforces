#include <bits/stdc++.h>
using namespace std;
const int INF=5e8;
int n,s[3003],c[3003],dp[3003][4];
int main(){
	for(int i=0;i<3003;i++)	dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=INF;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",s+i);
	for(int i=0;i<n;i++)	scanf("%d",c+i),dp[i][1]=c[i];
	for(int i=0;i<n;i++){
		for(int k=2;k<=3;k++){
			for(int j=0;j<i;j++){
				if(s[j]<s[i])
					dp[i][k]=min(dp[i][k],dp[j][k-1]+c[i]);
			}
		}
	}
	
	int ans=INF;
	for(int i=2;i<n;i++)	ans=min(ans,dp[i][3]);
	printf("%d\n",(ans==INF)?-1:ans);
}