#include<iostream>
using namespace std;
long long a[100020],n,h,x,y,z,q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>x>>y;
		z=max(h,a[x]);
		cout<<z<<endl;
		h=z+y;
	}
	return 0;
}