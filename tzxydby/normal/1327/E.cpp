#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,mod=998244353;
int p9[N]={1},p10[N]={1},ans[N],n;
int pow9(int x)
{
	return x<0?1:p9[x];
}
int pow10(int x)
{
	return x<0?1:p10[x];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	if(n==1)
	{
		cout<<10;
		return 0;
	}
	for(int i=1;i<=n;i++)
		p9[i]=p9[i-1]*9%mod,p10[i]=p10[i-1]*10%mod;
	for(int i=1;i<n;i++)
	{
		ans[i]=(n-i-1)*10*9*9%mod*pow10(n-i-2);
		ans[i]=(ans[i]+(2*10*9%mod*pow10(n-i-1)%mod))%mod;
		cout<<ans[i]<<' ';
	}
	cout<<10;
	return 0;
}