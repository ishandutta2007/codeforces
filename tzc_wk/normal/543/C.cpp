#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[22];
int c[22][22],dp[(1<<20)+15],sum[22][22],msk[22][22];
int main(){
	cin>>n>>m;
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)	cin>>s[i];
	for(int i=0;i<n;i++)	for(int j=0;j<m;j++)	cin>>c[i][j];
	for(int i=0;i<n;i++)	for(int j=0;j<m;j++){
		int mx=0;
		for(int k=0;k<n;k++){	
			if(s[i][j]==s[k][j]){
				mx=max(mx,c[k][j]);
				msk[i][j]|=1<<k;
				sum[i][j]+=c[k][j];
			}
		}
		sum[i][j]-=mx;
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(!((i>>j)&1)){
				for(int k=0;k<m;k++){
					dp[(i|(1<<j))]=min(dp[(i|(1<<j))],dp[i]+c[j][k]);
					dp[(i|msk[j][k])]=min(dp[(i|msk[j][k])],dp[i]+sum[j][k]);
				}
			}
		}	
	}
	cout<<dp[(1<<n)-1]<<endl;
}