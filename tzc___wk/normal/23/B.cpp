#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int(i)=0;(i)<(n);(i)++)
int t,n;
int main()
{
	cin>>t;
	rep(z,t)
	{
		cin>>n;
		if(n==1)	cout<<"0"<<endl;
		else	cout<<n-2<<endl;
	}
	return 0;
}