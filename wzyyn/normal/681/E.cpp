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
const int N=400005;
const double eps=1e-10;
const double pi=acos(-1);
int ox,oy,v,T,top,n;
double ans;
pdi q[N];
int main(){
	scanf("%d%d%d%d",&ox,&oy,&v,&T);
	scanf("%d",&n);
	double d=1.0*v*T;
	For(i,1,n){
		int x,y,R;
		scanf("%d%d%d",&x,&y,&R);
		double d1=sqrt(1.0*(x-ox)*(x-ox)+1.0*(y-oy)*(y-oy));
		if (d1<R+eps) return puts("1"),0;
		if (d1>R+d-eps) continue;
		double tmp=sqrt(1.0*d1*d1-1.0*R*R);
		double ang=atan2(y-oy,x-ox),dif;
		//cout<<tmp<<endl;
		if (tmp<d+eps) dif=asin(R/d1);
		else dif=acos((d1*d1+d*d-1.0*R*R)/(2*d1*d));
		double l=ang-dif,r=ang+dif;
		//cout<<(d1*d1+d*d-R*R)/2
		//cout<<ang<<' '<<dif<<' '<<d<<' '<<d1<<' '<<R<<endl;
		if (l<0) l+=2*pi;
		if (r<0) r+=2*pi;
		if (l>2*pi) l-=2*pi;
		if (r>2*pi) r-=2*pi;
		if (l<=r){
			q[++top]=(pdi){l,1};
			q[++top]=(pdi){r,-1};
		}
		else{
			q[++top]=(pdi){0,1};
			q[++top]=(pdi){r,-1};
			q[++top]=(pdi){l,1};
			q[++top]=(pdi){2*pi,-1};
		}
	}
	sort(q+1,q+top+1);
	int sum=0;
	For(i,1,top-1){
		sum+=q[i].se;
		if (sum) ans+=q[i+1].fi-q[i].fi; 
	}
	printf("%.15lf\n",ans/(2*pi));
}
/*
0 0 1 1
1
3 4 4
*/