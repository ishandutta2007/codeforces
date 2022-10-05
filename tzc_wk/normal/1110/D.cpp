#include <bits/stdc++.h>
using namespace std;
int hs[1000001];
int main(){
	int n,m;
	cin>>n>>m;
	while(n--){
		int a;
		cin>>a;
		hs[--a]++;
	}
	int dp[2][3][3]={0};
	for (int i=0;i<m;++i){
		memset(dp[i&1^1],0,36);
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				for(int l=0;l<3;++l)
					if(j+k+l<=hs[i])
						dp[i&1^1][k][l]=max(dp[i&1^1][k][l],dp[i&1][j][k]+l+(hs[i]-j-k-l)/3);
	}
	cout<<dp[m&1][0][0]<<endl;
}