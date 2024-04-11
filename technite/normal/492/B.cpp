#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,l;
	cin>>n>>l;
	long long int a[n]={0};
	double difference=0,max1=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
	{
		difference=a[i]-a[i-1];
		if(max1<difference) max1=difference;
	}
	double t=max1/2.0;
	if(t>a[0]&&t>l-a[n-1]) printf("%lf",t);
	else if(t>a[0]&&t<=l-a[n-1]) cout<<l-a[n-1];
	else if(t<=a[0]&&a[0]<l-a[n-1]) cout<<l-a[n-1];
	else cout<<a[0];
}