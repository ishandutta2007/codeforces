#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%1d",&a[i]);
	}
	int now0=0,now1=0;
	if(a[1]==0&&a[2]==0)
	{
		cout<<"No\n";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0)
		{
			now1=0;
			now0++;
			if(now0==3)
			{
				cout<<"No\n";
				return 0;
			}
		}
		else
		{
			now0=0;
			now1++;
			if(now1==2)
			{
				cout<<"No\n";
				return 0;
			}
		}
	}
	if(now0==2)
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}