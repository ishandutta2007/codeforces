#include <bits/stdc++.h>
using namespace std;
int n;
main()
{
	cin>>n;
	cout<<n/2<<endl;
	for (int i=1;i<n/2;i++)cout<<2<<" ";
	if (n%2)cout<<3<<endl;
	else cout<<2<<endl;
}