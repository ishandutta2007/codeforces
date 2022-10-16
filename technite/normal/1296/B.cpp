#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long sum=n,r=1,ans=0;
		while(sum>9)
		{
			r=sum%10;
			long long s=sum/10;
			ans+=s*10;
			sum=r+s;
		}
		r=sum%10;
		ans+=r;
		cout<<ans<<endl;
	}
}