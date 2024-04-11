#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
struct P{int X,Y;}s,e,a[120],u,v;
int n;
double l[120],L=1,R,Li,Ri,T,Ti;
int xm(P a,P b,P c)
{
	return (b.X-a.X)*(c.Y-a.Y)-(c.X-a.X)*(b.Y-a.Y);
}
double C(double x)
{
	int t=int(x);
	return l[t]+(x-t)*(l[t+1]-l[t]);
}
double ud(double x,double y)
{
	if(x>R)
		R=x,Ri=y;
	if(x<L)
		L=x,Li=y;
}
double D(P a,P b)
{
	return hypot(a.X-b.X,a.Y-b.Y);
}
int main()
{
	cin>>s.X>>s.Y>>e.X>>e.Y>>n;
	fr(i,n)
		cin>>a[i].X>>a[i].Y;
	a[n]=a[0];
	fr(i,n)
	{
		u=a[i],v=a[i+1];
		if(xm(s,e,u)*xm(s,e,v)<0&&xm(u,v,s)*xm(u,v,e)<0)
		{
			T=(double)xm(u,v,s)/(xm(u,v,s)+xm(v,u,e));
			Ti=i+(double)xm(s,e,u)/(xm(s,e,u)+xm(e,s,v));
			ud(T,Ti);
		}
	}
	fr(i,n)
		if(fabs(D(s,e)-D(s,a[i])-D(a[i],e))<1e-8)
			ud(D(s,a[i])/D(s,e),i);
	fr(i,n)
		l[i+1]=l[i]+D(a[i],a[i+1]);
	if(L>R)
		printf("%.9f",D(s,e));
	else
	{
		double dl=C(Li),dr=C(Ri);
		if(dl>dr)
			swap(dl,dr);
		printf("%.9f",min(D(s,e)*(1+R-L),D(s,e)*(1-R+L)+min(dr-dl,l[n]+dl-dr)));
	}
	return 0;
}