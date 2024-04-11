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
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	int t=ksm(2,m);
	--t,t+=mod,t%=mod;
	cout << ksm(t,n);
	return 0;
}