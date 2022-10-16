#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],t=2,coun=0;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    t+=a[i];
	}
	sort(a,a+n);
	for(int k=0,i=n-1;k<t/2;i--)
	{
		k+=a[i];
		coun++;
	}
	cout<<coun;
}