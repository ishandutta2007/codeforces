#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=100050;
struct Point
{
	int x,y;
	Point(){}
	Point(int a, int b){ x=a,y=b;}	
} P[N];
int Orientation(Point p, Point q, Point r)
{
	ll o=(ll)(q.y-p.y)*(r.x-q.x)-(ll)(q.x-p.x)*(r.y-q.y);
	if(o==0) return 0;
	return o>0?2:1;
}
int n;
bool Solve(Point a, Point b)
{
	vector<Point> p;
	int i;
	for(i=1;i<=n;i++)
	{
		if(Orientation(a,b,P[i])) p.pb(P[i]);
	}
	for(i=2;i<p.size();i++) if(Orientation(p[i],p[i-1],p[i-2])) return 0;
	//printf("A:(%i %i) B:(%i %i)\n",a.x,a.y,b.x,b.y);
	//for(i=0;i<p.size();i++) printf("P:(%i %i)\n",p[i].x,p[i].y);
	return 1;
}
int main()
{
	scanf("%i",&n);
	int i,j=0;
	for(i=1;i<=n;i++) scanf("%i %i",&P[i].x,&P[i].y);
	if(n<5) return printf("YES\n"),0;
	for(i=3;i<=n;i++)
	{
		if(Orientation(P[1],P[2],P[i])) j=i;
	}
	if(!j) return printf("YES\n"),0;
	if(Solve(P[2],P[1])) return printf("YES\n"),0;
	if(Solve(P[2],P[j])) return printf("YES\n"),0;
	if(Solve(P[1],P[j])) return printf("YES\n"),0;
	printf("NO\n");
	return 0;
}