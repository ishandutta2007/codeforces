#include <stdio.h>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct Point
{
	long long x,y;
	inline long long operator + (const Point & b) const
	{
		return (x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
	}
	inline Point operator - (const Point &b) const
	{
		Point c;
		c.x=x-b.x;
		c.y=y-b.y;
		return c;
	}
	inline Point operator * (const Point &b) const
	{
		Point c;
		c.x=x+b.x;
		c.y=y+b.y;
		return c;
	}
	inline bool operator < (const Point &b) const
	{
		if(y==b.y) return x<b.x;
		return y<b.y;
	}
} Points[4],p[4],pp[4];
pair<Point,Point> ps[4];
vector<long long> vec;
bool Check(Point a[])
{
	int i,j;
	vec.clear();
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			vec.push_back(a[i]+a[j]);
		}
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<4;i++)
	{
		if(vec[0]!=vec[i]) return false;
	}
	for(i=4;i<6;i++)
	{
		if(2*vec[0]!=vec[i]) return false;
	}
	if(vec[0]==0) return false;
	return true;
	/*int i,j=3;
	int s=-1;
	for(i=0;i<4;i++)
	{
		int tmp=a[i]+a[j];
		if(s==-1) s=tmp;
		if(s!=tmp) return false;
		j=i;
	}
	if((a[0]+a[1])+(a[1]+a[2])!=a[0]+a[2]) return false;
	return true;*/
}
Point Rotate(Point a, Point b)
{
	a=a-b;
	Point c;
	c.y=a.x;
	c.x=-a.y;
	c=c*b;
	return c;
}
Point Rotate(Point a, Point b, int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		a=Rotate(a,b);
	}
	return a;
}
int Orientation(Point p, Point q, Point r)
{
	long long o=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	if(o>0) return 1;
	return 2;
}
bool Compare(Point a, Point b)
{
	int o=Orientation(Points[0],a,b);
	if(o==0) return Points[0]+a<Points[0]+b;
	if(o==2) return true;
	return false;
}
int Matrix[300][4];
int time;
void BuildMatrix(int x, int pos)
{
	int i,j;
	for(i=1;i<256;i++)
	{
		time++;
		for(j=0;j<4;j++)
			Matrix[i][j]=Matrix[i-1][j];
		Matrix[i][0]++;
		for(j=0;j<3;j++)
		{
			if(Matrix[i][j]==4)
			{
				Matrix[i][j]=0;
				Matrix[i][j+1]++;
			}
		}
	}
	//if(Matrix[x][pos]==3) return;
	//time++;
	//int i;
	//for(i=0;i<4;i++) Matrix[time][i]=Matrix[x][i];
	//Matrix[time][pos]=Matrix[x][pos]+1;
	//for(i=pos;i<4;i++)
	//{
	//	BuildMatrix(time,i);
	//}
}
void swap(Point &a, Point &b)
{
	Point tmp=a;
	a=b;
	b=tmp;
}
int solve()
{
	int i,j,sum=0,sol=-1,soli=-1;
	for(i=0;i<=time;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			sum+=Matrix[i][j];
			pp[j]=Rotate(Points[j],p[j],Matrix[i][j]);
		}
		//int t=0;
		//for(j=1;j<4;j++) if(pp[j]<pp[t]) t=j;
		//swap(pp[0],pp[t]);
		//sort(pp+1,pp+4,Compare);
		if(Check(pp)) if(sol==-1 || sol>sum) sol=sum,soli=i;
		//if(sum==1 && Matrix[i][1]==1) printf("\n%i\n",Check(pp));
	}
	//if(soli!=-1)
	//{
	//	for(j=0;j<4;j++) printf("%i ",Matrix[soli][j]);
	//	printf("\n");
	//}
	return sol;
}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	BuildMatrix(0,0);
	//for(i=0;i<=time;i++) printf("%i %i %i %i\n",Matrix[i][0],Matrix[i][1],Matrix[i][2],Matrix[i][3]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%lld %lld %lld %lld",&Points[j].x,&Points[j].y,&p[j].x,&p[j].y);
		}
		printf("%i\n",solve());
	}
	//printf("%i %i %i %i %i %i\n",Points[0].x,Points[0].y,p[0].x,p[0].y,Rotate(Points[0],p[0],2).x,Rotate(Points[0],p[0],2).y);
	return 0;
}