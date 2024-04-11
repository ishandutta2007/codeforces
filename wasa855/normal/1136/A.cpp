#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int l,r;
};
Node a[105];
int main()
{
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].l,&a[i].r);
	}
	cin>>m;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].l<=m&&a[i].r>=m)
		{
			ans=i;
			break;
		}
	}
	cout<<n-ans+1<<endl;
	return 0;
}