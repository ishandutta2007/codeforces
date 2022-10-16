#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,n,i,j,k,m=0;
	cin>>n;
	for(i=0;i<n;i++) 
	{
	    cin>>a;
	    m=__gcd(m,a);
	    
	}
	cout<<n*m;
}