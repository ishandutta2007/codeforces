#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool is[110];
int main()
{
	memset(is,false,sizeof(is));
	int n,m;
	cin>>n>>m;
	int l,r;
	for(int i=0;i<n;i++)
	{
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			is[i]=true;
		}
	}
	int cur=0;
	for(int i=1;i<=m;i++)
	{
		if(!is[i])
		{
			cur++;
		}
	}
	cout<<cur<<endl;
	for(int i=1;i<=m;i++)
	{
		if(!is[i])
		{
			cout<<i<<" ";
		}
	}
	return 0;
}