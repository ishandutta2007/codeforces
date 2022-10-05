#include<bits/stdc++.h>
using namespace std;
int x[510000],y[510000],d[510000],t[510000],e[510000];
long long dp[510][510][2];
vector<int> s[510][510];
long long sum[510][510];
long long xx[510][510],yy[510][510];
vector<pair<int,int> > lt[510][510],up[510][510];
bool chk(int xx,int yy,int tt){
	return (xx+yy>=tt)&&(((xx+yy-tt)&3)==0);
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)scanf("%d%d%d%d%d",&x[i],&y[i],&d[i],&t[i],&e[i]);
	for(int i=1;i<=k;i++){
		bool r[4];
		r[0]=r[1]=r[2]=r[3]=0;
		if(chk(x[i],y[i],t[i])){
			r[0]=1;s[x[i]][y[i]].push_back(i);
		}
		if(chk(x[i]+d[i],y[i]-d[i],t[i]+1)){
			r[1]=1;s[x[i]+d[i]][y[i]-d[i]].push_back(i);
		}
		if(chk(x[i]+d[i],y[i],t[i]+2)){
			r[2]=1;s[x[i]+d[i]][y[i]].push_back(i);
		}
		if(chk(x[i],y[i]+d[i],t[i]+3)){
			r[3]=1;s[x[i]][y[i]+d[i]].push_back(i);
		}
		if(r[0]&&r[3])lt[x[i]][y[i]+d[i]].push_back(make_pair(y[i],i));
		if(r[1]&&r[2])lt[x[i]+d[i]][y[i]].push_back(make_pair(y[i]-d[i],i));
		if(r[0]&&r[2])up[x[i]+d[i]][y[i]].push_back(make_pair(x[i],i));
    }
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k : s[i][j])sum[i][j]+=e[k];
 	dp[0][0][0]=dp[0][0][1]=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(i|j){
		dp[i][j][0]=dp[i][j][1]=1000000000000000000ll;
		for(auto k : up[i][j]) xx[k.first][j]+=e[k.second]; 
		for(auto k : lt[i][j]) yy[i][k.first]+=e[k.second];
		long long s1=0,s2=0,s3=0,s4=0;
		for(int k=i-1;k>=0;k--){
			s1+=sum[k+1][j];
			s3+=xx[k][j];
			dp[i][j][0]=min(dp[i][j][0],dp[k][j][1]+s1-s3);
		}
		for(int k=j-1;k>=0;k--){
			s2+=sum[i][k+1];
			s4+=yy[i][k];
			dp[i][j][1]=min(dp[i][j][1],dp[i][k][0]+s2-s4);
		}
	}
	cout<<min(dp[n-1][m-1][0],dp[n-1][m-1][1]);
	return 0;
}