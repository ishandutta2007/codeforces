#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,ans=1,p=1;
		cin>>n>>m;
		while(1)
		{
			ans=ans*(p/2+1)%m;
			p*=2;
			if(p>n)
			{
				p/=2;
				ans=ans*(n-p+2)%m;
				break;
			}
		}
		ans=(ans-1+m)%m;
		cout<<ans<<endl;
	}
	return 0;
}