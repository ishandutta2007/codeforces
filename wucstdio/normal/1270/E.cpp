#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Point
{
	int x,y;
}p[1005];
int n,num;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)
	  if((p[i].x+p[i].y)%2)
		num++;
	while(num==0||num==n)
	{
		num=0;
		for(int i=1;i<=n;i++)
		{
			if((p[i].x+p[i].y)%2)
			  p[i].y++;
			int x=p[i].x,y=p[i].y;
			p[i].x=(x+y)/2,p[i].y=(x-y)/2;
			if((p[i].x+p[i].y)%2)num++;
		}
	}
	printf("%d\n",num);
	for(int i=1;i<=n;i++)
	  if((p[i].x+p[i].y)%2)
	    printf("%d ",i);
	printf("\n");
	return 0;
}