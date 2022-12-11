#include <bits/stdc++.h>
using namespace std;
int h1,c1,a1,h2,a2;
bool vis[10007];
int ans=0;
int main()
{
	scanf("%d%d%d",&h1,&a1,&c1);
	scanf("%d%d",&h2,&a2);
	while (h2>0)
	{
		++ans;
		if (h1<=a2&&h2>a1)
		{
			h1+=c1-a2;
			vis[ans]=true;
		}
		else
		{
			h1-=a2;
			h2-=a1;
			vis[ans]=false;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
		if (vis[i]) printf("HEAL\n"); else printf("STRIKE\n");
	return 0;
}