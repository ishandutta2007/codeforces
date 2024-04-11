#include<iostream>
using namespace std;
int a[1000];
int main()
{
	std::ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,a,b;
		cin>>n>>a>>b;
		if((a==n/2+1)&(b==n/2))
		{
			for(int j=n;j>1;j--) cout<<j<<' ';
			cout<<1;
			if(i<t) cout<<endl; 
			continue;
		}
		if((a<=n/2)&(b>=n/2+1))
		{
			for(int j=n;j>n/2;j--)
			 if(j!=b) cout<<j<<' ';
			cout<<a<<' ';
			for(int j=n/2;j>=1;j--)
			 if(j!=a) cout<<j<<' ';
			cout<<b;
			if(i<t) cout<<endl;
			continue;
		}
		cout<<-1;
		if(i<t) cout<<endl;
	}
	return 0; 
}