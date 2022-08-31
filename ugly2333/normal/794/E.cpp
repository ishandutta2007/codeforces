//CF 794E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[333333],b[333333];
int main()
{
	int n,i,x,y;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	for(i=1;i<=n;i=i+1)
	{
		x=(i-1)-(n-i);
		if(x<0)
			x=-x;
		b[x]=max(b[x],a[i]);
	}
	for(i=1;i<n;i=i+1)
	{
		x=(i-1)-(n-i-1);
		if(x<0)
			x=-x;
		b[x]=max(b[x],min(a[i],a[i+1]));
	}
	for(i=2;i<=n;i=i+1)
		b[i]=max(b[i],b[i-2]);
	for(i=1;i<n;i=i+1)
		cout<<b[i]<<' ';
	cout<<b[n-1]<<endl;
	return 0;
}