//CF 837D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int m = 6000;
const int inf = (1<<29);
LL a[222];
int b[222],c[222];
int dp[2][222][12345];
int main()
{
	int n,k,i,j,x,y,z,l,bb,cc;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		while(a[i]%2==0){
			b[i]++;
			a[i]/=2;
		}
		while(a[i]%5==0){
			c[i]++;
			a[i]/=5;
		}
	}
	for(i=0;i<=n;i=i+1)
		for(j=0;j<=2*m+1;j=j+1){
			dp[0][i][j]=-inf;
			dp[1][i][j]=-inf;
		}
	dp[0][0][m]=0;
	dp[1][0][m]=0;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=k;j=j+1){
			//cout<<i<<' '<<j<<endl;
			for(l=0;l<=2*m;l=l+1){
				z=l+c[i]-b[i];
				x=max(m-4444,min(m+4444,z));
				y=dp[(i&1)^1][j-1][x];
				if(z<m)
					bb=y,cc=y+m-z;
				else
					bb=y+z-m,cc=y;
				dp[i&1][j][l]=max(dp[(i&1)^1][j][l],min(bb+b[i],cc+c[i]));
				//cout<<dp[i&1][j][l]<<' ';
			}
			for(l=0;l<=m-4444;l=l+1)
				dp[i&1][j][m-4444]=max(dp[i&1][j][m-4444],dp[i&1][j][l]);
			for(l=m+4444;l<=2*m;l=l+1)
				dp[i&1][j][m+4444]=max(dp[i&1][j][m+4444],dp[i&1][j][l]);
			//cout<<endl;
		}
	}
	x=0;
	for(l=0;l<=2*m+1;l=l+1)
		x=max(x,dp[n&1][k][l]);
	cout<<x<<endl;
	return 0;
}