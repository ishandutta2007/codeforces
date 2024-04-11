#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
long long a[N],p[25];
int main()
{
	p[0]=1;
	for(int i=1;i<=20;i++)
		p[i]=p[i-1]*10%mod;
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int j=1;
		while(a[i])
		{
			long long k=a[i]%10;
			long long add=k*(p[j]+p[j-1])%mod;
			ans=(ans+add)%mod;
			j+=2;
			a[i]/=10;
		}
	}
	cout<<(ans*n)%mod<<endl;
	return 0;
}