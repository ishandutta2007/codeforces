#include <bits/stdc++.h>
using namespace std;
bool prime(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)	return false;
	}
	return true;
}
bool nei(int a,int b)
{
	if(!prime(a)||!prime(b))	return false;
	for(int i=a+1;i<b;i++)
	{
		if(prime(i))	return false;
	}
	return true;
}
bool ok(int n)
{
	if(!prime(n))	return false;
	int m=n-1;
	for(int i=2;i<m/2;i++)
	{
		if(nei(i,m-i))	return true;
	}
	return false;
}
int n,k,ans=0;
int main()
{
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		if(ok(i))
		{
			ans++;
		}
	}
	if(ans>=k)	puts("YES");
	else	puts("NO");
}