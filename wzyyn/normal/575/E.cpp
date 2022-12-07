#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int M=100000;
const int N=1000005;
const double pi=acos(-1);
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	ll operator ^(const P &a)const{
		return 1ll*x*a.x+1ll*y*a.y;
	}
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	bool operator ==(const P &a)const{
		return x==a.x&&y==a.y;
	}
}p[N],q[N];
P P1,P2,P3;
int top,n;
double ansR;
void build_convex(int &n){
	int top=0;
	For(i,1,n){
		for (;top>=2&&(q[top]-q[top-1])*(p[i]-q[top-1])>=0;top--);
		q[++top]=p[i];
	}
	int ttop=top;
	Rep(i,n-1,1){
		for (;top>ttop&&(q[top]-q[top-1])*(p[i]-q[top-1])>=0;top--);
		q[++top]=p[i];
	}
	n=--top;
	For(i,1,top) p[i]=q[i];
}
void update(P p1,P p2,P p3){
	if (!((p1-p2)*(p1-p3))) return;
	double D=sqrt((p2-p3)^(p2-p3));
	double ang1=atan2(p2.y-p1.y,p2.x-p1.x);
	double ang2=atan2(p3.y-p1.y,p3.x-p1.x);
	double ang=ang1-ang2;
	for (;ang>pi;ang-=pi);
	for (;ang<0;ang+=pi);
	double R=0.5*D/sin(fabs(ang));
	if (R>ansR){
		ansR=R;
		P1=p1; P2=p2; P3=p3;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if (x-v>=0)
			p[++top]=P(x-v,y);
		else{
			int dif=v-x;
			p[++top]=P(0,max(0,y-dif));
			p[++top]=P(0,min(M,y+dif));
		}
		if (y-v>=0)
			p[++top]=P(x,y-v);
		else{
			int dif=v-y;
			p[++top]=P(max(0,x-dif),0);
			p[++top]=P(min(M,x+dif),0);
		}
		if (x+v<=M)
			p[++top]=P(x+v,y);
		else{
			int dif=x+v-M;
			p[++top]=P(M,max(y-dif,0));
			p[++top]=P(M,min(y+dif,M));
		}
		if (y+v<=M)
			p[++top]=P(x,y+v);
		else{
			int dif=y+v-M;
			p[++top]=P(max(x-dif,0),M);
			p[++top]=P(min(x+dif,M),M);
		}
	}
	sort(p+1,p+top+1);
	top=unique(p+1,p+top+1)-p-1;
	build_convex(top);
	For(i,1,top)
		update(p[(i-1)%top+1],p[i%top+1],p[(i+1)%top+1]);
	printf("%d %d\n",P1.x,P1.y);
	printf("%d %d\n",P2.x,P2.y);
	printf("%d %d\n",P3.x,P3.y);
}