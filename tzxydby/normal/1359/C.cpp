#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		double c,h,t;
		cin>>h>>c>>t;
		double m=(c+h)/2;
		if(t==h)
		{
			cout<<1<<endl;
			continue;
		}
		if(t<=m)
		{
			cout<<2<<endl;
			continue;
		}
		t-=m,h-=m;
		double zh=floor(h/t/2);
		if(fabs(t-h/(zh*2+1))<=fabs(t-h/(zh*2+3)))
			cout<<zh*2+1<<endl;
		else
			cout<<zh*2+3<<endl;
	}
	return 0;
}