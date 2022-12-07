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
const int N=40005;
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
		return x*a.y-y*a.x;
	}
	ll operator ^(const P &a)const{
		return x*a.x+y*a.y;
	}
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
}a[N],b[N],A[N];
int px[N],py[N],n,m,cnt;
void convex(P *A,P *a,int &n){
	sort(a+1,a+n+1);
	int top=0;
	For(i,1,n){
		for (;top>=2&&(a[i]-A[top-1])*(A[top]-A[top-1])<=0;--top);
		A[++top]=a[i];
	}
	int ttop=top--;
	Rep(i,n,1){
		for (;top>ttop&&(a[i]-A[top-1])*(A[top]-A[top-1])<=0;--top);
		A[++top]=a[i];
	}
	n=--top;
}
void get_edge(int l,int r){
	px[++cnt]=l; py[cnt]=r;
	if (l+1>=r) return;
	double v=-1e18;
	int p=-1;
	For(i,l+1,r-1){
		int v1=(A[i]-A[l])^(A[i]-A[r]);
		int v2=(A[l]-A[i])*(A[l]-A[r]);
		double val=-1.0*v1/v2;
		if (val>v) v=val,p=i;
	}
	get_edge(l,p);
	get_edge(p,r);
}
void check(int l,int r,int n,P *b,int m){
	double vl=-1e18,vr=1e18;
	For(i,1,n){
		if (i==l||i==r) continue;
		int v1=(A[i]-A[l])^(A[i]-A[r]);
		int v2=(A[l]-A[i])*(A[l]-A[r]);
		if (!v2) continue;
		double v=1.0*v1/v2;
		if (v2<0) vr=min(vr,v);
		else vl=max(vl,v); 
		if (vl>=vr) break;
	}
	For(i,1,m){
		int v1=(b[i]-A[l])^(b[i]-A[r]);
		int v2=(A[l]-b[i])*(A[l]-A[r]);
		if (!v2){
			if (v1>0) continue;
			vl=1e19;
			break;
		}
		double v=1.0*v1/v2;
		if (v2>0) vr=min(vr,v);
		else vl=max(vl,v); 
		if (vl>=vr) break;
	}
	if (vl<vr){
		puts("YES");
		exit(0);
	}
}
void solve(P *a,int n,P *b,int m){
	cnt=0;
	convex(A,a,n);
	get_edge(1,n);
	For(i,1,cnt)
		check(px[i],py[i],n,b,m);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	For(i,1,m) scanf("%d%d",&b[i].x,&b[i].y);
	if (n==1||m==1) return puts("YES"),0;
	solve(a,n,b,m);
	solve(b,m,a,n);
	puts("NO");
}