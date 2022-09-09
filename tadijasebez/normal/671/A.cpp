#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100050;
#define ll long long
#define pb push_back
#define mp make_pair
struct Point
{
	ll x,y;
	Point(ll a=0, ll b=0){ x=a,y=b;}
	double operator ^ (Point b) const { return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));}
} A,B,R,P[N];
double min(double a, double b){ return a>b?b:a;}
vector<pair<double,int> > a,b;
int main()
{
	int n,i;
	scanf("%lld %lld %lld %lld %lld %lld",&A.x,&A.y,&B.x,&B.y,&R.x,&R.y);
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld %lld",&P[i].x,&P[i].y);
	double sol=0;
	for(i=1;i<=n;i++) sol+=(R^P[i])*2;
	for(i=1;i<=n;i++) a.pb(mp((A^P[i])-(R^P[i]),i));
	for(i=1;i<=n;i++) b.pb(mp((B^P[i])-(R^P[i]),i));
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if(a[0].second!=b[0].second)
	{
		double add=min(a[0].first+b[0].first,min(a[0].first,b[0].first));
		printf("%.12llf\n",sol+add);
	}
	else
	{
		double add=min(min(a[0].first+b[1].first,a[1].first+b[0].first),min(a[0].first,b[0].first));
		printf("%.12llf\n",sol+add);
	}
	return 0;
}