#include <bits/stdc++.h>
using namespace std;

int N, xa, xb, ya, yb, xt, yt, i, x, y;
double sq(double d){return d*d;}
double dp[2][2], tmp[2][2];

int main(){
	scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xt,&yt);
	dp[1][0]=dp[0][1]=dp[1][1]=1e100;
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d%d",&x,&y);
		double dt = sqrt(sq(x-xt)+sq(y-yt));
		double da = sqrt(sq(x-xa)+sq(y-ya));
		double db = sqrt(sq(x-xb)+sq(y-yb));
		tmp[0][0]=dp[0][0]+2*dt;
		tmp[1][0]=min(dp[1][0]+dt,dp[0][0]+da)+dt;
		tmp[0][1]=min(dp[0][1]+dt,dp[0][0]+db)+dt;
		tmp[1][1]=min(min(dp[0][1]+da,dp[1][0]+db),dp[1][1]+dt)+dt;
		swap(tmp,dp);
	}
	printf("%.10lf\n",min(min(dp[1][0],dp[0][1]),dp[1][1]));
	return 0;
}