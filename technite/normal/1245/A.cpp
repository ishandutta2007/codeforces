#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		if(a>=b)
		{
			if(gcd(a,b)==1) cout<<"finite"<<endl;
			else cout<<"infinite"<<endl;
		}
		else
		{
			if(gcd(b,a)==1) cout<<"finite"<<endl;
			else cout<<"infinite"<<endl;
		}
	}
}