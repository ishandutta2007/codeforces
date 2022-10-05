#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n,x0,a[1100];
int s,e;
int main()
{
	cin>>n>>x0;
	int ans=1100;
	for(int i=0;i<n;i++)
	{
		cin>>s>>e;
		for(int j=min(s,e);j<=max(s,e);j++)
		{
			a[j]++;
		}
	}
	for(int i=0;i<1100;i++)
	{
		if(a[i]==n)
		{
			ans=min(ans,abs(i-x0));
		}
	}
	if(ans==1100)	puts("-1");
	else	cout<<ans<<endl;
	return 0;
}