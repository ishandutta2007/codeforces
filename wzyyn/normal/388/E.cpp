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
const double eps=1e-7;
const int N=1005;
struct Line{
	double x,y,vx,vy;
	void init(){
		double t1,t2;
		scanf("%lf%lf%lf",&t1,&x,&y);
		scanf("%lf%lf%lf",&t2,&vx,&vy);
		vx=(vx-x)/(t2-t1); x-=t1*vx;
		vy=(vy-y)/(t2-t1); y-=t1*vy;
	}
}p[N],tmp;
struct P{
	double x,y;
}b[N];
double det(P a,P b){
	return a.x*b.y-a.y*b.x;
};
bool operator <(P a,P b){
	if (fabs(det(a,b))>eps) return det(a,b)<0;
	if (fabs(a.x-b.x)>eps) return a.x<b.x;
	return a.y<b.y;
}
int n,ans;
double a[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) p[i].init();
	For(i,1,n){
		int top=0;
		For(j,1,n) if (j!=i){
			Line tmp;
			tmp.x=p[j].x-p[i].x;
			tmp.y=p[j].y-p[i].y;
			tmp.vx=p[j].vx-p[i].vx;
			tmp.vy=p[j].vy-p[i].vy;
			double t=0;
			if (tmp.vx) t=tmp.x/tmp.vx;
			if (tmp.vy) t=tmp.y/tmp.vy;
			if (fabs(tmp.x-tmp.vx*t)<=eps)
				if (fabs(tmp.y-tmp.vy*t)<=eps){
					a[++top]=t;
					b[top].x=tmp.vx;
					b[top].y=tmp.vy;
				}
		}
		//cout<<top<<endl;
		sort(a+1,a+top+1);
		sort(b+1,b+top+1);
		int cnt=0;
		For(j,1,top){
			if (fabs(a[j]-a[j-1])>eps) cnt=0;
			ans=max(ans,++cnt);
		}
		cnt=0;
		sort(b+1,b+top+1);
		For(j,1,top){
			if (fabs(det(b[j],b[j-1]))>eps) cnt=1;
			else if (fabs(b[j].x-b[j-1].x)>eps||fabs(b[j].y-b[j-1].y)>eps) ++cnt;
			ans=max(ans,cnt);
		}
	}
	printf("%d\n",ans+1);
} 
/*
dx,dy
*/