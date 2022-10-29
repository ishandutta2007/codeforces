#include <iostream>
#define int long long
#define mod 1000000007
using namespace std;
int f[1005];
inline int cal(int x)
{
	int rtn=0;
	while(x)
	{
		rtn+=(x&1);
		x>>=1;
	}
	return rtn;
}
string s;
int dp[1005][1005][2];
signed main(int argc, char** argv) {
	f[1]=0;
	for(int i=2;i<=1000;i++)
		f[i]=f[cal(i)]+1;
	int k;
	cin >> s >> k;
	if(k>5)
	{
		cout << 0;
		return 0;
	}
	if(k==0)
	{
		cout << 1;
		return 0;
	}
	--k;
	dp[0][1][1]=1,dp[0][0][0]=1;
	for(int i=1;i<s.size();i++)
	{
		for(int j=0;j<=1000;j++)
		{
			dp[i][j][0]+=dp[i-1][j][0];	
			if(j) dp[i][j][0]+=dp[i-1][j-1][0];
			if(s[i]==48) dp[i][j][1]+=dp[i-1][j][1];
			if(s[i]==49&&j) dp[i][j][1]+=dp[i-1][j-1][1],dp[i][j][0]+=dp[i-1][j][1];
			dp[i][j][0]%=mod;
			dp[i][j][1]%=mod;
		}
	}
	int ans=0;
	for(int i=1;i<=1000;i++)
	{
		if(f[i]==k)
			ans+=dp[s.size()-1][i][0]+dp[s.size()-1][i][1];
		ans%=mod;
	}
	if(k==0) --ans;
	cout << ans << endl;
	return 0;
}