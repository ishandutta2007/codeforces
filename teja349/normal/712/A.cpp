#include<iostream>
using namespace std;
int main(){
	int n;
	long long int a[123456],b[123456];
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	a[n]=0;
	for (int i = 0; i < n; ++i)
	{
		b[i]=a[i]+a[i+1];
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<b[i]<<" ";
	}
}