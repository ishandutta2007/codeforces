#include <bits/stdc++.h>
using namespace std;



int main(){
	int n,k;
	cin>>n;
	int a[n],b[n],m=1000000007;
	long long int x=1;
	for (int i = 0; i < n; ++i)
	{
		b[i]=x;
		cin>>a[i];
		x*=2;
		x%=m;
	}
	sort(a,a+n);
	long long int sum=0,y=0;
	for (int i = 0; i < n; ++i)
	{
		y=(b[i]-b[n-1-i]);
		y%=m;
		y*=a[i];
		y%=m;
		sum+=y;
		sum%=m;
	}
	cout<<sum<<endl;
	return 0;
}