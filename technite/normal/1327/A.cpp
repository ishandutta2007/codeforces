#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		if((n+k)%2==0)
		{
			if(n>=k*k)
			{
				cout<<"YES";
			}
			else cout<<"NO";
		}
		else cout<<"NO";
		cout<<endl;
	}
}