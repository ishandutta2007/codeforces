

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n;
	cin>>m;
	cin>>k;
	int a[n+1];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i+1];
	}
	a[0]=101;
	for (int i = 1; i < n; ++i)
	{
		if ((a[m-i]<=k)&&((m-i)>0)&&(a[m-i]>0))
		{
			cout<<10*i<<endl;
			return 0;
		}
		else if ((a[m+i]<=k)&&((m+i)<=n)&&(a[m+i]>0))
		{
			cout<<10*i<<endl;
			return 0;
		}
	}
	return 0;
}