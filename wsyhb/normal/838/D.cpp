#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int qpow(int a,int n)
{
	int res=1;
	while(n>0)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int ans=1ll*qpow(2,m)*qpow(n+1,m-1)%mod*(n+1-m)%mod;
	printf("%d\n",ans);
	return 0;
}