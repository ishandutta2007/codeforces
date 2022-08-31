#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
string dp[1100];
int n,way[1100];
int main(){
	cin>>dp[0]; n=dp[0].length();
	for (int i=1;i<=n;i++){
		string k1=dp[i-1];
		char now=k1[i-1];
		for (int j=i-1;j;j--) k1[j]=k1[j-1];
		k1[0]=now;
	//	cout<<i<<" "<<k1<<" "<<dp[i-1]<<endl;
		if (k1<dp[i-1]) way[i]=1,dp[i]=k1; else way[i]=0,dp[i]=dp[i-1];
	}
	for (int i=1;i<=n;i++) way[i]^=way[i+1];
	for (int i=1;i<=n;i++) printf("%d ",way[i]); puts("");
}