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
const int N=100005;
const double eps=1e-9;
const double pi=acos(-1);
struct P{
	int x,y;
}a[N];

int n,vi[N],t[N];
double l[N],r[N],q[N];
ll k;

void change(int k,int v){
	for (;k;k-=k&(-k)) t[k]+=v;
}
int ask(int k){
	int s=0;
	for (;k<N;k+=k&(-k)) s+=t[k];
	return s;
}
struct node{
	double p1,p2;
	int v;
}op[N*2];
bool cmp(node a,node b){
	return a.p1<b.p1;
}
ll count(double R){
	int top=0,op_top=0;
	memset(t,0,sizeof(t));
	For(i,1,n){
		l[i]=r[i]=-1;
		double d=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
		if (d<R+eps) continue;
		double theta=atan2(a[i].y,a[i].x);
		double delta=acos(R/d);
		l[i]=theta-delta;
		r[i]=theta+delta;
		for (;l[i]<0;l[i]+=2*pi);
		for (;r[i]<0;r[i]+=2*pi);
		for (;l[i]>=2*pi;l[i]-=2*pi);
		for (;r[i]>=2*pi;r[i]-=2*pi);
		if (l[i]>r[i]) swap(l[i],r[i]);
		q[++top]=l[i];
		op[++op_top]=(node){l[i],l[i],1};
		op[++op_top]=(node){r[i],l[i],-1};
		//cout<<R<<' '<<i<<' '<<l[i]<<' '<<r[i]<<endl;
	}
	sort(q+1,q+top+1);
	sort(op+1,op+op_top+1,cmp);
	ll sum=0;
	For(i,1,op_top){
		int p=lower_bound(q+1,q+top+1,op[i].p2)-q;
		change(p,op[i].v);
		if (op[i].v==-1) sum+=ask(p);
	}
	return sum;
}
int main(){
	scanf("%d%lld",&n,&k);
	For(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	double l=0,r=15000;
	For(T,1,50){
		double mid=(l+r)/2;
		if (1ll*n*(n-1)/2-count(mid)<k) l=mid;
		else r=mid;
	}
	printf("%.10lf\n",(l+r)/2);
}