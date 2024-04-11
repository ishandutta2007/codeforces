#include<iostream>
using namespace std;
int a[20000],s[20000];
int main()
{
	int i,j,n,r=1<<31;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	for(j=1;j<=n/3;++j)
		if (n%j==0)
		{
			for(i=0;i<j;++i)
				s[i]=0;
			for(i=0;i<n;++i)
				s[i%j]+=a[i];
			for(i=0;i<j;++i)
				r=max(r,s[i]);
		}
	cout<<r;
}