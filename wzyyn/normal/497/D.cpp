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
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	void init(){
		scanf("%d%d",&x,&y);
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	double dis(){
		return 1.0*x*x+1.0*y*y;
	}
}a[N],b[N],p,q;
double R;
int n,m;
double sqr(double x){
	return x*x;
}
void check(P x,P y,P z){
	double l=(x-y).dis();
	double r=(x-z).dis();
	if (l>r) swap(l,r);
	//cout<<l<<' '<<r<<endl;
	if ((y-z).dis()+l>=r)
		l=min(l,sqr((y-x)*(z-x)/sqrt((y-z).dis())));
	//cout<<l<<' '<<r<<endl;
	if (l<=R&&R<=r){
		puts("YES");
		exit(0);
	}
}
int main(){
	p.init();
	scanf("%d",&n);
	For(i,1,n) a[i].init();
	For(i,1,n) a[i]=a[i]-p;
	q.init();
	scanf("%d",&m);
	For(i,1,m) b[i].init();
	For(i,1,m) b[i]=b[i]-q;
	R=(p-q).dis();
	For(i,1,n) For(j,1,m) check(a[i],b[j],b[j%m+1]);
	For(i,1,m) For(j,1,n) check(b[i],a[j],a[j%n+1]);
	puts("NO");
}