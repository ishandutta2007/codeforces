#include <bits/stdc++.h>
using namespace std;

int main(){

	int n,h;
	cin>>n>>h;
	double a=h*1.0;
	a=a/sqrt(n);
	for (int i = 1; i < n; ++i)
	{
		double ans=sqrt(i)*a;
		cout<<setprecision(15)<<ans<<" ";
	}




	return 0;

}