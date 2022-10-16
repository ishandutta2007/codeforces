#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long int a,b,n,sum;
		scanf("%lld %lld %lld %lld",&a,&b,&n,&sum);
		if(a*n+b<sum)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			int p=sum%n;
			if(p<=b)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
}