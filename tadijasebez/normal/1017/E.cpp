#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
struct Point{ int x,y;Point(int a=0, int b=0):x(a),y(b){}};
bool operator < (Point a, Point b){ return a.x<b.x || a.x==b.x && a.y<b.y;}
Point operator - (Point a, Point b){ return Point(a.x-b.x,a.y-b.y);}
ll operator ^ (Point a, Point b){ return (ll)a.x*b.y-(ll)b.x*a.y;}
ll operator * (Point a, Point b){ return (ll)a.x*b.x+(ll)a.y*b.y;}
ll side(Point a, Point b, Point c){ return (b-a)^(c-a);}
vector<Point> ConvexHull(vector<Point> a)
{
	vector<Point> ch;int sz=0;
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++){ while(sz>1 && side(ch[sz-2],ch[sz-1],a[i])<=0) ch.pop_back(),sz--;ch.pb(a[i]);sz++;}
	int tmp=sz;reverse(a.begin(),a.end());
	for(int i=1;i<a.size();i++){ while(sz>1 && sz>tmp && side(ch[sz-2],ch[sz-1],a[i])<=0) ch.pop_back(),sz--;ch.pb(a[i]);sz++;}
	sz--;ch.pop_back();
	return ch;
}
const int N=100050;
int go[N];
bool KMP(vector<pair<ll,ll> > a, vector<pair<ll,ll> > b)
{
	int n=a.size(),m=b.size();
	for(int i=0;i<n;i++) a.pb(a[i]);n*=2;
	for(int i=2;i<=b.size();i++){ go[i]=go[i-1];while(go[i] && b[go[i]]!=b[i-1]) go[i]=go[go[i]];if(b[go[i]]==b[i-1]) go[i]++;}
	int at=0;
	for(int i=0;i<a.size();i++){ while(at && b[at]!=a[i]) at=go[at];if(b[at]==a[i]) at++;if(at==m) return 1;}
	return 0;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	vector<Point> a,b;
	a.resize(n);b.resize(m);
	for(int i=0;i<n;i++) scanf("%i %i",&a[i].x,&a[i].y);
	for(int i=0;i<m;i++) scanf("%i %i",&b[i].x,&b[i].y);
	a=ConvexHull(a);b=ConvexHull(b);
	n=a.size();m=b.size();
	vector<pair<ll,ll> > sa,sb;
	//printf("A: ");
	for(int i=0;i<n;i++)
	{
		//printf("(%i, %i) ",a[i].x,a[i].y);
		int j=(i+1)%n,k=(j+1)%n;
		sa.pb(mp((a[i]-a[j])*(a[i]-a[j]),(a[i]-a[j])*(a[k]-a[j])));
	}
	//printf("\n");
	//printf("B: ");
	for(int i=0;i<m;i++)
	{
		//printf("(%i, %i) ",b[i].x,b[i].y);
		int j=(i+1)%m,k=(j+1)%m;
		sb.pb(mp((b[i]-b[j])*(b[i]-b[j]),(b[i]-b[j])*(b[k]-b[j])));
	}
	//printf("\n");
	if(KMP(sa,sb)) printf("YES\n");
	else printf("NO\n");
	return 0;
}