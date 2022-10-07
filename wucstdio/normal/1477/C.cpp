#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct Point
{
	double x,y;
	Point(double xx=0,double yy=0){x=xx,y=yy;}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	double dot(Point p){return x*p.x+y*p.y;}
	double abs2(){return x*x+y*y;}
}a[5005];
int n;
bool flag[5005];
int main()
{
	scanf("%d",&n);
	int now=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i].x,&a[i].y);
		if(a[i].x<a[now].x)now=i;
	}
	printf("%d ",now);
	flag[now]=1;
	int last=now;
	for(int t=1;t<=n-1;t++)
	{
		for(int i=1;i<=n;i++)
		{
			if(flag[i])continue;
			if(flag[now]||((a[i]-a[last]).abs2()>(a[now]-a[last]).abs2()))now=i;
		}
		printf("%d ",now);
		flag[now]=1;
		last=now;
	}
	printf("\n");
	return 0;
}