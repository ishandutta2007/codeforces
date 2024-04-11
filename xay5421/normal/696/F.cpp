// author: xay5421
// created: Tue Dec 29 21:51:15 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const double eps=1e-9;
const int N=305;
int n;
struct vec{
	double x,y;
	vec operator+(const vec&k)const{return(vec){x+k.x,y+k.y};}
	vec operator-(const vec&k)const{return(vec){x-k.x,y-k.y};}
	vec operator/(double k)const{return(vec){x/k,y/k};}
	vec operator*(double k)const{return(vec){x*k,y*k};}
	double ang()const{return atan2(y,x);}
	double len()const{return sqrt(x*x+y*y);}
	void out()const{D("(%.4f,%.4f)",x,y);}
}a[N],p1,p2;
double cross(const vec&k1,const vec&k2){return k1.x*k2.y-k1.y*k2.x;}
int sgn(double x){return x<-eps?-1:x>eps?1:0;}
struct line{
	vec a,b;
	double ang;
	void init(vec s,vec t){
		a=s,b=t-s;
		ang=b.ang();
	}
	bool operator<(const line&k)const{
		int t;
		return sgn(ang-k.ang)?ang<k.ang:(t=sgn(cross(b,k.b)))!=0?t>0:cross(k.a-a,b)<0;
	}
	line move(double r){
		line res=*this;
		vec tem=b;
		tem=(vec){-tem.y,tem.x}/tem.len()*r;
		res.a=res.a+tem;
		res.b=res.b*(-1);
		res.ang=res.b.ang();
		return res;
	}
	void out()const{
		D("{");
		a.out();
		D(",");
		b.out();
		D(",%.4f",ang);
		D("}\n");
	}
}b[N*2];
vec intersection(const line&a,const line&b){
	return a.a+a.b*cross(b.b,a.a-b.a)/cross(a.b,b.b);
}
deque<line>bk;
bool sol(deque<line>cur,vec&p){
	sort(cur.begin(),cur.end());
	deque<vec>v;
	deque<line>l;
	for(const auto&t:cur){
		//t.out();
		while(SZ(v)&&cross(v.back()-t.a,t.b)>0)v.pop_back(),l.pop_back();
		while(SZ(v)&&cross(v.front()-t.a,t.b)>0)v.pop_front(),l.pop_front();
		if(SZ(l)&&sgn(cross(t.b,l.back().b))==0){
			if(sgn(t.ang-l.back().ang)!=0)return 0;
			l.pop_back();
			if(SZ(v))v.pop_back();
		}
		if(SZ(l))v.push_back(intersection(l.back(),t));
		l.push_back(t);
	}
	while(SZ(v)&&cross(v.back()-l.front().a,l.front().b)>0)v.pop_back(),l.pop_back();
	if(SZ(l)<=2)return 0;
	p=intersection(l.front(),l.back());
	return 1;
}
bool OK(int l,int r,vec &p){
	deque<line>cur=bk;
	rep(i,l,r)cur.push_back(b[(i-1)%n+1+n]);
	//D("pd %d %d\n",l,r);
	return sol(cur,p);
}
bool chk(double mid){
	rep(i,1,n)b[i].init(a[i],a[i%n+1]);
	rep(i,n+1,n+n){
		b[i]=b[i-n].move(mid);
	}
	bk.clear();
	rep(i,1,n)bk.push_back(b[i]);
	for(int i=1,j=1;i<=n;++i){
		while(j<i+n-2&&OK(i,j,p1))++j;
		if(OK(j,i+n-1,p2))return 1;
	}
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%lf%lf",&a[i].x,&a[i].y);
	double l=0,r=1e6;
	while(r-l>1e-9){
		double mid=(l+r)/2.;
		if(chk(mid))r=mid;
		else l=mid;
	}
	chk(r);
	printf("%.20f\n",l);
	printf("%.20f %.20f\n",p1.x,p1.y);
	printf("%.20f %.20f\n",p2.x,p2.y);
	return 0;
}