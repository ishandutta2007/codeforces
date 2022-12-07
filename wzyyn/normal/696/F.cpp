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
const double inf=1e10;
const double eps=1e-8;
int sgn(double x){
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}
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
	double operator *(const P &a)const{
		return x*a.y-y*a.x;
	}
	P operator *(const double &a)const{
		return P(x*a,y*a);
	}
};
double dis(P p){
	return sqrt(p.x*p.x+p.y*p.y);
}
P Norm(P p){
	return P(-p.y,p.x)*(1/dis(p));
}
struct Line{
	P x,y;
	bool online(P p){
		return sgn((p-x)*(y-x))==0;
	}
};
P insert(Line x,Line y){
	double ar1=(x.y-x.x)*(y.x-x.x);
	double ar2=(y.y-x.x)*(x.y-x.x);
	P res=(y.y*ar1+y.x*ar2)*(1/(ar1+ar2));
	/*cout<<x.x.x<<' '<<x.x.y<<' '<<x.y.x<<' '<<x.y.y<<endl;
	cout<<y.x.x<<' '<<y.x.y<<' '<<y.y.x<<' '<<y.y.y<<endl;
	cout<<res.x<<' '<<res.y<<' '<<ar1<<' '<<ar2<<endl;*/
	//assert(x.online(res)&&y.online(res));
	return res;
}
bool check(Line x,Line y,Line z){
	P p=insert(y,z);
	return sgn((x.y-x.x)*(p-x.x))>=0;
}
double Angle(Line x){
	return atan2(x.y.y-x.x.y,x.y.x-x.x.x);
}
bool half(vector<Line> v,P &p){
	static Line q[N];
	int l=1,r=0;
	for (auto i:v){
		//cerr<<l<<' '<<r<<endl;
		for (;l<r&&check(i,q[r],q[r-1]);--r);
		for (;l<r&&check(i,q[l],q[l+1]);++l);
		q[++r]=i;
	}
	//cerr<<"AXIBA"<<endl;
	for (;l<r&&check(q[l],q[r],q[r-1]);--r);
	for (;l<r&&check(q[r],q[l],q[l+1]);++l);
	//cerr<<"AXIBA "<<l<<' '<<r<<endl;
	if (l+1>=r) return 0;
	return p=insert(q[l],q[l+1]),1;
}
P a[N],p1,p2;
Line L[N];
double ang[N];
int id[N],n;
bool cmp(int x,int y){
	if (sgn(ang[x]-ang[y])) return ang[x]>ang[y];
	return sgn((L[x].y-L[x].x)*(L[y].x-L[x].x))>0;
}
bool check(int l,int r,P &p){
	//cout<<l<<' '<<r<<endl;
	static int vis[N];
	memset(vis,0,sizeof(vis));
	For(i,l,r-1) vis[(i-1)%n+1]=1;
	double las=-inf;
	vector<Line> v;
	For(i,1,2*n)
		if (id[i]<=n||vis[id[i]-n])
			if (sgn(las-ang[id[i]])){
				//cout<<las<<' '<<ang[id[i]]<<' '<<L[id[i]].y.x-L[id[i]].x.x<<' '<<L[id[i]].y.y-L[id[i]].x.y<<endl;
				las=ang[id[i]];
				v.PB(L[id[i]]);
			}
	return half(v,p);
}
bool check(double mid){
	For(i,1,n)
		L[i]=(Line){a[i%n+1],a[i]};
	For(i,1,n){
		P tmp=Norm(a[i%n+1]-a[i]);
		//cout<<tmp.x<<' '<<tmp.y<<endl;
		L[i+n].x=a[i]+tmp*mid;
		L[i+n].y=a[i%n+1]+tmp*mid;
	}
	For(i,1,2*n){
		id[i]=i;
		ang[i]=Angle(L[i]);
	}
	sort(id+1,id+2*n+1,cmp);
	//For(i,1,2*n) cout<<ang[id[i]]; cout<<endl;
	int j=1;
	For(i,1,n){
		P p,x,y;
		for (j=max(j,i);j<i+n&&check(i,j+1,p);x=p,++j);
		//cout<<i<<' '<<j<<endl;
		if (j==i+n) return p1=p2=x,1;
		if (check(j,i+n,y)) return p1=x,p2=y,1;
	}
	return 0;
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n);
	For(i,1,n){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		a[i+n]=a[i];
	}
	double l=0,r=40000;
	For(T,1,40){
		double mid=(l+r)/2;
		//cerr<<mid<<endl;
		if (check(mid)) r=mid;
		else l=mid;
	}
	check(r);
	printf("%.10lf\n",r);
	printf("%.10lf %.10lf\n",p1.x,p1.y);
	printf("%.10lf %.10lf\n",p2.x,p2.y);
}