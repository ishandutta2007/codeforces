#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
string s;
LL a[N],dp[N][5],minh,mina,minr;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	cin>>s;s=' '+s;
	rep(i,1,n)scanf("%d",&a[i]);
	dp[0][0] = 0;
	//dp[0][1] = dp[0][2] = dp[0][3] = 1e18;
	minh = mina = minr = 0;
	rep(i,1,n){
		dp[i][0] = dp[i-1][0]+(s[i]=='h'?a[i]:0);
		dp[i][1] = s[i]=='a'?min(dp[i-1][1]+a[i],dp[i-1][0]):dp[i-1][1];
		dp[i][2] = s[i]=='r'?min(dp[i-1][2]+a[i],dp[i-1][1]):dp[i-1][2];
		dp[i][3] = s[i]=='d'?min(dp[i-1][3]+a[i],dp[i-1][2]):dp[i-1][3];
		//cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<endl;
	}
	cout<<min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]))<<endl;
	return 0;
}