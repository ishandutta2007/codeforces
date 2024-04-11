#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,i,p,j;
		scanf("%lld",&n);
		j=0;
		for(i=1;i<=9;i++)
		{
			p=i;
			while(p<=n)
			{
				j++;
				p=p*10 +i;
			}
		}
	cout<<j<<endl;
	}
}