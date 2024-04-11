#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
inline void umax(double&x,double y){if(x<y)x=y;}
const int N=200005;
int n,Q,x,y,b[N];
struct node{
	double a[3][3];
	double val()const{
		double ret=0;
		rep(i,0,2)rep(j,0,2)umax(ret,a[i][j]);
		return ret;
	}
}dp[N*4];
node unite(const node&lhs,const node&rhs){
	node ret;
	memset(ret.a,0,sizeof(ret.a));
	rep(j,0,2)rep(i_,0,2){
		if(j&&i_&&(j!=2||i_!=2))continue;
		rep(i,0,2)rep(j_,0,2){
			umax(ret.a[i][j_],lhs.a[i][j]+rhs.a[i_][j_]);
		}
	}
	return ret;
}
void upd(int k1){dp[k1]=unite(dp[k1*2],dp[k1*2+1]);}
void bud(int k1,int k2,int k3){
	if(k2==k3){
		dp[k1].a[0][0]=0;
		dp[k1].a[1][1]=1.*b[k2]/max(x,y);
		dp[k1].a[2][2]=1.*b[k2]/(x+y);
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4){
	if(k2==k3){
		dp[k1].a[0][0]=0;
		dp[k1].a[1][1]=1.*b[k2]/max(x,y);
		dp[k1].a[2][2]=1.*b[k2]/(x+y);
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)mdf(k1*2,k2,mid,k4);else mdf(k1*2+1,mid+1,k3,k4);
	upd(k1);
}
bool fir;
node ff;
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		if(fir){
			ff=dp[k1];
			fir=0;
		}else{
			ff=unite(ff,dp[k1]);
		}
		return;
	}
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5),ask(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q),rd(x),rd(y);
	rep(i,1,n)rd(b[i]);
	bud(1,1,n);
	rep(i,1,Q){
		int opt;
		rd(opt);
		if(opt==1){
			int k,v;
			rd(k),rd(v);
			b[k]=v;
			mdf(1,1,n,k);
		}else{
			int l,r;
			rd(l),rd(r);
			fir=1;
			ask(1,1,n,l,r);
			printf("%.20f\n",ff.val());
		}
	}
	return 0;
}