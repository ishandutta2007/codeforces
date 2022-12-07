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

#define pdi pair<double,int>
const double pi=acos(-1);
const double eps=1e-10;
const int N=2005;
pdi q[N*5];
struct P{
	int x,y,c;
}a[N];
int n,m;
double sqr(double x){
	return x*x;
}
bool check(int id,double r){
	int top=0;
	if (a[id].c==1){
		q[++top]=pdi(0,-1);
		q[++top]=pdi(2*pi,1);
	}
	For(i,1,n+m) if (i!=id){
		double ang=atan2(a[id].y-a[i].y,a[id].x-a[i].x);
		double R=sqr(a[id].y-a[i].y)+sqr(a[id].x-a[i].x);
		if (R>4*r*r) continue;
		if (a[i].c==2&&R>4*r*r-eps) continue;
		double dif=acos(sqrt(R)/2/r);
		double le=ang-dif,ri=ang+dif;
		//if (a[i].c==1) le-=eps,ri+=eps;
		//else le+=eps,ri-=eps;
		if (le<0) le+=2*pi;
		if (le>2*pi) le-=2*pi;
		if (ri<0) ri+=2*pi;
		if (ri>2*pi) ri-=2*pi;
		q[++top]=pdi(le,-a[i].c);
		q[++top]=pdi(ri,a[i].c);
		if (le>ri+eps){
			q[++top]=pdi(0,-a[i].c);
			q[++top]=pdi(2*pi,a[i].c);
		}
	}
	sort(q+1,q+top+1);
	static int S[3];
	S[1]=S[2]=0;
	For(i,1,top){
		S[abs(q[i].se)]+=(q[i].se<0?1:-1);
		//cout<<q[i].fi<<' '<<q[i].se<<endl;
		if (S[1]&&!S[2]) return 1;
	}
	return 0;
}
/*
a^2+b^2-c^2-2cosCab
*/
int main(){
	scanf("%d%d",&n,&m);
	int lx=10000,ly=10000,rx=0,ry=0;
	For(i,1,n+m){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].c=(i<=n?1:2);
		lx=min(lx,a[i].x);
		rx=max(rx,a[i].x);
		ly=min(ly,a[i].y);
		ry=max(ry,a[i].y);
	}
	double mx=sqr(rx-lx)+sqr(ry-ly);
	double ans=0;
	For(i,1,n+m)
		if (check(i,mx))
			return puts("-1"),0;
	For(i,1,n+m){
		if (!check(i,ans)) continue;
		double l=ans,r=mx;
		For(T,1,100){
			double mid=(l+r)/2;
			if (check(i,mid)) l=ans=mid;
			else r=mid;
		}
	}
	printf("%.18lf\n",ans);
}