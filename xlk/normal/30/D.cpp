#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n,m;
double a[100020],mx,x,y,z;
double D(int i)
{
	return hypot(x-a[i],y);
}
double A(int l,int r)
{
	return a[r]-a[l]+min(D(l),D(r));
}
double B(int l,int r)
{
	return a[r]-a[l]+min(D(l)+fabs(mx-a[r]),D(r)+fabs(mx-a[l]));
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%lf",a+i);
	cin>>x>>y;
	mx=a[m-1];
	sort(a,a+n);
	if(m>n)
		z=A(0,n-1);
	else
	{
		z=B(0,n-1);
		for(int i=1;i<n;i++)
			z=min(z,min(A(0,i-1)+B(i,n-1),B(0,i-1)+A(i,n-1)));
	}
	printf("%.20f\n",z);
	return 0;
}