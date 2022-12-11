#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point
{
   	ll x,y;
    Point(ll x=0,ll y=0):x(x),y(y){}
    inline void read()
    {
        scanf("%lld%lld",&x,&y);
    }
};
typedef vector<Point> Polygon;
typedef Point Vector;

inline Vector operator + (Vector A, Vector B)
{
    return Vector(A.x+B.x, A.y+B.y);
}
inline Vector operator - (Point A, Point B)
{
    return Vector(A.x-B.x, A.y-B.y);
}
inline bool operator < (Point a, Point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
inline bool operator == (Point a,Point b)
{
	return (a.x==b.x)&&(a.y==b.y);
}
ll Cross(Vector A,Vector B)
{
	return A.x*B.y-A.y*B.x;
}
ll Dot(Vector A,Vector B)
{
	return A.x*B.x+A.y*B.y;
}
ll Length2(Vector A)
{
	return Dot(A,A);
}
vector<Point> ConvexHull(vector<Point>& p)
{
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    int m = 0;
    vector<Point> ch(n+1);
    for(int i = 0; i < n; i++)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--)
    {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    ch.resize(m);
    return ch;
}
#define maxn 400005
int n,m;
vector<Point> A,B;
ll xp1[maxn],xp2[maxn];
ll ha1[maxn],ha2[maxn],hb1,hb2;
const ll bas1=31,bas2=37;
const ll mod1=998244353,mod2=1000000007,offset=1000000009;
ll fastpow(ll a,ll p,ll mod)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x,ll mod)
{
	x%=mod;
	return fastpow(x,mod-2,mod);
}
ll gethash(int l,int r)
{
	ll x=ha1[r]-ha1[l-1]*xp1[r-l+1]%mod1;
    x=(x%mod1+mod1)%mod1;
    ll y=ha2[r]-ha2[l-1]*xp2[r-l+1]%mod2;
    y=(y%mod2+mod2)%mod2;
    return x*offset+y; 
}
const double PI=acos(-1);
int main()
{
	xp1[0]=xp2[0]=1;
	for(int i=1;i<=400000;++i)
	{
		xp1[i]=xp1[i-1]*bas1%mod1;
		xp2[i]=xp2[i-1]*bas2%mod2;
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		Point p;
		p.read();
		A.push_back(p); 
	}
	for(int i=1;i<=m;++i)
	{
		Point p;
		p.read();
		B.push_back(p);
	}
	A=ConvexHull(A);
	B=ConvexHull(B);
	n=A.size();m=B.size();
	if(n!=m)
	{
		puts("NO");
		return 0;
	}
	A.push_back(A[0]);
	B.push_back(B[0]);
	for(int i=1;i<=n;++i)
	{
		int x=i-1,y=(i+1)%n;
		ll d=Dot(A[x]-A[i],A[y]-A[i]),vx=Length2(A[x]-A[i]),vy=Length2(A[y]-A[i]);
		ll d1=(d%mod1+mod1)%mod1,vx1=vx%mod1,vy1=vy%mod1;
		ll d2=(d%mod2+mod2)%mod2,vx2=vx%mod2,vy2=vy%mod2;
		d1=d1*d1%mod1;d2=d2*d2%mod2;
		if(d<0)d1=(mod1-d1)%mod1,d2=(mod2-d2)%mod2; 
		ha1[i*2-1]=(ha1[i*2-2]*bas1%mod1+vx1)%mod1;
		ha1[i*2]=(ha1[i*2-1]*bas1%mod1+d1*inv(vx1,mod1)%mod1*inv(vy1,mod1)%mod1)%mod1;
		ha2[i*2-1]=(ha2[i*2-2]*bas2%mod2+vx2)%mod2;
		ha2[i*2]=(ha2[i*2-1]*bas2%mod2+d2*inv(vx2,mod2)%mod2*inv(vy2,mod2)%mod2)%mod2;
	}
	for(int i=n+1;i<=2*n;++i)
	{
		int x=(i-1)%n,y=(i+1)%n;
		ll d=Dot(A[x]-A[i%n],A[y]-A[i%n]),vx=Length2(A[x]-A[i%n]),vy=Length2(A[y]-A[i%n]);
		ll d1=(d%mod1+mod1)%mod1,vx1=vx%mod1,vy1=vy%mod1;
		ll d2=(d%mod2+mod2)%mod2,vx2=vx%mod2,vy2=vy%mod2;
		d1=d1*d1%mod1;d2=d2*d2%mod2;
		if(d<0)d1=(mod1-d1)%mod1,d2=(mod2-d2)%mod2; 
		ha1[i*2-1]=(ha1[i*2-2]*bas1%mod1+vx1)%mod1;
		ha1[i*2]=(ha1[i*2-1]*bas1%mod1+d1*inv(vx1,mod1)%mod1*inv(vy1,mod1)%mod1)%mod1;
		ha2[i*2-1]=(ha2[i*2-2]*bas2%mod2+vx2)%mod2;
		ha2[i*2]=(ha2[i*2-1]*bas2%mod2+d2*inv(vx2,mod2)%mod2*inv(vy2,mod2)%mod2)%mod2;
	}
	for(int i=1;i<=n;++i)
	{
		int x=i-1,y=(i+1)%n;
		ll d=Dot(B[x]-B[i],B[y]-B[i]),vx=Length2(B[x]-B[i]),vy=Length2(B[y]-B[i]);
		ll d1=(d%mod1+mod1)%mod1,vx1=vx%mod1,vy1=vy%mod1;
		ll d2=(d%mod2+mod2)%mod2,vx2=vx%mod2,vy2=vy%mod2;
		d1=d1*d1%mod1;d2=d2*d2%mod2;
		if(d<0)d1=(mod1-d1)%mod1,d2=(mod2-d2)%mod2;
		hb1=(hb1*bas1%mod1+vx1)%mod1;
		hb1=(hb1*bas1%mod1+d1*inv(vx1,mod1)%mod1*inv(vy1,mod1)%mod1)%mod1;
		hb2=(hb2*bas2%mod2+vx2)%mod2;
		hb2=(hb2*bas2%mod2+d2*inv(vx2,mod2)%mod2*inv(vy2,mod2)%mod2)%mod2;
	}
	ll HB=hb1*offset+hb2;
	bool yes=0;
	for(int i=1;i<=2*n;++i)
	{
		ll t=gethash(i,i+2*n-1);
		if(t==HB)yes=1;
	}
	if(yes)puts("YES");
	else puts("NO");
}