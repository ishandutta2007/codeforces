#include<stdio.h>
#include<iostream>
using namespace std;
long long n,t,z,c[40][40];
int p;
int main()
{
	cin>>n>>t;
	if(t&t-1)
		return puts("0"),0;
	for(int i=0;i<40;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(p=0;1LL<<p!=t;p++)
		;
	for(int i=1;1LL<<i<n;i++)
		z+=c[i][p],n-=1LL<<i;
	for(int i=40;i--;)
		if(~p&&n>>i&1)
			z+=c[i][p],p--;
	cout<<z;
	return 0;
}