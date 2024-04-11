// Author : WangZhikun
// Date   : 2018.09.03

#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}

ll n,dp[1000010][2];
char a[1000010],b[1000010];
int main(){
	read(n);
	cin>>a>>b;
	memset(dp,7,sizeof(dp));
	for(int i=0;i<n;i++){
		a[i]-='0';b[i]-='0';
	}
	dp[0][a[0]] = 0;
	for(int i=0;i<n;i++){
		dp[i+1][a[i+1]] = min(dp[i][b[i]],dp[i][!b[i]]+1);
		if(a[i+1] == b[i]){
			dp[i+1][0] = min(dp[i+1][0],dp[i][0]+1);
			dp[i+1][1] = min(dp[i+1][1],dp[i][1]+1);
		}
	}
	cout<<min(dp[n-1][b[n-1]],dp[n-1][!b[n-1]]+1)<<endl;
	return 0;
}