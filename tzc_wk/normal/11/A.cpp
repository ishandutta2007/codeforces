#include <bits/stdc++.h>
using namespace std;
long long a[1001000],n,k,moves;
int main()
{
	cin>>n>>k;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i-1]>=a[i])
		{
			int t=(a[i-1]-a[i])/k+1;
			moves+=t;
			a[i]=a[i]+t*k;
		}
	}
	cout<<moves<<endl;
	return 0;
}