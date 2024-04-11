#include <iostream>
#define int long long
#define mod 1000000007
using namespace std;
inline int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1)
			rtn*=x,rtn%=mod;
		x*=x,x%=mod,y>>=1;
	}
	return rtn;
}
signed main() {
	int a,b,ans=1;
	cin >> a >> b;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i)
			continue;
		while(a%i==0&&a)
			a/=i;
		int x=b,cnt=0;
		while(x)
		{
			cnt+=x/i;
			x/=i;
		}
		ans*=ksm(i,cnt);
		ans%=mod;
	}
	if(a!=1)
	for(int i=a;i<=a;i++)
	{
		int x=b,cnt=0;
		while(x)
		{
			cnt+=x/i;
			x/=i;
		}
		ans*=ksm(i,cnt);
		ans%=mod;
	}
	cout << ans;
	return 0;
}