#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
double a,b,c;
double x1,yy,x2,y2;
double ans;
int dcmp(double x)
{
	if(fabs(x)<eps)return 0;
	if(x<0)return -1;
	return 1;
}
struct point
{
	double x,y;
	point(){}
	point(double X,double Y)
	{
		x=X;y=Y;
	}
};
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point p1[3],p2[3];
point A,B;
int main()
{
	cin>>a>>b>>c>>x1>>yy>>x2>>y2;
	A=point(x1,yy);
	B=point(x2,y2);
	ans=fabs(x1-x2)+abs(yy-y2);
	if(!dcmp(a)||!dcmp(b))
	{
		printf("%.10lf\n",ans);
		return 0;
	}
	p1[1]=point(-b/a*yy-c/a,yy);
	p1[2]=point(x1,-a/b*x1-c/b);
	p2[1]=point(-b/a*y2-c/a,y2);
	p2[2]=point(x2,-a/b*x2-c/b);
	for(int i=1;i<=2;++i)
	{
		for(int j=1;j<=2;++j)ans=min(ans,dist(A,p1[i])+dist(p1[i],p2[j])+dist(p2[j],B));
	}
	printf("%.10lf\n",ans);
	return 0;
}