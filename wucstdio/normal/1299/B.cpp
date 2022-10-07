#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
	Point(ll xx=0,ll yy=0){x=xx,y=yy;}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	ll det(Point p){return x*p.y-y*p.x;}
	bool operator!=(Point p){return x!=p.x||y!=p.y;}
}a[100005];
int n;
int main()
{
	scanf("%d",&n);
	if(n&1)return puts("NO"),0;
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=n/2;i++)
	{
		if((a[i+1]-a[i])!=(a[i+n/2]-a[(i+n/2)%n+1]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}