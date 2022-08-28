//CF 798B
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
int a[111111],dp[111111];
int gcd(int x,int y)
{
	if(x==0||y==0)
		return max(x,y);
	if(x<y)
		swap(x,y);
	int r;
	r=x%y;
	while(r){
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int main()
{
	int i,n,x;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		dp[i]=1<<30;
	}
	if(n==1){
		if(a[1]==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES\n0"<<endl;
		return 0;
	}
	x=a[1];
	for(i=2;i<=n;i=i+1)
		x=gcd(x,a[i]);
	if(x!=1){
		cout<<"YES\n0"<<endl;
		return 0;
	}
	dp[0]=0;
	if(a[1]%2==0)
		dp[1]=0;
	else
		dp[1]=2;
	for(i=2;i<=n;i=i+1){
		if(a[i]%2==0){
			dp[i]=min(dp[i],dp[i-1]);
			if(a[i-1]%2==1)
				dp[i]=min(dp[i],dp[i-2]+2);
		}
		else{
			dp[i]=min(dp[i],dp[i-2]+2);
			if(a[i-1]%2==1)
				dp[i]=min(dp[i],dp[i-2]+1);
		}
	}
	cout<<"YES"<<endl<<dp[n]<<endl;
	return 0;
}