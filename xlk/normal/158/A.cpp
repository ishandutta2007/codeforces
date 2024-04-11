#include<iostream>
using namespace std;
int a[100],n,k,i;
int main()
{
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;a[i]>0&&a[i]>=a[k];i++)
		;
	cout<<i-1;
	return 0;
}