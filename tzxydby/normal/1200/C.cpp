#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n,m,q;
	cin>>n>>m>>q;
	long long g=__gcd(n,m);
	long long x=n/g,y=m/g;
	while(q--)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		b--;
		d--;
		if(a==c)
		{
			if(a==1)
			{
				if(b/x==d/x)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			if(a==2)
			{
				if(b/y==d/y)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
		}
		else
		{
			long long i,j;
			if(a==1)
				i=b/x;
			if(a==2)
				i=b/y;
			if(c==1)
				j=d/x;
			if(c==2)
				j=d/y;
			if(i==j)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}