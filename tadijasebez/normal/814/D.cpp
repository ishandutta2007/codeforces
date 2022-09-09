#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
const ldb PI=acos(-1);
const int N=1050;
const ll inf=1e18;
struct pt{ ll x,y;pt(){}pt(ll a, ll b):x(a),y(b){}};
pt operator - (pt a, pt b){ return pt(a.x-b.x,a.y-b.y);}
pt operator + (pt a, pt b){ return pt(a.x+b.x,a.y+b.y);}
pt operator / (pt a, ll b){ return pt(a.x/b,a.y/b);}
ll cross(pt a, pt b){ return a.x*b.y-a.y*b.x;}
ll dot(pt a, pt b){ return a.x*b.x+a.y*b.y;}
ll sq(pt a){ return dot(a,a);}
ll dist_sq(pt a, pt b){ return sq(a-b);}
struct seg{ pt a,b;seg(){}seg(pt x, pt y):a(x),b(y){}};
bool on_disc(seg a, pt b){ return dot(a.a-b,a.b-b)<=0;}
seg cir[N];
int par[N],dep[N];
ll sz[N];
int main()
{
	int n,x,y,r,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&x,&y,&r);
		cir[i]=seg(pt(x-r,y),pt(x+r,y));
	}
	sort(cir+1,cir+1+n,[&](seg x, seg y){ return x.b.x-x.a.x>y.b.x-y.a.x;});
	ll ans=0;
	vector<int> root;
	for(i=1;i<=n;i++)
	{
		pt m1=(cir[i].a+cir[i].b)/2;
		ll r1=m1.x-cir[i].a.x;
		for(j=i-1;j>=1;j--)
		{
			pt m2=(cir[j].a+cir[j].b)/2;
			ll r2=m2.x-cir[j].a.x;
			if(dist_sq(m1,m2)+r1*r1<=r2*r2)
			{
				par[i]=j;
				break;
			}
		}
		dep[i]=dep[par[i]]+1;
		sz[i]=r1*r1;
		if(dep[i]==1 || dep[i]%2==0) ans+=sz[i];
		else ans-=sz[i];
	}
	cout<<fixed<<setprecision(12)<<PI*ans<<"\n";
	return 0;
}