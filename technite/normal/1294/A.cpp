#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int a,b,c,n;
		cin>>a>>b>>c>>n;
		if(c>b) swap(b,c);
		if(b>a)
		{
			swap(a,b);
			if(c>b) swap(b,c);
		}
		long long sum=a+a-b-c;
		if(n>=sum)
		{
			if((n-sum)%3==0) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else cout<<"NO\n";

	}
}