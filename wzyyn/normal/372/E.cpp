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
const int mo=1000000007;
const double eps=1e-9;
double x[N],y[N];
bool EQ(double x,double y){
	return fabs(x-y)<eps;
}
struct node{
	double x,y,d;
	bool operator <(const node &a)const{
		if (!EQ(x,a.x)) return x<a.x;
		if (!EQ(y,a.y)) return y<a.y;
		if (!EQ(d,a.d)) return d<a.d; 
		return 0;
	} 
}q[N*N/2];
int n,cnt,ans;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		double x=1.0*a/b,y=1.0*c/d;
		::x[i]=x/(x*x+y*y);
		::y[i]=y/(x*x+y*y);
		//cout<<::x[i]<<' '<<::y[i]<<endl;
	}
	For(i,1,n) For(j,i+1,n){
		++cnt;
		q[cnt].x=x[i]+x[j];
		q[cnt].y=y[i]+y[j];
		q[cnt].d=EQ(x[i],x[j])?1e50:(y[i]-y[j])/(x[i]-x[j]);
	}
	sort(q+1,q+cnt+1);
	for (int l=1,r;l<=cnt;l=r){
		for (r=l;r<=cnt&&EQ(q[l].x,q[r].x)&&EQ(q[l].y,q[r].y);++r);
		int num=1,tmp=2;
		For(i,l+1,r)
			if (i==r||!EQ(q[i].d,q[i-1].d))
				num=1ll*num*tmp%mo,tmp=2;
			else ++tmp;
		//cout<<num<<' '<<r-l+1<<' '<<l<<' '<<r<<endl;
		ans=(ans+num+1ll*mo-(r-l+1))%mo;
	}
	printf("%d\n",ans);
}