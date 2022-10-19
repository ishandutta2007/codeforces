#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	if(c==1)
	{
		cout<<a*b<<endl;
		return 0;
	}
	long long ans=((a-1)/c+1)*((b-1)/c+1);
	cout<<ans<<endl;
	return 0;
}