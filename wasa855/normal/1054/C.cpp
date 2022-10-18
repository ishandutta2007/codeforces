#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int l,r;
	int v;
};
Node a[1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].l);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].r);
	}
	for(int i=1;i<=n;i++)
	{
		a[i].v=n-a[i].l-a[i].r;
	}
	for(int i=1;i<=n;i++)
	{
		int suml=0,sumr=0;
		for(int j=1;j<i;j++)
		{
			if(a[j].v>a[i].v)
			{
				suml++;
			}
		}
		for(int j=i+1;j<=n;j++)
		{
			if(a[j].v>a[i].v)
			{
				sumr++;
			}
		}
		if(suml!=a[i].l||sumr!=a[i].r)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i].v);
	}
	cout<<"\n";
	return 0;
}
//weasyufr