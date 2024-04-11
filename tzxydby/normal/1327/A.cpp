#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,k;
		cin>>n>>k;
		if(n%2!=k%2)
			cout<<"NO\n";
		else
		{
			long long s=k*k;
			if(s<=n)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}