#include <bits/stdc++.h>
using namespace std;

int dp[101][4], n, i, j, k;
pair<int,int> w[4]={{2,3},{1,3},{3,1},{3,2}};
string a[2];

bool cmp(int i, int j){
	return ((2&i)>=(2&j)&&(1&i)>=(1&j));
}

int main(){
	cin >> a[0] >> a[1];
	for(i=1;i<a[0].size();i++){
		int mask = 2*(a[0][i]=='0')+(a[1][i]=='0');
		int mbsk = 2*(a[0][i-1]=='0')+(a[1][i-1]=='0');
		int mx = 0;
		for(int j=0;j<4;j++)mx=max(dp[i-1][j],mx);
		for(int j=0;j<4;j++) dp[i][j]=mx;
		for(int j=0;j<4;j++){
			if(cmp(mask,w[j].second)&&cmp(mbsk,w[j].first)){
				for(int k=0;k<4;k++){
					if(cmp(k,w[j].first)){
						dp[i][mask^w[j].second]=max(dp[i][mask^w[j].second],dp[i-1][k]+1);
					}
				}
			}
		}
	}
	int ans= 0;
	for(int j=0;j<4;j++)
		ans=max(ans,dp[a[0].size()-1][j]);
	printf("%d\n",ans);
	getchar(); getchar();
}