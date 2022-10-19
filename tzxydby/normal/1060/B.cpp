#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,ans;
	cin>>n;
	while(n>9)
	{
		n-=9;
		ans+=9;
		ans+=n%10;
		n/=10;
	}
	cout<<ans+n<<endl;
}