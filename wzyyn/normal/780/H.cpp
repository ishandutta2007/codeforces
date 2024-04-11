#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=100005;
const double eps=1e-10;
struct P{
	double x,y;
	P(){}
	P(double _x,double _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	P operator *(const double &a)const{
		return P(a*x,a*y);
	}
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	void init(){
		scanf("%lf%lf",&x,&y);
	}
};
double sqr(double x){
	return x*x;
}
double dis(P x,P y){
	return sqrt(sqr(x.x-y.x)+sqr(x.y-y.y));
}
struct Func{
	double a,b,c;
	P calc(double z){
		if (fabs(a)<eps)
			return z<=c?P(1e18,-1e18):P(-1e18,1e18);
		double C=c-z;
		double delta=b*b-4*a*C;
		if (delta+eps<0) return P(-1e18,-1e18);
		delta=sqrt(delta+eps);
		return P((-b-delta)/2/a,(-b+delta)/2/a);
	}
};
struct node{
	Func f;
	double l,r;
};
P p[N];
int n,m;
double C;
vector<node> vec;
vector<P> spe[N];
void build(){
	For(i,1,n) C+=dis(p[i],p[i%n+1]);
	int at=2; P now=p[1];
	For(i,1,m){
		spe[i].PB(now);
		double rem=C/m;
		for (;fabs(rem)>eps;){
			double D=dis(now,p[at]);
			if (fabs(D)<eps) at=at%n+1;
			else if (D<=rem){
				rem-=D;
				spe[i].PB(p[at]);
				now=p[at];
				at=at%n+1;
			}
			else{
				now=now+(p[at]-now)*(rem/D);
				spe[i].PB(now);
				break;
			}
		}
		//cout<<C/m<<endl;
		/*for (auto j:spe[i])
			cout<<j.x<<' '<<j.y<<endl;
		cout<<"AWSL "<<C/m<<endl;*/
	}
}
void buildF(vector<P> a,vector<P> b){
	int sza=a.size(),szb=b.size();
	int nxa=1,nxb=1;
	P pa=a[0],pb=b[0];
	double T=0;
	for (;nxa<sza||nxb<szb;){
		double da=dis(pa,a[nxa]);
		double db=dis(pb,b[nxb]);
		double val=min(da,db);
		P Da=(a[nxa]-pa)*(1/da);
		P Db=(b[nxb]-pb)*(1/db);
		P del1=pa-pb;
		P del2=Da-Db;
		Func f;
		//cout<<T<<' '<<val<<' '<<Da.x<<' '<<Da.y<<' '<<Db.x<<' '<<Db.y<<endl;
		f.a=sqr(del2.x)+sqr(del2.y);
		f.b=2*del2.x*del1.x+2*del2.y*del1.y;
		f.c=sqr(del1.x)+sqr(del1.y);
		vec.PB((node){f,T,T+val});
		T+=val;
		pa=pa+Da*val;
		pb=pb+Db*val;
		if (fabs(val-da)<eps) nxa++;
		if (fabs(val-db)<eps) nxb++;
	}
}
bool check(double mid){
	static P q[N*10];
	int top=0;
	For(i,0,vec.size()-1){
		P range=vec[i].f.calc(mid);
		//cout<<range.x<<' '<<range.y<<endl;
		if (range.x<-1e17){
			if (range.y<-1e17)
				q[++top]=(P){vec[i].l,vec[i].r};
		}
		else{
			double len=vec[i].r-vec[i].l;
			if (range.x>0) q[++top]=(P){vec[i].l,vec[i].l+min(range.x,len)};
			if (range.y<len) q[++top]=(P){vec[i].l+max(0.0,range.y),vec[i].r};
		}
	}
	sort(q+1,q+top+1);
	double r=0;
	For(i,1,top)
		if (q[i].x>r+eps) return 0;
		else r=max(r,q[i].y);
	return r+eps>C/m;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) p[i].init();
	build();
	For(i,1,m) buildF(spe[i],spe[i%m+1]);
	//for (auto i:vec) cout<<"FUNC "<<i.l<<' '<<i.r<<' '<<i.f.a<<' '<<i.f.b<<' '<<i.f.c<<endl;
	double l=0,r=3000;
	For(T,1,100){
		double mid=(l+r)/2;
		if (!check(mid*mid)) r=mid;
		else l=mid;
	}
	printf("%.10lf\n",(r+l)/2);
	check(400);
}