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
inline int sgn(ll x){return x==0?0:(x<0?-1:1);}
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
inline int direction(point p1,point p2,point p3){return sgn((p2-p1)^(p3-p1));}
point quan;
int q[N];
double cc[N];
inline double qiu(point x){
	return atan2(x.y,x.x);
}
inline bool cmp(int  a,int b){
	return cc[a]<cc[b];
}
int n;
point a[N],b[N];
ll ans;
inline int cal(int l,int r){
	return l<=r?r-l:r+n-l-1;
} 
int main(){
	n=read(); 
	for(int i=1;i<=n;i++){
		a[i].x=read(); a[i].y=read();
		b[i]=a[i]; q[i]=i;
	}
	//cout<<direction(a[1],a[2],a[4])<<endl;
	for(int i=1;i<=n;i++){
		quan=a[i];
		for(int j=1;j<=n;j++){cc[j]=qiu(a[j]-quan); q[j]=j;} 
		sort(&q[1],&q[n+1],cmp);
		for(int j=1;j<=n;j++)b[j]=a[q[j]];
		for(int j=1;j<=n;j++)if(b[j].x==a[i].x&&b[j].y==a[i].y){
			for(int k=j-1;k;k--)swap(b[k],b[k+1]); break;
		} 
		int k=3;
		//cout<<i<<endl; for(int j=2;j<=n;j++)cout<<q[j]<<" "<<b[j].x<<" "<<b[j].y<<endl; 
		for(int j=2;j<=n;j++){
			if(k==j)k=(k+1>n?2:k+1);
			while(k!=j){
				if(direction(quan,b[k],b[j])<0){
					k++; if(k>n)k=2; 
				}else break;
			}
			ll t=cal(k,j);
			if(t<2||t+2>n-2)continue;
			//for(int l=k;l!=j;l=(l+1>n?2:l+1))cout<<direction(quan,b[l],b[j])<<endl;
			//cout<<i<<" "<<j<<" "<<t<<" "<<b[j].x<<" "<<b[j].y<<" "<<b[k].x<<" "<<b[k].y<<" "<<k<<endl;
			ans+=2*(t*(t-1)/2)*((n-2-t)*(n-2-t-1)/2);
		}
	}
	//cout<<ans<<endl;
	cout<<ans/4<<endl;
}