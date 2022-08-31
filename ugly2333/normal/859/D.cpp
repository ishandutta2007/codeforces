//CF 859D
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
const int N = 11;
const int M = 111;
int a[M][M];
double b[N][M],dp[N][M],ans;
bool cal(int i,int j,int k){
	return (i>>k)==(j>>k)&&(((i>>(k-1))+(j>>(k-1)))&1);
}
int main()
{
	int n,m,i,j,k,p;
	cin>>n;
	m=1<<n;
	for(i=0;i<m;i=i+1){
		b[0][i]=1.0;
		for(j=0;j<m;j=j+1)
			cin>>a[i][j];
	}
	for(k=1;k<=n;k=k+1){
		for(i=0;i<m;i=i+1){
			b[k][i]=0.0;
			for(j=0;j<m;j=j+1){
				if(cal(i,j,k))
					b[k][i]+=(double)b[k-1][j]*a[i][j]/100;
			}
			b[k][i]*=(double)b[k-1][i];
			//cout<<b[k][i]<<' ';
		}
		//cout<<endl;
	}
	for(k=1;k<=n;k=k+1){
		p=1<<(k-1);
		for(i=0;i<m;i=i+1){
			dp[k][i]=0.0;
			for(j=0;j<m;j=j+1)
				if(cal(i,j,k))
					dp[k][i]=max(dp[k][i],dp[k-1][j]);
			dp[k][i]+=dp[k-1][i]+(double)b[k][i]*p;
			//cout<<dp[k][i]<<' ';
		}
		//cout<<endl;
	}
	ans=0.0;
	for(i=0;i<m;i=i+1)
		ans=max(ans,dp[n][i]);
	printf("%.12lf\n",ans);
	return 0;
}