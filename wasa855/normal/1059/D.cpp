#include<bits/stdc++.h>
using namespace std;
struct Node
{
	double x;
	double y;
};
Node a[100005];
int n;
double count(double x)
{
	double maxn=0;
	for(int i=1;i<=n;i++)
	{
		double t=abs((a[i].x-x)*(a[i].x-x)+(a[i].y*a[i].y))/(2.0*a[i].y);
		if(t>maxn)
		{
			maxn=t;
		}
	}
	return maxn;
}
int main()
{
	cin>>n;
	bool up=false;
	bool low=false;
	double l=0.0,r=0.0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a[i].x,&a[i].y);
		if(a[i].y>0)
		{
			up=true;
		}
		if(a[i].y<0)
		{
			low=true;
		}
		if(a[i].x<l)
		{
			l=a[i].x;
		}
		if(a[i].x>r)
		{
			r=a[i].x;
		}
	}
	if(up==true&&low==true)
	{
		cout<<"-1\n";
		return 0;
	}
	if(low==true)
	{
		for(int i=1;i<=n;i++)
		{
			a[i].y=-a[i].y;
		}
	}
	while(r-l>1e-8)
	{
		double x=(2.0*l+r)/3.0;
		double y=(l+2.0*r)/3.0;
		if(count(x)>count(y))
		{
			l=x;
		}
		else
		{
			r=y;
		}
	}
	printf("%.7lf\n",count(l));
	return 0;
}