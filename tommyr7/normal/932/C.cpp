#include <bits/stdc++.h>
#define Maxn 1000007
using namespace std;
int p[Maxn];
int n,a,b,x,y;
bool flag=false;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (x=0;x*a<=n;x++)
		if ((n-a*x)%b==0)
		{
			y=(n-a*x)/b;
			flag=true;
			break;
		}
	if (!flag) printf("%d\n",-1);
	else
	{
		int now=1;
		for (int i=1;i<=x;i++)
		{
			int pos=now;
			for (int j=1;j<a;j++)
			{
				p[now]=now+1;
				++now;
			}
			p[now]=pos;
			++now;
		}
		for (int i=1;i<=y;i++)
		{
			int pos=now;
			for (int j=1;j<b;j++)
			{
				p[now]=now+1;
				++now;
			}
			p[now]=pos;
			++now;
		}
		for (int i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}