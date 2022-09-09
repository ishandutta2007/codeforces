#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
const int N=100050;
const ll inf=(ll)1000000000*1000000000;
struct Point
{
	int x,y;
	Point(){}
	Point(int a, int b):x(a),y(b){}
	inline ll operator + (const Point &b) const
	{
		return (ll)(x-b.x)*(x-b.x)+(ll)(y-b.y)*(y-b.y);
	}
} P[N],L[N];
ll min(ll a, ll b){ return a>b?b:a;}
bool CompareX(Point a, Point b){ return a.x<b.x;}
bool CompareY(Point a, Point b){ return a.y<b.y;}
void Swap(Point &a, Point &b)
{
	Point tmp=a;
	a=b;
	b=tmp;
}
ll BruteForce(int ss, int se)
{
	//sort(P+ss,P+se+1,CompareY);
	if(P[ss].y>P[se].y) Swap(P[ss],P[se]);
	int i,j;
	ll sol=inf;
	for(i=ss;i<=se;i++) for(j=i+1;j<=se;j++) sol=min(sol,P[i]+P[j]);
	return sol;
}
ll Consider(vector<Point> p, ll sol)
{
	//sort(p.begin(),p.end(),CompareY);
	int i,j,n;
	n=p.size();
	for(i=0;i<n;i++)
		for(j=i+1;j<n && sol>(p[j].y-p[i].y)*(p[j].y-p[i].y);j++)
			sol=min(sol,p[i]+p[j]);
	return sol;
}
ll Solve(int ss, int se)
{
	if(se-ss<2) return BruteForce(ss,se);
	int mid=ss+se>>1;
	int tmp=P[mid].x;
	ll sol=min(Solve(ss,mid),Solve(mid+1,se));
	int i=ss,j=mid+1,k;
	for(k=ss;k<=se;k++)
	{
		if(i<=mid && (j>se || P[i].y<P[j].y)) L[k]=P[i++];
		else L[k]=P[j++];
	}
	for(k=ss;k<=se;k++) P[k]=L[k];
	vector<Point> p;
	ll root=floor(sqrt(sol));
	for(i=ss;i<=se;i++) if(abs(P[i].x-tmp)<root) p.push_back(P[i]);
	return min(sol,Consider(p,sol));
}
int main()
{
	int n,x,p=0,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		p+=x;
		P[i]=Point(i,p);
	}	
	printf("%lld\n",Solve(1,n));
	return 0;
}