// author: xay5421
// created: Fri Nov 12 14:55:34 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const long double PI=acos(-1.0);
const int N=3005;
struct vec{
	int x,y;
	vec(int k1=0,int k2=0):x(k1),y(k2){}
}a[N];
vec operator+(const vec a,const vec b){return vec(a.x+b.x,a.y+b.y);}
vec operator-(const vec a,const vec b){return vec(a.x-b.x,a.y-b.y);}
long double dis(vec a,vec b){return sqrt(1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y));}
LL dis2(vec a,vec b){return 1LL*(a.x-b.x)*(a.x-b.x)+1LL*(a.y-b.y)*(a.y-b.y);}
long double l[N],r[N];
int tag[N],ban[N][N];
int n,R,ans;
bool tryins(int i,long double L,long double R){
	if(R<l[i]||L>r[i])return 0;
	return 1;
}
void ins(int i,long double L,long double R){
	l[i]=max(l[i],L);
	r[i]=min(r[i],R);
}
bool chk(long double ang,int i){return !tag[i]||(l[i]<=ang&&ang<=r[i]);}
int main(){
	scanf("%d%d",&n,&R);
	rep(i,1,n)scanf("%d%d",&a[i].x,&a[i].y);
	rep(i,1,n)rep(j,1,n){
		if(i==j)continue;
		if(dis2(a[i],a[j])<=1LL*R*R)continue;
		long double ang=asin(R/dis(a[i],a[j]));
		long double nowang=atan2(a[j].y-a[i].y,a[j].x-a[i].x);
		if(nowang<0)nowang+=2*PI;
		long double nowl=nowang-ang,nowr=nowang+ang;
		if (!tag[i]){
			tag[i]=1;
			l[i]=nowl;
			r[i]=nowr;
		}else{
			if(tryins(i,nowl,nowr)){
				ins(i,nowl,nowr);
			}else if(tryins(i,nowl+2*PI,nowr+2*PI)){
				ins(i,nowl+2*PI,nowr+2*PI);
			}else{
				ins(i,nowl-2*PI,nowr-2*PI);
			}
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			if(i==j)continue;
			long double nowang=atan2(a[j].y-a[i].y,a[j].x-a[i].x);
			if(nowang<0)nowang+=2*PI;
			if(!chk(nowang,i)&&!chk(nowang-2*PI,i)&&!chk(nowang+2*PI,i))ban[i][j]=ban[j][i]=1;
		}
	}
	rep(i,1,n)rep(j,i+1,n)ans+=(1-ban[i][j]);
	printf("%d\n",ans);
	return 0;
}