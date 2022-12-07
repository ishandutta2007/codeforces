#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
#define pdd pair<double,double>
const double pi=acos(-1);
const int N=100005;
pii a[N];
int st[N*2][20],n,m;
double dis[N],deg[N];
pdd b[N*2];
bool check(double mid){
	For(i,1,n){
		double ang=acos(mid/dis[i]);
		b[i]=pdd(deg[i]-ang,deg[i]+ang);
		if (b[i].fi<0) b[i].fi+=2*pi,b[i].se+=2*pi;
	}
	sort(b+1,b+n+1);
	int top=0;
	For(i,1,n){
		for (;top&&b[top].se>=b[i].se;--top);
		b[++top]=b[i];
	}
	for (;b[top].se>=b[1].se+2*pi;--top);
	For(i,1,top) b[i+top]=b[i];
	For(i,top+1,top*2) b[i].fi+=2*pi,b[i].se+=2*pi;
	int posi=1;
	For(i,1,top){
		for (;posi<2*top&&b[i].se>=b[posi].fi;++posi);
		st[i][0]=posi;
		st[i+top][0]=min(posi+top,2*top);
	}
	For(i,1,18) For(j,1,top*2)
		st[j][i]=st[st[j][i-1]][i-1];
	For(i,1,top){
		int now=0,posi=i;
		Rep(j,18,0)
			if (st[posi][j]<i+top)
				posi=st[posi][j],now+=1<<j;
		if (now+1<=m) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	double l=0,r=1e10;
	For(i,1,n){
		dis[i]=sqrt(1ll*a[i].fi*a[i].fi+1ll*a[i].se*a[i].se);
		deg[i]=atan2(a[i].se,a[i].fi);
		r=min(r,dis[i]);
	}
	For(T,1,50){
		double mid=(l+r)/2;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%.10lf\n",(l+r)/2);
}