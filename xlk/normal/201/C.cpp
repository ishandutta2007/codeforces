#include<stdio.h>
#include<iostream>
using namespace std;
int n;
long long a[100020],l[100020],r[100020],z,mx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		if(a[i-1]>1)
			l[i]=l[i-1]+a[i-1]/2*2; 
	for(int i=n;i>0;i--)
		if(a[i]>1)
			r[i]=r[i+1]+a[i]/2*2; 
	for(int i=1;i<n;i++)
	{
		if(~a[i]&1)
			a[i]--;
		a[i]+=a[i-1];
	}
	for(int i=n;i>0;i--)
		z=max(z,(mx=max(mx,r[i]+a[i-1]))+l[i]-a[i-1]);
	printf("%I64d\n",z);
	return 0;
}