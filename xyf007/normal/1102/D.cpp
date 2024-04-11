#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string s;
int n,zero,one,two;
int main()
{
	scanf("%d",&n);
	cin>>s;
	zero=one=two=-n/3;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			zero++;
		}
		if(s[i]=='1')
		{
			one++;
		}
		if(s[i]=='2')
		{
			two++;
		}
	}
	if(zero>0)
	{
		for(int i=n-1;(i>=0)&&(zero>0);i--)
		{
			if(s[i]=='0')
			{
				zero--;
				if(two<0)
				{
					s[i]='2';
					two++;
				}
				else
				{
					s[i]='1';
					one++;
				}
			}
		}
	}
	if(one>0)
	{
		for(int i=0;(i<n)&&(zero<0)&&(one>0);i++)
		{
			if(s[i]=='1')
			{
				one--;
				zero++;
				s[i]='0';
			}
		}
		for(int i=n-1;(i>=0)&&(two<0)&&(one>0);i--)
		{
			if(s[i]=='1')
			{
				one--;
				two++;
				s[i]='2';
			}
		}
	}
	if(two>0)
	{
		for(int i=0;(i<n)&&(two>0);i++)
		{
			if(s[i]=='2')
			{
				two--;
				if(zero<0)
				{
					s[i]='0';
					zero++;
				}
				else
				{
					s[i]='1';
					one++;
				}
			}
		}
	}
	cout<<s;
	return 0;
}