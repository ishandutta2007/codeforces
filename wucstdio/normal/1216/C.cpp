#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Point
{
	int x,y;
}p[7];
int main()
{
	for(int i=1;i<=6;i++)scanf("%d%d",&p[i].x,&p[i].y);
	if(p[3].x<=p[1].x&&p[3].y<=p[1].y&&p[4].x>=p[2].x&&p[4].y>=p[2].y)
	{
		printf("NO\n");
		return 0;
	}
	if(p[5].x<=p[1].x&&p[5].y<=p[1].y&&p[6].x>=p[2].x&&p[6].y>=p[2].y)
	{
		printf("NO\n");
		return 0;
	}
	if(p[3].x<=p[1].x&&p[4].x>=p[2].x&&p[5].x<=p[1].x&&p[6].x>=p[2].x)
	{
		if(p[3].y<=p[1].y&&p[4].y>=p[5].y&&p[6].y>=p[2].y)
		{
			printf("NO\n");
			return 0;
		}
		if(p[5].y<=p[1].y&&p[6].y>=p[3].y&&p[4].y>=p[2].y)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(p[3].y<=p[1].y&&p[4].y>=p[2].y&&p[5].y<=p[1].y&&p[6].y>=p[2].y)
	{
		if(p[3].x<=p[1].x&&p[4].x>=p[5].x&&p[6].x>=p[2].x)
		{
			printf("NO\n");
			return 0;
		}
		if(p[5].x<=p[1].x&&p[6].x>=p[3].x&&p[4].x>=p[2].x)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}