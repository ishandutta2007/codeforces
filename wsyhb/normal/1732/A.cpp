#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int n;
const int max_n=20+5;
int a[max_n];
inline bool check()
{
	int d=a[1];
	for(int i=2;i<=n;++i)
		d=gcd(d,a[i]);
	return d==1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		if(n==1)
		{
			puts(a[1]==1?"0":"1");
			continue;
		}
		if(check())
		{
			puts("0");
			continue;
		}
		int old=a[n];
		a[n]=gcd(a[n],n);
		if(check())
		{
			puts("1");
			continue;
		}
		a[n]=old;
		a[n-1]=gcd(a[n-1],n-1);
		if(check())
		{
			puts("2");
			continue;
		}
		puts("3");
	}
	return 0;
}