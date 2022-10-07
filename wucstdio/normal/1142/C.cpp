#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const double EPS=1e-9;
struct Point
{
	ll x,y;
}p[200005];
struct Line
{
	ll a,c;
}a[200005];
int n,st[100005],top;
bool cmp(Line a,Line b)
{
	return a.a>b.a||(a.a==b.a&&a.c>b.c);
}
double cross(Line a,Line b)
{
	double k1=(double)-a.a;
	double b1=(double)-a.c;
	double k2=(double)-b.a;
	double b2=(double)-b.c;
	return 1.0*(b2-b1)/(k1-k2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
		a[i].a=p[i].x;
		a[i].c=p[i].x*p[i].x-p[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].a==a[i+1].a)
		  a[i].a=-1000000000;
	}
	sort(a+1,a+n+1,cmp);
	while(a[n].a==-1000000000)n--;
	for(int i=1;i<=n;i++)
	{
		while(top>=2&&cross(a[st[top-1]],a[st[top]])>cross(a[i],a[st[top-1]])-EPS)top--;
		st[++top]=i;
	}
	printf("%d\n",top-1);
	return 0;
}