#include <iostream>
using namespace std;
int dp[100005],t[100005],x[100005],y[100005];
inline bool check(int a,int b)
{
	if(max(x[a],x[b])-min(x[a],x[b])+max(y[a],y[b])-min(y[a],y[b])<=max(t[a],t[b])-min(t[a],t[b]))
		return 1;
	return 0;
}
int main(int argc, char** argv) {
	int r,n;
	cin >> r >> n;
	for(int i=1;i<=n;i++)
		cin >> t[i] >> x[i] >> y[i];
	x[0]=y[0]=1;
	int mx=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=-1e9;
		if(i<=r*2)
		{
			for(int j=0;j<i;j++)
			{
				if(check(i,j))
					dp[i]=max(dp[i],dp[j]+1);
			}
		}
		else
		{
			mx=max(mx,dp[i-2*r]);
			dp[i]=max(dp[i],mx+1);
			for(int j=i-1;j>=i-r*2;j--)
				if(check(i,j)) dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}