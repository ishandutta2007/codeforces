#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Point
{
	int x,y;
}p[1005];
int t,n;
bool cmp(Point a,Point b)
{
	return a.x+a.y<b.x+b.y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
		sort(p+1,p+n+1,cmp);
		bool f=1;
		for(int i=2;i<=n;i++)
		{
			if(p[i].x<p[i-1].x||p[i].y<p[i-1].y)
			{
				f=0;
				break;
			}
		}
		if(!f)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int nowx=0,nowy=0;
		for(int i=1;i<=n;i++)
		{
			while(nowx<p[i].x)
			{
				putchar('R');
				nowx++;
			}
			while(nowy<p[i].y)
			{
				putchar('U');
				nowy++;
			}
		}
		putchar('\n');
	}
	return 0;
}