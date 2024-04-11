#include <iostream>
#include <map>
using namespace std;
int a[100005],b[100005],dp[100005],n,m,cg[100005];
map <int,int> mp;
inline int gcd(int x,int y)
{
	if(x>y)
		swap(x,y);
	while(x)
	{
		y%=x;
		swap(x,y);
	}
	return y;
}
inline int cal(int x)
{
	if(mp[x]!=0)
		return mp[x];
	int rtn=0,X=x;
	for(int i=1;i<=m;i++)
	{
		while(x%b[i]==0)
		{
			--rtn;
			x/=b[i];
		}
	}
	for(int i=2;i*i<=x;i++)
	{
		while(x%i==0)
		{
			x/=i;
			++rtn;
		}
	}
	if(x>1)
		++rtn;
	mp[X]=rtn;
	return rtn;
}
int t[100005],g[100005],qzh[100005];
int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		g[i]=gcd(a[i],g[i-1]);
	}
	for(int i=1;i<=m;i++)
		cin >> b[i];
	for(int i=1;i<=n;i++)
	{
		t[i]=cal(a[i]);
		qzh[i]=qzh[i-1]+t[i];
		cg[i]=cal(g[i]);
	}
	dp[n]=cal(a[n])-cal(g[n]);
	for(int i=n-1;i>=1;i--)
	{
		int mx=-123456789;
		for(int j=n;j>i;j--)
			mx=max(mx,dp[j]+qzh[j-1]-qzh[i]-cg[j]*(j-i-1)+t[i]-cg[i]);
		dp[i]=max(mx,qzh[n]-qzh[i-1]);
	}
	int ans=-123456789;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]+qzh[i-1]-cal(g[i])*(i-1));
	cout << max(ans,qzh[n]);
	return 0;
}
//dp[i]ii
//dp[i]=max(dp[j]+a[i+1]+a[i+2]+...+a[j-1]-cal(g[j])*(j-i-1)+a[i]-cal(g[i])