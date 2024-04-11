#include <bits/stdc++.h>
#include <map>
#include <iostream>
using namespace std;
int power(int a,int b)
{
	int ans=1;
	for(int i=0;i<b;i++)
	{
		ans=ans*a;
	}
	return ans;
}
int main()
{
	int a,b,n;
	cin>>a>>b>>n;
	if(a==0&&b==0)
	{
		cout<<"3749"<<endl;
		return 0;
	}
	if(a==0&&b!=0)
	{
		cout<<"No solution"<<endl;
		return 0;
	}
	if(b==0&&a!=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(b%a!=0)
	{
		cout<<"No solution"<<endl;
		return 0;
	}
	int c=b/a;
	for(int i=-1000;i<=1000;i++)
	{
		if(power(i,n)==c)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"No solution"<<endl;
	return 0;
}