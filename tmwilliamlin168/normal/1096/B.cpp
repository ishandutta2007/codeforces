#include <bits/stdc++.h> 
using namespace std;

int main()
{
	 long long int n,x,y,u=998244353,i;
	cin>>n;
	string a;
	cin>>a;
	
	x=0;
	for(i=0;i<n;i++)
	{
		if(a[i]!=a[0])
			break;
		x++;
	}

	y=0;

	for(i=n-1;i>=0;i--)
	{
		if(a[i]!=a[n-1])
			break;
		y++;
	}

x++;
y++;

	if(a[0]!=a[n-1])
	{
		cout<<x+y-1;
	}
	else
	{
		x=(x*y)%u;
		cout<<x;
	}
	return 0;
}