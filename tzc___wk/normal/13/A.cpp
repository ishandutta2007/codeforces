#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	int r;
	for(;y!=0;)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int Sum(int x,int k)
{
	int ans=0;
	while(x)
	{
		ans+=x%k;
		x/=k;
	}
	return ans;
}
int a=0;
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<n;i++)
	{
		a+=Sum(n,i);
	}
	int b=n-2;
	int c=gcd(a,b);
	a/=c,b/=c;
	cout<<a<<"/"<<b<<endl;
}