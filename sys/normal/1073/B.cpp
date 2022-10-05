#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int a[Maxn],b[Maxn],pnt,n;
bool vis[Maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(!vis[b[i]])
		{
			int ans=0;
			vis[b[i]]=true;
			while(a[pnt]!=b[i]) ans++,vis[a[pnt]]=true,pnt++;
			printf("%d ",ans);
		}
		else
			printf("0 ");
	}
	return 0;
}