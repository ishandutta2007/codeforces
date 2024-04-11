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
const double eps=1e-10;
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
	double len(){
		return sqrt(x*x+y*y);
	}
}p[1005];
pair<double,int> q[1005];
int n,Q;
double solve(P *p,int n,P S,P T){
	int top=0;
	For(i,1,n){
		int fl1=sgn((p[i]-S)*(T-S));
		int fl2=sgn((p[i%n+1]-S)*(T-S));
		if (fl1==fl2) continue;
		double ar1=(p[i]-S)*(p[i%n+1]-p[i]);
		double ar2=(T-S)*(p[i%n+1]-p[i]);
		q[++top]=make_pair(ar1/ar2,fl2-fl1);
	}
	sort(q+1,q+top+1);
	int cnt=0;
	double sum=0,las=0;
	For(i,1,top){
		if (cnt>0) sum+=q[i].fi-las;
		las=q[i].fi; cnt+=q[i].se;
	}
	return sum*(T-S).len();
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%lf%lf",&p[i].x,&p[i].y);
	double sum=0;
	For(i,1,n) sum+=p[i]*p[i%n+1];
	if (sum<0) reverse(p+1,p+n+1);
	while (Q--){
		P S,T;
		scanf("%lf%lf%lf%lf",&S.x,&S.y,&T.x,&T.y);
		printf("%.10lf\n",solve(p,n,S,T));
	}
}