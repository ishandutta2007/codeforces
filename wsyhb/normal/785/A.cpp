#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0,i;
	string a;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a[0]=='T') ans+=4;
		if(a[0]=='C') ans+=6;
		if(a[0]=='O') ans+=8;
		if(a[0]=='D') ans+=12;
		if(a[0]=='I') ans+=20;
	}
	cout<<ans;
	return 0;
}