#include<bits/stdc++.h>
using namespace std;
char e[3]; 
int main()
{
	ios::sync_with_stdio(false);
	e[0]='a',e[1]='b',e[2]='c';
	string a,b;
	int n;
	cin>>n;
	cin>>a>>b;
	cout<<"YES\n";
	do
	{
		string c=e;
		string d;
		d+=c[2];
		d+=c[0];
		if(c.substr(0,2)!=a&&c.substr(0,2)!=b&&c.substr(1,2)!=a&&c.substr(1,2)!=b&&d!=a&&d!=b)
		{
			while(n--)
				cout<<c;
			return 0;	
		}
	}while(next_permutation(e,e+3));
	if(a[0]==b[0])
	{
		for(int j=0;j<3;j++)
		{
			if(j!=a[0]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
		for(int j=0;j<3;j++)
		{
			if(j==a[0]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
	}
	else if(a[1]==b[1])
	{
		for(int j=0;j<3;j++)
		{
			if(j==a[1]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
		for(int j=0;j<3;j++)
		{
			if(j!=a[1]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
	}
	else
	{
		for(int j=0;j<3;j++)
		{
			if(j==a[0]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
		for(int j=0;j<3;j++)
		{
			if(j!=a[0]-'a'&&j!=b[0]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
		for(int j=0;j<3;j++)
		{
			if(j==b[0]-'a')
			{
				for(int i=1;i<=n;i++)
					cout<<char(j+'a');
			}
		}
	}
	return 0;
}