#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t,k,d,x;
	cin>>n>>t>>k>>d;

		x=n/k;
		if (n%k!=0)
		{
			x++;
		}
		x=x*t;
		if (d+t<x)
		{
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}

	
	return 0;
}