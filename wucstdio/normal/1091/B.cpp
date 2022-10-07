#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
struct Point
{
	int x,y;
	Point(int xx=0,int yy=0){x=xx,y=yy;}
	Point operator+(Point a){return Point(x+a.x,y+a.y);}
	bool operator<(const Point&a)const
	{
		return x<a.x||x==a.x&&y<a.y;
	}
}a[1005],b[1005];
map<Point,int>m;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		for(int j=1;j<=n;j++)
		{
			m[a[j]+b[i]]++;
			if(m[a[j]+b[i]]==n)
			{
				printf("%d %d\n",(a[j]+b[i]).x,(a[j]+b[i]).y);
				return 0;
			}
		}
	}
	return 0;
}