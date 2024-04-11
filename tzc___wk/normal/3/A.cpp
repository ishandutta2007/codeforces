#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>
#include <cmath> 
using namespace std;
string s,t;
int main()
{
	cin>>s>>t;
	int a=s[0]-'a',b=t[0]-'a',x=s[1]-'0',y=t[1]-'0';
	int d1=fabs(a-b),d2=fabs(x-y);
	if(a==b&&x==y)
	{
		cout<<"0"<<endl;
		return 0;
	}
	else if(a==b&&x>y)
	{
		cout<<x-y<<endl;
		for(int i=0;i<x-y;i++)
		{
			cout<<"D"<<endl;
		}
		return 0;
	}
	else if(a==b&&y>x)
	{
		cout<<y-x<<endl;
		for(int i=0;i<y-x;i++)
		{
			cout<<"U"<<endl;
		}
		return 0;
	}
	else if(a>b&&y==x)
	{
		cout<<a-b<<endl;
		for(int i=0;i<a-b;i++)
		{
			cout<<"L"<<endl;
		}
		return 0;
	}
	else if(a<b&&y==x)
	{
		cout<<b-a<<endl;
		for(int i=0;i<b-a;i++)
		{
			cout<<"R"<<endl;
		}
		return 0;
	}
	cout<<max(d1,d2)<<endl;
	for(int i=0;i<min(d1,d2);i++)
	{
		if(a>b&&x>y)	cout<<"LD"<<endl;
		else if(a<b&&x<y)	cout<<"RU"<<endl;
		else if(a<b&&x>y)	cout<<"RD"<<endl;
		else if(a>b&&x<y)	cout<<"LU"<<endl;
	}
	for(int i=0;i<max(d1,d2)-min(d1,d2);i++)
	{
		if(a>b&&x>y&&d1>d2)	cout<<"L"<<endl;
		else if(a>b&&x>y&&d1<d2)	cout<<"D"<<endl;
		else if(a<b&&x>y&&d1>d2)	cout<<"R"<<endl;
		else if(a<b&&x>y&&d1<d2)	cout<<"D"<<endl;
		else if(a>b&&x<y&&d1>d2)	cout<<"L"<<endl;
		else if(a>b&&x<y&&d1<d2)	cout<<"U"<<endl;
		else if(a<b&&x<y&&d1>d2)	cout<<"R"<<endl;
		else if(a<b&&x<y&&d1<d2)	cout<<"U"<<endl;
	}
}