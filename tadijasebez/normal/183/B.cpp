#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct pt{ ll x,y;pt(ll a=0, ll b=0):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
ll cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
struct line{ pt p;ll c;line(){}line(pt a, pt b):p(a-b),c(cross(p,a)){}};
bool online(line a, pt x){ return cross(a.p,x)==a.c;}
bool check(line a, ll y){ return a.p.y!=0 && (a.p.x*y-a.c)%a.p.y==0;}
ll val(line a, ll y){ return (a.p.x*y-a.c)/a.p.y;}
const int N=1000050;
int mx[N];
int main()
{
	int n,m,i,j,k;
	vector<pt> ps;
	scanf("%i %i",&n,&m);
	ps.resize(m);
	for(i=0;i<m;i++) scanf("%lld %lld",&ps[i].x,&ps[i].y);
	for(i=0;i<m;i++) for(j=i+1;j<m;j++)
	{
		line l=line(ps[i],ps[j]);
		int cnt=0;
		for(k=0;k<m;k++) if(online(l,ps[k])) cnt++;
		if(check(l,0))
		{
			ll sec=val(l,0);
			if(sec>0 && sec<=n) mx[sec]=max(mx[sec],cnt);
		}
	}
	int ans=0;
	for(i=1;i<=n;i++) ans+=max(mx[i],1);
	printf("%i\n",ans);
	return 0;
}