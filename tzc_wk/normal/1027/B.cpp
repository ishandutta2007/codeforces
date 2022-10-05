#include <bits/stdc++.h>
using namespace std;
#define sqr(a)	((a)*(a))
#define fhalf(a)	(sqr(a)/2)
int main()
{
	long long n,q;
	cin>>n>>q;
	for(int e=0;e<q;e++)
	{
		long long x,y;
		cin>>x>>y;
		long long num=(x-1)*n+y;
		if(n%2==1)
		{
			if(num%2==1)	cout<<(num+1)/2<<endl;
			else cout<<fhalf(n)+(num)/2+1<<endl;
		}
		else
		{
			if(x%2==1&&num%2==0)	cout<<fhalf(n)+num/2<<endl;
			else if(x%2==1&&num%2==1)	cout<<(num+1)/2<<endl;
			else if(x%2==0&&num%2==0)	cout<<num/2<<endl;
			else	cout<<fhalf(n)+(num+1)/2<<endl;
		}
	}
	return 0;
}