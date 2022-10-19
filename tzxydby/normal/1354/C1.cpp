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
		double x=360.0/n/2;
		double y=0.5/tan(x*acos(-1)/180.0)*2;
		cout<<fixed<<setprecision(10)<<y<<endl;
	}
	return 0;
}