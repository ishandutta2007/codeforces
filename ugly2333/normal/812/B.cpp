// CF 812B
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
char a[22][111];
int dp[22][3],l[22],r[22];
int main()
{
	int n,m,i,j,f;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1){
		l[i]=m+2;
		r[i]=1;
	}
	f=n+1;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m+2;j=j+1){
			cin>>a[i][j];
			if(a[i][j]=='1'){
				l[i]=min(l[i],j);
				r[i]=max(r[i],j);
				f=min(f,i);
			}
		}
	dp[n+1][1]=-1;
	dp[n+1][2]=1<<30;
	for(i=n;i>f;i=i-1){
		dp[i][1]=min(dp[i+1][1]+2*(r[i]-1),dp[i+1][2]+m+1)+1;
		dp[i][2]=min(dp[i+1][2]+2*(m+2-l[i]),dp[i+1][1]+m+1)+1;
	}
	cout<<min(dp[f+1][1]+r[f]-1,dp[f+1][2]+m+2-l[f])+1<<endl;
	return 0;
}