#include <bits/stdc++.h>
#define inf 2000007
using namespace std;
struct node
{
	int x1,y1,x2,y2;
};
node a,b;
int main()
{
	a.x1=inf,a.y1=inf,a.x2=-inf,a.y2=-inf;
	b.x1=inf,b.y1=inf,b.x2=-inf,b.y2=-inf;
	for (int i=1;i<=4;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a.x1=min(a.x1,x);
		a.y1=min(a.y1,y);
		a.x2=max(a.x2,x);
		a.y2=max(a.y2,y);
	}
	for (int i=1;i<=4;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		b.x1=min(b.x1,x);
		b.y1=min(b.y1,y);
		b.x2=max(b.x2,x);
		b.y2=max(b.y2,y);
	}
	bool check=false;
	for (int i=a.x1;i<=a.x2;i++)
		for (int j=a.y1;j<=a.y2;j++)
		{
			if (i>=b.x1&&i<=(b.x1+b.x2)/2)
			{
				if (j>=b.y1+(b.x1+b.x2)/2-i&&j<=b.y2-(b.x1+b.x2)/2+i) check=true;
			}
			if (i>=(b.x1+b.x2)/2&&i<=b.x2)
			{
				if (j>=b.y1-(b.x1+b.x2)/2+i&&j<=b.y2+(b.x1+b.x2)/2-i) check=true;
			}
		}
	if (check) printf("YES\n"); else printf("NO\n");
	return 0;
}