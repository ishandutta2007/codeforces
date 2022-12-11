#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n,a[Maxn],ans=0;
bool vis[Maxn];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++)
		if (a[i]==0) ++ans;
		else
		{
			if (vis[a[i]]) ++ans;
			vis[a[i]]=true;
		}
	printf("%d\n",ans);
	return 0;
}