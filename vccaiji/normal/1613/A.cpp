#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long a,c;
		int b,d;
		cin>>a>>b>>c>>d;
		if(b>=d+7)
		{
			cout<<'>';
			if(i<t) cout<<endl;
			continue;
		} 
		if(b<=d-7) 
		{
			cout<<'<';
			if(i<t) cout<<endl;
			continue;
		}
		if(b<=d)
		{
			for(int j=1;j<=d-b;j++) c*=10;
		}
		else
		{
			for(int j=1;j<=b-d;j++) a*=10;
		}
		if(a<c) cout<<'<';
		if(a>c) cout<<'>';
		if(a==c) cout<<'=';
		if(i<t) cout<<endl;
	}
	return 0;//0 
}