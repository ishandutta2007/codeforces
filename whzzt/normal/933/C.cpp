#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;

const int N=15;
const double eps=1e-7;

struct P{
	double x,y;
	P(double _x=0,double _y=0){x=_x;y=_y;}
	friend bool operator<(const P&a,const P&b){
		if(fabs(a.x-b.x)>eps)
			return a.x<b.x;
		return a.y<b.y; 
	}
	friend bool operator==(const P&a,const P&b){
		return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;
	}
	friend P operator+(const P&a,const P&b){
		return P(a.x+b.x,a.y+b.y);
	}
	friend P operator-(const P&a,const P&b){
		return P(a.x-b.x,a.y-b.y);
	}
	double ang(){
		return atan2(y,x);
	}
	double len(){
		return sqrt(x*x+y*y);
	}
}p[N];
vector<P> poi;
vector<P> poc[N];

double r[N];
int n,E,V,fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
	cin>>n;
	fo(i,1,n)cin>>p[i].x>>p[i].y>>r[i],fa[i]=i;
	fo(i,1,n)fo(j,1,n)if(i!=j){
		double l=(p[j]-p[i]).len();
		if(r[i]+r[j]+eps<l||fabs(r[i]-r[j])>l+eps)continue;
		double k=(p[j]-p[i]).ang();
		double a=r[j],b=r[i],c=l;
		double cosA=(b*b+c*c-a*a)/(2*b*c);
		if(cosA<-1)cosA=-1;if(cosA>1)cosA=1;
		double A=acos(cosA);
		double kk;P now;
		kk=k-A;now=p[i]+P(r[i]*cos(kk),r[i]*sin(kk));poi.pb(now);poc[i].pb(now);
		kk=k+A;now=p[i]+P(r[i]*cos(kk),r[i]*sin(kk));poi.pb(now);poc[i].pb(now);
		fa[find(i)]=find(j);
	}
	sort(ALL(poi));
	V=SZ(poi);
	for(int i=0;i+1<SZ(poi);i++)if(poi[i]==poi[i+1])V--;
	fo(i,1,n){
		if(fa[i]==i)E++;
		sort(ALL(poc[i]));
		E+=SZ(poc[i]);
		for(int j=0;j+1<SZ(poc[i]);j++)if(poc[i][j]==poc[i][j+1])E--;
	}
	printf("%d\n",E+1-V);
	return 0;
}