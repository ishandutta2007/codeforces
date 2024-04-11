#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		if(x>=y || x>=4)
		{
			cout<<"YES"<<endl;
		}
		else if(x==2 && y<=3)
		{	
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}

}