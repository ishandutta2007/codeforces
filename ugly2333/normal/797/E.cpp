//CF 797D
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
int dp[111111][333],a[111111];
int main()
{
	int n,i,j,m,q,p,k;
	cin>>n;
	m=300;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&a[i]);
		for(j=0;j<=m;j=j+1){
			if(i+a[i]+j>n)
				dp[i][j]=1;
			else
				dp[i][j]=1<<30;
		}
	}
	for(j=1;j<=m;j=j+1){
		for(i=n;i>0;i=i-1)
			if(i+a[i]+j<=n)
				dp[i][j]=min(dp[i][j],dp[i+a[i]+j][j]+1);
	}
	cin>>q;
	while(q--){
		cin>>p>>k;
		if(k<=m)
			cout<<dp[p][k]<<endl;
		else{
			j=0;
			while(p<=n){
				p=p+a[p]+k;
				j++;
			}
			cout<<j<<endl;
		}
	}
	return 0;
}