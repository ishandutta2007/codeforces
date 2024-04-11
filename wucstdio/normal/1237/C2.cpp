#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Point
{
	int x,y,z;
	int id;
}p[50005];
int n;
bool flag[50005];
bool cmp(Point a,Point b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.z<b.z);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(flag[p[i].id])continue;
		if(i!=n&&p[i].x==p[i+1].x&&p[i].y==p[i+1].y)
		{
			printf("%d %d\n",p[i].id,p[i+1].id);
			flag[p[i].id]=flag[p[i+1].id]=1;
		}
		else p[i].z=p[i].y,p[i].y=p[i].x,p[i].x=1000000000;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(flag[p[i].id])continue;
		if(i!=n&&p[i].x==p[i+1].x&&p[i].y==p[i+1].y)
		{
			printf("%d %d\n",p[i].id,p[i+1].id);
			flag[p[i].id]=flag[p[i+1].id]=1;
		}
		else p[i].z=p[i].y,p[i].y=p[i].x,p[i].x=1000000000;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(flag[p[i].id])continue;
		if(i!=n&&p[i].x==p[i+1].x&&p[i].y==p[i+1].y)
		{
			printf("%d %d\n",p[i].id,p[i+1].id);
			flag[p[i].id]=flag[p[i+1].id]=1;
		}
		else p[i].z=p[i].y,p[i].y=p[i].x,p[i].x=1000000000;
	}
	return 0;
}