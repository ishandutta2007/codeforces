#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100020],c=100020,z,x;
int main()
{
	cin>>n;
	for(;n--;)
		cin>>x,c=min(c,x);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++)
		if(i%(c+2)<c)
			z+=a[i];
	cout<<z;
	return 0;
}