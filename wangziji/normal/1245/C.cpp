#include <iostream>
#define int long long
#define mod 1000000007
using namespace std;
int dp[100005][10],f[100005];
string s;
signed main(int argc, char** argv) {
	dp[0][0]=1;
	for(int i=1;i<=100000;i++)
	{
		dp[i][1]+=dp[i-1][0]+dp[i-1][1];
		dp[i][1]%=mod;
		dp[i][0]+=dp[i-1][1];
		dp[i][0]%=mod;
		f[i]=dp[i][0]+dp[i][1];
		f[i]%=mod;
	}
	int ans=1;
	cin >> s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='w'||s[i]=='m')
		{
			cout << 0;
			return 0;
		}
	}
	int lst,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==lst)
			++cnt;
		else
		{
			if(lst=='n'||lst=='u')
				ans*=f[cnt],ans%=mod;
			cnt=1,lst=s[i];
		}
	}
	
			if(lst=='n'||lst=='u')
				ans*=f[cnt],ans%=mod;
	cout << ans;
	return 0;
}