#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m;
	cin>>n>>m;
	int a[m],b[n];
	long long int t=0;
	for(long long int i=0;i<m;i++)
	{
		cin>>a[i];
		if(i>=1)
		{
			if(a[i]>=a[i-1]) t+=a[i]-a[i-1];
			else t+=n-(a[i-1]-a[i]);
		}
		if(i<1) t+=a[i]-1;
	}
	cout<<t;
	
	
	
}