#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int x,y,t;
long long z;
int gcd(int x,int y)
{
	if(x==0)
		return 0;
	z+=y/x;
	gcd(y%x,x);
}
int main()
{
	for(cin>>t;t--;)
	{
		cin>>x>>y;
		z=0;
		gcd(x,y);
		cout<<z<<endl;
	}
}