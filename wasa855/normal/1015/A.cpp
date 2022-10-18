#include<bits/stdc++.h>
using namespace std;
bool can[105];
int main()
{
	int n,m;
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&u,&v);
		for(int j=u;j<=v;j++)
		{
			can[j]=true;
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		if(can[i]==false)
		{
			sum++;
		}
	}
	cout<<sum<<endl;
	for(int i=1;i<=m;i++)
	{
		if(can[i]==false)
		{
			printf("%d ",i);
		}
	}
	return 0;
}