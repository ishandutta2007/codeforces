#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long a,b;
		cin>>a>>b;
		if(a%b)
		cout<<b-a%b<<endl;
		else cout<<0<<endl;

	}
}