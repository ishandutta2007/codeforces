#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	if(m==0)
	{
		cout<<"1\n";
		return 0;
	}
	if(m%4==1)
	{
		cout<<"8\n";
	}
	if(m%4==2)
	{
		cout<<"4\n";
	}
	if(m%4==3)
	{
		cout<<"2\n";
	}
	if(m%4==0)
	{
		cout<<"6\n";
	}
	
}