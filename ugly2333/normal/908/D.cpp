//CF 908D
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
const int N = 1111;
const int mod = 1e9+7;
int fpow(int x,int p=mod-2){
	if(!p)
		return 1;
	LL e=fpow(x,p>>1);
	e=e*e%mod;
	if(p&1)
		e=e*x%mod;
	return e;
}
int n;
LL a,b,w,dp[N][N];
int dfs(int i,int j){
	if(dp[i][j])
		return dp[i][j];
	if(i+j>=n)
		dp[i][j]=w+i+j;
	else
		dp[i][j]=a*dfs(i,j+1)+b*dfs(i+j,j);
	dp[i][j]%=mod;
	return dp[i][j];
}
int main()
{
	int x;
	cin>>n>>a>>b;
	x=fpow(a+b);
	a=a*x%mod,b=b*x%mod;
	w=a*fpow(b);
	cout<<dfs(0,1);
	return 0;
}