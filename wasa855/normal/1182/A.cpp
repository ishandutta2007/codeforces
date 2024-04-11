#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n&1) cout<<"0\n";
	else
	{
		int ans=1;
		for(int i=1;i<=n/2;i++)
		{
			ans*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}