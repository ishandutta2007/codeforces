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
int n,m,s;
signed main()
{
	cin>>n>>m;
	s=qp(m,n);
	for(int i=0;i<n;i++)
		s=(s+qp(m,n-i)*qp(2*m-1,i)%mod)%mod;
	cout<<s<<endl;
	return 0;
}