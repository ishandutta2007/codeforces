#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long w,h,ans=1;
	cin>>w>>h;
	for(int i=1;i<=w+h;i++)
		ans=ans*2%998244353;
	cout<<ans<<endl;
	return 0;
}