#include <bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int n;
int a[maxn],m[maxn];
bool flag=false;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m[i]=m[i-1]+a[i]%2;
	}
	if(m[2]>=2)	flag=true;
	if(flag)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]%2==0)
			{
				cout<<i+1<<endl;
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==1)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
}