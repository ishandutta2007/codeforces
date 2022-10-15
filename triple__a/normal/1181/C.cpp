#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=2007;

int dp[maxn][maxn];
int u[maxn][maxn],cb[maxn][maxn];

int n,m;
char mp[maxn][maxn];

int main(){
	memset(u,0,sizeof(u));
	memset(cb,0,sizeof(cb));
	memset(dp,0,sizeof(dp));
	memset(mp,0,sizeof(mp));
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i){
		cin>>mp[i];
	}
	for (int i=0;i<m;++i){
		for (int j=0;j<n;++j){
			if (j==0||mp[j][i]!=mp[j-1][i]){
				cb[j][i]=1;
			}
			else{
				cb[j][i]=cb[j-1][i]+1;
			}
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (i>=2*cb[i][j]&&cb[i][j]==cb[i-cb[i][j]][j]&&cb[i][j]<=cb[i-2*cb[i][j]][j]){
				u[i][j]=cb[i][j];
			}
		}
	}
	for (int i=0;i<m;++i){
		for (int j=0;j<n;++j){
			if (i==0){
				dp[j][i]=(u[j][i]>0);
			}
			else{
				if (u[j][i]){
					if (u[j][i]==u[j][i-1]&&mp[j][i]==mp[j][i-1]&&mp[j-u[j][i]][i]==mp[j-u[j][i]][i-1]&&mp[j-2*u[j][i]][i]==mp[j-2*u[j][i]][i-1]){
						dp[j][i]=dp[j][i-1]+1;
					}
					else{
						dp[j][i]=1;
					}	
				}
			}
		}
	}
	long long ans=0;

	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			ans+=dp[i][j];
		}
	}
	cout<<ans;
	return 0;
}