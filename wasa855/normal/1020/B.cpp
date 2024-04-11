#include<bits/stdc++.h>
using namespace std;
int a[1005];
int used[1005];
int find(int x)
{
	memset(used,0,sizeof(used));
	used[x]++;
	while(1)
	{
		x=a[x];
		used[x]++;
		if(used[x]==2)
		{
			return x;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",find(i));
	}
	return 0;
}