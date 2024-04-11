#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n*=2;
		long double x=360.0/n/4;
		long double y=0.5/sin(x*acos(-1)/180.0);
		cout<<fixed<<setprecision(10)<<y<<endl;
	}
	return 0;
}