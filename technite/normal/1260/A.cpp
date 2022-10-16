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
		long long int c,sum;
		scanf("%lld %lld",&c,&sum);
		if (c>=sum)
		{
			cout<<sum<<endl;
		} 
		else
		{
			int p=(sum/c),q=sum%c;
			cout<<(p+1)*(p+1)*q+p*p*(c-q)<<endl;


		}
	}
}