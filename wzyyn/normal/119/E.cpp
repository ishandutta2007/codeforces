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
const int N=1005;
#define db double
int n,Q;
struct P3{
	db x,y,z;
	P3(){}
	P3(db _x,db _y,db _z){
		x=_x; y=_y; z=_z;
	}
	void init(){
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	double operator *(const P3 &a)const{
		return x*a.x+y*a.y+z*a.z;
	}
	P3 operator *(const double &a)const{
		return P3(x*a,y*a,z*a);
	}
	P3 operator +(const P3 &a)const{
		return P3(x+a.x,y+a.y,z+a.z);
	}
	P3 operator -(const P3 &a)const{
		return P3(x-a.x,y-a.y,z-a.z);
	}
	P3 ord(){
		P3 xx=*this;
		return xx*sqrt(1/(xx*xx));
	}
}P[N];
struct P2{
	db x,y;
	P2(){}
	P2(db _x,db _y){
		x=_x; y=_y;
	}
	P2 operator +(const P2 &a)const{
		return P2(x+a.x,y+a.y);
	}
	P2 operator -(const P2 &a)const{
		return P2(x-a.x,y-a.y);
	}
	P2 operator *(const double &a)const{
		return P2(x*a,y*a);
	}
	double operator *(const P2 &a)const{
		return x*a.y-y*a.x;
	}
	P2 rot(){
		return P2(y,-x);
	}
}a[N];
double dis(P2 x,P2 y){
	return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
P2 solve(P3 x,P3 y){
	y=y-x*((x*y)/(x*x));
	assert(fabs(y*x)<1e-9);
	//cout<<y.x<<' '<<y.y<<' '<<y.z<<endl;
	//P3 tmp=y;
	if (fabs(x.x)<1e-9) swap(x.x,x.y),swap(y.x,y.y);
	if (fabs(x.x)<1e-9) swap(x.x,x.z),swap(y.x,y.z);
	if (fabs(x.y)<1e-9&&fabs(x.z)<1e-9)	return P2(y.y,y.z);
	P3 p1(-(x.y*x.y+x.z*x.z)/x.x,x.y,x.z);
	P3 p2(0,x.z,-x.y);
	p1=p1.ord(); p2=p2.ord();
	P2 ans; P3 tmp=y;
	ans.y=y.x/p1.x;
	y=y-p1*ans.y;
	if (fabs(p2.z)>0)
		ans.x=y.z/p2.z;
	else ans.x=y.y/p2.y;
	tmp=tmp-p2*ans.x;
	tmp=tmp-p1*ans.y;
	//cout<<tmp.x<<' '<<tmp.y<<' '<<tmp.z<<endl;
	assert(fabs(p1*x)<1e-9);
	assert(fabs(p2*x)<1e-9);
	assert(fabs(p1*p2)<1e-9);
	assert(fabs(p1*p1-1)<1e-9);
	assert(fabs(p2*p2-1)<1e-9);
	assert(fabs(tmp.x)<1e-9);
	assert(fabs(tmp.y)<1e-9);
	assert(fabs(tmp.z)<1e-9);
	//assert(fabs(p1*p2)<1e-9);
	//assert(fabs(p1*p1-1)<1e-9);
	//assert(fabs(p2*p2-1)<1e-9);
	//printf("%.10lf %.10lf\n",ans.x,ans.y);
	return ans;
}
P2 Cir(P2 x,P2 y,P2 z){
	//puts("WZP");
	P2 m1=(x+y)*0.5,m2=(x+z)*0.5;
	P2 d1=(y-x).rot()+m1,d2=(z-x).rot()+m2;
	double ar1=(d1-m2)*(d2-m2),ar2=(d2-m2)*(m1-m2);
	if (fabs(ar2)==0) return m2;
	/*cout<<x.x<<' '<<x.y<<' '<<y.x<<' '<<y.y<<' '<<z.x<<' '<<z.y<<endl;
	cout<<m1.x<<' '<<m1.y<<' '<<m2.x<<' '<<m2.y<<endl;
	cout<<d1.x<<' '<<d1.y<<' '<<d2.x<<' '<<d2.y<<endl;
	cout<<ar1<<' '<<ar2<<endl;*/
	return m1+(d1-m1)*(ar2/(ar1+ar2));
	
	//m1+(d1-m1)(ar1/ar2)
}
double min_cir(){
	random_shuffle(a+1,a+n+1);
	P2 o=a[1]; double r=0;
	For(i,1,n) if (dis(o,a[i])>r+1e-8){
		o=a[i],r=0;
		For(j,1,i-1) if (dis(o,a[j])>r+1e-8){
			o=(a[i]+a[j])*0.5; r=dis(o,a[j]);
			For(k,1,j-1) if (dis(o,a[k])>r+1e-8){
				o=Cir(a[i],a[j],a[k]),r=dis(o,a[k]);
				double r1=dis(a[i],o),r2=dis(a[j],o);
				//cout<<r1<<' '<<r2<<' '<<r<<endl;
			}
		}
	}
	return r;
}
/*
ax+by+cz=0
(a,b,a^2+b^2/c)
(-b,a,0)
*/
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) P[i].init();
	while (Q--){
		P3 x; x.init();
		For(i,1,n) a[i]=solve(x,P[i]);
		//For(i,1,n) cout<<a[i].x<<' '<<a[i].y<<endl;
		printf("%.10lf\n",min_cir());
	}
}
/*
ax+by+cz=1
ax+by+cz=1

7 1
0 0 0
10 10 0
0 20 1000
0 0 10
1 1 1
5 1230 76
99 66 3
1 0 0
*/