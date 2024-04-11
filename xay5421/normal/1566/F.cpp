// author: xay5421
// created: Sun Sep 12 23:26:23 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,INF=0X3F3F3F3F;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int T,n,m,a[N];
LL dp[N][4];
struct seg{
	int l,r;
	bool operator<(const seg&k)const{
		return r^k.r?r<k.r:l>k.l;
	}
}b[N];
struct node{
	int opt,l,r;
	bool operator<(const node&k)const{
		return l<k.l;
	}
}c[N*2];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)rd(a[i]);
		sort(a+1,a+1+n);
		rep(i,1,m){
			rd(b[i].l),rd(b[i].r);
			int pos=lower_bound(a+1,a+1+n,b[i].l)-a;
			if(pos<=n&&b[i].l<=a[pos]&&a[pos]<=b[i].r){
				--i,--m;
				continue;
			}
		}
		sort(b+1,b+1+m);
		{
			int m_=0,l=~INF;
			rep(i,1,m){
				if(b[i].l>l){
					b[++m_]=b[i];
					l=b[i].l;
				}
			}
			m=m_;
		}
		rep(i,1,n){
			c[i]=(node){1,a[i],0};
		}
		rep(i,1,m){
			c[n+i]=(node){2,b[i].l,b[i].r};
		}
		sort(c+1,c+1+n+m);
		rep(i,0,n+m)memset(dp[i],63,sizeof(dp[i]));
		if(c[1].opt==1){
			dp[1][0]=-c[1].l;
			dp[1][1]=-c[1].l*2;
		}else{
			dp[1][2]=-c[1].r;
			dp[1][3]=-c[1].r*2;
		}
		rep(i,2,n+m){
			if(c[i].opt==1){
				if(c[i-1].opt==1){
					LL val=min(dp[i-1][0]+c[i-1].l,dp[i-1][1]+c[i-1].l*2);
					dp[i][0]=val-c[i].l;
					dp[i][1]=val-c[i].l*2;
				}else{
					LL val=min(dp[i-1][0]+c[i-1].l,dp[i-1][1]+c[i-1].l*2);
					dp[i][0]=min(val-c[i].l,dp[i-1][3]+c[i].l);
					dp[i][1]=min(val-c[i].l*2,dp[i-1][2]-c[i].l);
				}
			}else{
				if(c[i-1].opt==1){
					dp[i][0]=dp[i-1][0];
					dp[i][1]=dp[i-1][1];
					dp[i][2]=min(dp[i-1][0]+c[i-1].l,dp[i-1][1]+c[i-1].l*2)-c[i].r;
					dp[i][3]=min(dp[i-1][0]+c[i-1].l,dp[i-1][1]+c[i-1].l*2)-c[i].r*2;
				}else{
					dp[i][0]=dp[i-1][0];
					dp[i][1]=dp[i-1][1];
					dp[i][2]=min(dp[i-1][2],min(dp[i-1][0]+c[i-1].l,dp[i-1][1]+c[i-1].l*2)-c[i].r);
					dp[i][3]=min(dp[i-1][3],min(dp[i-1][0]+c[i-1].l,dp[i-1][1]+c[i-1].l*2)-c[i].r*2);
				}
			}
		}
		/*rep(i,1,n+m){
			if(c[i].opt==1){
				D("opt=1 x=%d\n",c[i].l);
				rep(j,0,1)D("%lld ",dp[i][j]);
				D("\n");
			}else{
				D("opt=2 l=%d r=%d\n",c[i].l,c[i].r);
				rep(j,0,3)D("%lld ",dp[i][j]);
				D("\n");
			}
		}*/
		if(c[n+m].opt==1){
			pt(min({dp[n+m][0]+c[n+m].l,dp[n+m][1]+c[n+m].l*2}),'\n');
		}else{
			pt(min({dp[n+m][0]+c[n+m].l,dp[n+m][1]+c[n+m].l*2}),'\n');
		}
	}
	return 0;
}