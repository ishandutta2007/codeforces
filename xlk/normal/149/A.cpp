#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int i,n,k,a[20],z;
int main()
{
	cin>>k;
	for(i=0;i<12;i++)
		cin>>a[i];
	sort(a,a+12,greater<int>());
	for(i=0;i<12&&z<k;i++)
		z+=a[i];
	if(z<k)
		cout<<-1;
	else
		cout<<i;
	return 0;
}