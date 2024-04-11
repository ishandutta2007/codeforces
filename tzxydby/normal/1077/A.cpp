#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,a,b,k;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>k;
		if(k%2)
			cout<<(a-b)*(k/2)+a<<endl;
		else
			cout<<(a-b)*k/2<<endl;
	}
	return 0;
}