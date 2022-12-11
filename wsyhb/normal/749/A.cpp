#include<bits/stdc++.h>
using namespace std;
void _(int x)
{
	for(int i=1;i<=x;i++) cout<<2<<" ";
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	if(n%2)
	{
		cout<<(n-3)/2+1<<endl;
		_((n-3)/2);
		cout<<3;
	}
	else 
	{
		cout<<n/2<<endl;
		_(n/2);
	}
	return 0;
}