#include <bits/stdc++.h>
using namespace std;
int N,K,dp[500002][30];
char s[500002];
int main(){
	scanf("%d%d%s",&N,&K,s+1);
	memset(dp,1,sizeof(dp));
	for(int i=0;i<30;i++)	dp[0][i]=0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<K;j++){
			for(int l=0;l<K;l++){
				if(j!=l){
					dp[i][j]=min(dp[i][j],dp[i-1][l]);
				}
			}
			if(s[i]-'A'!=j)	dp[i][j]++;
		}
	}
	int ans=INT_MAX,ind=0,nind;
	for(int i=0;i<K;i++)
		if(ans>dp[N][i]){
			ans=dp[N][i];
			nind=i;
		}
	printf("%d\n",ans);
	vector<char> str;
	for(int i=N;i>=1;i--){
		str.push_back(nind+'A');
		ind=nind;
		for(int j=0;j<K;j++){
			if(dp[i-1][j]+((s[i]-'A'==ind)?0:1)==dp[i][ind]&&j!=ind){
				nind=j;
			}
		}
	}
	reverse(str.begin(),str.end());
	for(int i=0;i<str.size();i++)	printf("%c",str[i]);
}