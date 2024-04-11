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
long long k,b,n,t,x,ans;
int main()
{
	cin>>k>>b>>n>>t;
	x=1;
	while(k*x+b<=t)
	{
		x=k*x+b;
		n--;
	}
	while(t<x)
	{
		t=k*t+b;
		n++;
	}
	cout<<max(n,0LL)<<endl;
	return 0;
}