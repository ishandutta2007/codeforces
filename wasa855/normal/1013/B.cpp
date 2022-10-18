#include<bits/stdc++.h>
using namespace std;
int a[100005];
int mp[100005];
int main()
{
	int m,x;
	cin>>m>>x;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		if(mp[a[i]]==1)
		{
			cout<<"0\n";
			return 0;
		}
		mp[a[i]]=1;
	}
	bool _2=false;
	for(int i=1;i<=m;i++)
	{
		int t=a[i]&x;
		if(t==a[i])
		{
			continue;
		}
		if(mp[t]==1)
		{
			cout<<"1\n";
			return 0;
		}
		if(mp[t]==2)
		{
			_2=true;
		}
		mp[t]=2;
	}
	if(_2==true)
	{
		cout<<"2\n";
		return 0;
	}
	cout<<"-1\n";
	return 0;
}