#include <iostream>
#define int long long
#define mod 998244353
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
inline int inv(int x)
{
	return ksm(x,mod-2);
}
int p[500005];
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin >> t;
		p[i]=(p[i-1]+1)*100%mod*inv(t)%mod;
	}
	cout << p[n];
	return 0;
}