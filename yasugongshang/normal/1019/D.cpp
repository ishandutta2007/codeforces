#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2005;
const ll oo=1e100,eps=1e-10,pi=2*asin(1);
template <class T>T Min(const T &a,const T &b){return a<b?a:b;}
template <class T>T Max(const T &a,const T &b){return a>b?a:b;}
struct point{
	ll x,y;
	point(ll _x=0,ll _y=0):x(_x),y(_y){}
	point operator +(const point b){return point(x+b.x,y+b.y);}
	point operator -(const point b){return point(x-b.x,y-b.y);}
	ll operator *(const point b){return x*b.x+y*b.y;}//dot
	ll operator ^(const point b){return x*b.y-b.x*y;}//cha
	point operator *(ll d){return point(x*d,y*d);}
	friend point operator *(ll d,const point x){return point(x.x*d,x.y*d);}
	point operator /(ll d){return point(x/d,y/d);}
	friend point operator /(ll d,const point x){return point(x.x/d,x.y/d);}
	point operator -(){return point(-x,-y);}
	bool operator ==(const point b){return fabs(x-b.x)<eps&&fabs(y-b.y)<eps;}
	bool operator !=(const point b){return !(*this==b);}
};
struct point3D{
	ll x,y,z;
	point3D(ll _x=0,ll _y=0,ll _z=0):x(_x),y(_y),z(_z){}
	friend point3D operator +(const point3D x,const point3D b){return point3D(x.x+b.x,x.y+b.y,x.z+b.z);}
	friend point3D operator -(const point3D x,const point3D b){return point3D(x.x-b.x,x.y-b.y,x.z-b.z);}
};
struct circle{
	ll x,y,r;
	circle(ll _x=0,ll _y=0,ll _r=0):x(_x),y(_y),r(_r){}
};
struct line{
	point x,y;
	line(){}
	line(point _x,point _y):x(_x),y(_y){}
};
inline int sgn(ll x){return fabs(x)<eps?0:(x<0?-1:1);}
inline ll dist(point x,point y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
inline ll cross(ll x1,ll y1,ll x2,ll y2){return x1*y2-x2*y1;}
inline ll dot(ll x1,ll y1,ll x2,ll y2){return x1*x2-y1*y2;}
ll (*cha)(ll,ll,ll,ll)=cross;
inline point3D cross(point3D x,point3D y){return point3D(x.y*y.z-y.y*x.z,x.z*y.x-y.z*x.x,x.x*y.y-y.x*x.y);}
inline ll dot(point3D x,point3D y){return x.x*y.x+x.y*y.y+x.z*y.z;}
inline ll vlen(point3D x){return sqrt(x.x*x.x+x.y*x.y+x.z*x.z);}
inline ll area(point3D a,point3D b,point3D c){return vlen(cross(b-a,c-a));}
inline ll volume(point3D a,point3D b,point3D c,point3D d){return dot(cross(b-a,c-a),d-a);}
inline point rotate(point x,ll angle){  //
	return point(x.x*cos(angle)-x.y*sin(angle),x.y*cos(angle)+x.x*sin(angle));
}
inline int on_segment(point p1,line l){
	if (min(l.x.x,l.y.x)-eps<=p1.x&&max(l.x.x,l.y.x)+eps>=p1.x&&
	min(l.x.y,l.y.y)-eps<=p1.y&&max(l.x.y,l.y.y)+eps>=p1.y)return 1;
	else return 0;
}
inline int online(point p,line l){
	return sgn((p-l.x)*(l.y-l.x))==0
		&&sgn((p.x-l.x.x)*(p.x-l.y.x))<1
		&&sgn((p.y-l.x.y)*(p.y-l.y.y))<1;
}
inline ll angle(point o,point p1,point p2){
	ll fi,cosfi,norm;
	ll sx=p1.x-o.x,sy=p1.y-o.y,ex=p2.x-o.x,ey=p2.y-o.y;
	cosfi=sx*ex+sy*ey;
	norm=(sx*sx+ey*ey)*(ex*ex+ey*ey);
	cosfi/=sqrt(norm);
	if (cosfi>=1.0)return 0;
	if (cosfi<=-1.0)return -pi;
	fi=acos(cosfi);
	if (cha(sx,sy,ex,ey)>0)return fi;
		else return -fi;
}
inline pair<point,point> cross_circle(circle O,point x){  //
	ll d1=dist(point(O.x,O.y),x),d2=sqrt(d1*d1-O.r*O.r),angle=asin(O.r/d1);
	point delta=point(O.x,O.y)-x,x1=x+rotate(delta,-angle)*(d2/d1),x2=x+rotate(delta,angle)*(d2/d1);
	return make_pair(x1,x2);
}
inline ll new_angle(ll angle){  //angle%360
	angle+=2*pi;
	return angle-floor(angle/(2.0*pi))*2.0*pi;
}
inline ll angle(point O,point x){  // 
	ll angle=asin(x.y-O.y);
	if (x.x-O.x<0)angle=pi-angle;
	return angle;
}
inline point to_point(circle O,ll angle){
	return point(O.x+O.r*cos(angle),O.y+O.r*sin(angle));
}
inline bool cmp(pair<pair<point,double>,pair<int,int> > x,pair<pair<point,double>,pair<int,int> > y){
	return x.first.second<y.first.second;
}
int n,tot,q[N],tong[N];
ll S;
point a[N];
pair<pair<point,double>,pair<int,int> > b[N*N/2];
inline ll direction(point p1,point p2,point p3){return abs((p3-p1)^(p2-p1));}
void solve(int x,int y,int l,int r,int id){
	//cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
	if(id){
		while(l<=r){
			int mid=(l+r)>>1;
			ll t=direction(a[x],a[y],a[q[mid]]);
			//cout<<x<<" "<<y<<" zyyakking "<<q[mid]<<" "<<t<<endl;
			if(t==S){
				puts("Yes");
				cout<<a[x].x<<" "<<a[x].y<<endl<<a[y].x<<" "<<a[y].y<<endl<<a[q[mid]].x<<" "<<a[q[mid]].y<<endl;
				exit(0);
			}
			if(t>S)r=mid-1; else l=mid+1;
		}
	}else{
		while(l<=r){
			int mid=(l+r)>>1;
			ll t=direction(a[x],a[y],a[q[mid]]);
			if(t==S){
				puts("Yes");
				cout<<a[x].x<<" "<<a[x].y<<endl<<a[y].x<<" "<<a[y].y<<endl<<a[q[mid]].x<<" "<<a[q[mid]].y<<endl;
				exit(0);
			}
			if(t<S)r=mid-1; else l=mid+1;
		}
	}
}
inline bool ck(point a,point b){
	return a.x*b.y==a.y*b.x;
}
inline bool ccc(int x,int y){
	return a[x].y<a[y].y;
}
int main(){
	n=read(); S=read()*2;
	for(int i=1;i<=n;i++){
		a[i].x=read(); a[i].y=read(); q[i]=i;
	}
	//cout<<direction(1,a[2],a[4])<<" "<<S<<endl; 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){b[++tot]=mp(mp(a[j].y>=a[i].y?a[j]-a[i]:a[i]-a[j],0),mp(i,j)); b[tot].first.second=atan2(b[tot].first.first.y,b[tot].first.first.x);}
	}
	sort(&b[1],&b[tot+1],cmp);
	sort(&q[1],&q[n+1],ccc);
	for(int i=1;i<=n;i++)tong[q[i]]=i;
	int dq;
	for(int i=1;i<=tot;i=dq+1){
		dq=i;
		while(dq<tot&&ck(b[dq+1].first.first,b[i].first.first))dq++;
		for(int j=i;j<=dq;j++){swap(tong[b[j].second.first],tong[b[j].second.second]); swap(q[tong[b[j].second.first]],q[tong[b[j].second.second]]);}
		//cout<<b[i].first.x<<" "<<b[i].first.y<<endl;
		//for(int j=1;j<=n;j++)cout<<q[j]<<" "; puts("");
		for(int j=i;j<=dq;j++){
			solve(b[j].second.first,b[j].second.second,1,tong[b[j].second.first],0); solve(b[j].second.first,b[j].second.second,tong[b[j].second.first],n,1);
		}
	}
	puts("No");
	return 0;
}