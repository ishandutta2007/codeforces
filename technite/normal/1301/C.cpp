#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		long long k=(n-m)/(m+1);
		cout<<(n*(n+1)/2)-k*(k+1)*(m+1-(n-m)%(m+1))/2-(k+1)*(k+2)*((n-m)%(m+1))/2;
	
	    cout<<endl;
	}
}