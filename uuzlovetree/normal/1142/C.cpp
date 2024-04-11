#include<bits/stdc++.h>
#define vec point
#define maxn 200005
#define pdd pair<double,double>
#define mp(a,b) make_pair(a,b)
using namespace std;
const double eps=1e-7;
int n;
struct point
{
	double x,y;
	point(double x=0,double y=0):x(x),y(y){}
}a[maxn],p[maxn],ch[maxn];
bool operator < (point A,point B)
{
	if(A.x==B.x)return A.y<B.y;
	return A.x<B.x;
}
pdd getu(point A,point B)
{
	double b=((A.y-A.x*A.x)-(B.y-B.x*B.x))/(A.x-B.x);
	double c=A.y-A.x*A.x-b*A.x;
	return pdd(b,c);
}
bool in(point A,pdd u)
{
	double b=u.first,c=u.second;
	if(A.y-(A.x*A.x+b*A.x+c)>-eps)return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<n;++i)if(fabs(a[i].x-a[i+1].x)>eps)p[++cnt]=a[i];
	p[++cnt]=a[n];
    int top=0;
    for(int i=cnt;i;i--)
    {
        while(top>1&&in(p[i],getu(ch[top],ch[top-1])))top--;
        ch[++top]=p[i];
    }
    printf("%d\n",top-1);
    return 0;
}