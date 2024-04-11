#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int a,b;
int ans=0;
int n=0,m=0;
bool vis[Maxn];
int main()
{
	scanf("%d%d",&a,&b);
	long long tot=0;
	while (tot+ans+1<=a+b)
	{
		++ans;
		tot+=ans;
	}
	for (int i=ans;i;i--)
	{
		if ((!vis[i])&&(a>=i))
		{
			vis[i]=true;
			++n;
			a-=i;
		}
	}
	printf("%d\n",n);
	for (int i=1;i<=ans;i++)
		if (vis[i]) printf("%d ",i);
	printf("\n");
	printf("%d\n",ans-n);
	for (int i=1;i<=ans;i++)
		if (!vis[i]) printf("%d ",i);
	printf("\n");
	return 0;
}