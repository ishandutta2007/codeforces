#include<iostream>
#include<algorithm>
using namespace std;
int n,x,y,a[2000],i;
int main()
{
	cin>>n>>x>>y;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[y]-a[y-1];
	return 0;
}