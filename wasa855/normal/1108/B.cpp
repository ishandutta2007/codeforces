#include<bits/stdc++.h>
using namespace std;
#define int long long
bool used[10005];
int a[130];
int gcd(int x,int y)
{
	if(y==0)
	{
		return x;
	}
	return gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+n+1);
	int x=a[n];
	for(int i=1;i<=n;i++)
	{
		if(used[a[i]]==false&&x%a[i]==0)
		{
			used[a[i]]=true;
			a[i]=0;
		}
	}
	sort(a+1,a+n+1);
	int y=a[n];
	printf("%I64d %I64d\n",x,y);
	return 0;
}