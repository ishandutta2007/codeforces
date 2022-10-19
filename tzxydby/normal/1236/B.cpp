#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int qp(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
main()
{
	int n,m;
	cin>>n>>m;
	cout<<qp(((qp(2,m)-1+mod)%mod),n)<<endl;
	return 0;
}