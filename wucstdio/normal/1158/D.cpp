#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double EPS=1e-9;
const double Pi=acos(-1.0);
struct Point
{
	double x,y;
	int id;
	Point(double xx=0,double yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	Point operator*(double d){return Point(x*d,y*d);}
	Point operator/(double d){return Point(x/d,y/d);}
	double dot(Point p){return x*p.x+y*p.y;}
	double det(Point p){return x*p.y-y*p.x;}
	double abs2(){return x*x+y*y;}
	double abs(){return sqrt(abs2());}
	Point unit(){return *this/abs();}
}p[2005];
char s[2005];
int n,ans[2005];
bool flag[2005];
bool cmp(Point a,Point b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	scanf("%s",s+1);
	sort(p+1,p+n+1,cmp);
	ans[1]=p[1].id;
	flag[1]=1;
	int now=1;
	for(int i=1;i<n;i++)
	{
		int nxt=0;
		for(int j=1;j<=n;j++)
		{
			if(flag[j])continue;
			if(!nxt)nxt=j;
			else
			{
				if(s[i]=='L')
				{
					if((p[j]-p[now]).det(p[nxt]-p[now])>0)
					  nxt=j;
				}
				else
				{
					if((p[j]-p[now]).det(p[nxt]-p[now])<0)
					  nxt=j;
				}
			}
		}
		flag[nxt]=1;
		ans[i+1]=p[nxt].id;
		now=nxt;
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}