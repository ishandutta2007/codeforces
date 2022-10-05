#include <bits/stdc++.h>
using namespace std;
#define add(x,y)	x=(x+(y))%MOD
#define int long long
const int MOD=1e9+9;
int w,h,dp[1005][2][32][32][32],ans;
signed main(){
	cin>>w>>h;
	dp[0][0][0][0][0]=1;
	for(int i=0;i<w;i++)
		for(int a=0;a<2;a++)
			for(int b=0;b<=h;b++)
				for(int c=0;c<=h;c++)
					for(int d=0;d<=h;d++)
						if(dp[i][a][b][c][d]){
							add(dp[i+1][a][min(b+1,h)][min(c+1,h)][min(d+1,h)],dp[i][a][b][c][d]);
							add(dp[i+1][(b+1<=h)^1][min(c+1,h)][min(d+1,h)][a?h:1],dp[i][a][b][c][d]);
							add(dp[i+1][(c+1<=h)^1][min(d+1,h)][a?h:1][min(b+1,h)],dp[i][a][b][c][d]);
							add(dp[i+1][(d+1<=h)^1][a?h:1][min(b+1,h)][min(c+1,h)],dp[i][a][b][c][d]);
						}
	for(int a=0;a<2;a++)
		for(int b=0;b<=h;b++)
			for(int c=0;c<=h;c++)
				for(int d=0;d<=h;d++)
					if(!a||b<h||c<h||d<h)
						add(ans,dp[w][a][b][c][d]);
	cout<<ans<<endl;
}