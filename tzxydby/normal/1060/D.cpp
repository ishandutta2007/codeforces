#include<bits/stdc++.h>
using namespace std;
long long n,i,l[100001],r[100001],x,y,z,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,i,l[100001],r[100001],x,y,z,t;
	cin>>n;
	x=n;
	for(i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(i=1;i<=n;i++)
		x+=max(l[i],r[i]);
	cout<<x<<endl;
	return 0;
}