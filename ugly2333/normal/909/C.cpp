//CF 909C
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
const int N = 5555;
const int mod = 1e9+7;
int dp[N][N];
int main()
{
	int n,i,j,x;
	char ch[5],cc;
	cin>>n;
	cc='s';
	dp[0][0]=1;
	for(i=1;i<=n+1;i=i+1){
		if(i<=n)
			cin>>ch;
		if(ch[0]=='s'){
			for(j=0;j<=n;j=j+1)
				dp[i][j]=dp[i-1][j];
			x=0;
		}
		else{
			for(j=1;j<=n;j=j+1)
				dp[i][j]=dp[i-1][j-1];
			x=1;
		}
		if(cc=='s'){
			for(j=n;j>=x;j=j-1)
				dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
		}
		cc=ch[0];
	}
	cout<<dp[n+1][0]<<endl;
	return 0;
}