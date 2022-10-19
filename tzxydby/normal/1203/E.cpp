#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],vis[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	int ans=0; 
	for(int i=1;i<=150001;i++)
	{
		if(!vis[i])
		{
			if(a[i])
			{
				a[i]--;
				vis[i]=1;
			}
			else if(a[i+1])
			{
				a[i+1]--;
				vis[i]=1;
			}
		}
		if(vis[i]&&a[i])
		{
			a[i]--;
			vis[i+1]=1;
		}
		ans+=vis[i];
	}
	printf("%d\n",ans);
	return 0;
}