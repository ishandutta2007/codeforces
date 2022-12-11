#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,x,ans=0,mx=0,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		ans+=x;
		mx=max(x,mx);
	}
	cout<<mx*n-ans;	
	return 0;
}