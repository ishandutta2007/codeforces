#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[x]=i;
	}
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}