#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int sum1=0,sum2=0;
	int t;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		sum1+=t;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		sum2+=t;
	}
	if(sum1>=sum2)
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}