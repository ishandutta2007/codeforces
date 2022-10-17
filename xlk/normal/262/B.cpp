#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[100020],z;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0&&k)
			a[i]=-a[i],k--;
	}
	sort(a,a+n);
	if(k%2)
		*a=-*a;
	for(int i=0;i<n;i++)
		z+=a[i];
	cout<<z;
}