#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int a,b,c,d;
bool vis[2][1500010];

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	memset(vis,false,sizeof(vis));
	while(b<=1200000)
	{
		vis[0][b] = true;
		b+=a;
	}
	while(d<=1200000)
	{
		vis[1][d] = true;
		d+=c;
	}
	for (int i=0;i<=1200000;i++)
	if (vis[0][i] && vis[1][i]) 
	{
		printf("%d\n",i);
		return 0;
	}
	puts("-1");
}