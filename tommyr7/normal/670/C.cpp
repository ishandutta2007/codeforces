#include <bits/stdc++.h>
using namespace std;
int n,m,x,ans,ans1,ans2;
int A[200007],B[200007];
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	mp.clear();
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		++mp[x];
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		scanf("%d",&A[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&B[i]);
	ans1=0,ans2=0,ans=1;
	for (int i=1;i<=m;i++)
	{
		int a=A[i],b=B[i];
		if ((mp[a]>ans1)||(mp[a]==ans1&&mp[b]>ans2))
		{
			ans1=mp[a];
			ans2=mp[b];
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}