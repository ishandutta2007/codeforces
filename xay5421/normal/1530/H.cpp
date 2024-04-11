// author: xay5421
// created: Mon Aug  2 21:57:15 2021
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
const int INF=0X3F3F3F3F;
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
const int N=15005,S=505;
int T,n,a[N];
struct BIT{
	int t[N];
	void clear(int n,int v){
		fill(t,t+1+n,v);
	}
	void upd_max(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)umax(t[i],k2);
	}
	int qry_max(int k1){ // pre max
		int k2=-INF;
		for(int i=k1;i;i&=i-1)umax(k2,t[i]);
		return k2;
	}
	void upd_min(int k1,int k2){
		for(int i=k1;i;i&=i-1)umin(t[i],k2);
	}
	int qry_min(int k1){ // suf min
		int k2=INF;
		for(int i=k1;i<=n;i+=i&-i)umin(k2,t[i]);
		return k2;
	}
}F[S],G[S],F_[S],G_[S];
int f[N][S],g[N][S];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		per(i,n,1)scanf("%d",&a[i]);
		int ans=1;
		rep(opt,0,1){
			D("opt=%d\n",opt);
			rep(i,0,S-1)F[i].clear(n,INF),G[i].clear(n,-INF),F_[i].clear(n,INF),G_[i].clear(n,-INF);
			rep(i,1,n)rep(j,0,S-1)f[i][j]=INF,g[i][j]=-INF;
			if(opt==0){ // choose
				f[1][1]=a[1];
				g[1][1]=a[1];
				F[1].upd_min(a[1],a[1]);
				G[1].upd_max(a[1],a[1]);
			}else{
				
			}
			rep(i,2,n){
				per(j,S-1,2){
					/*if(opt==0&&i==2&&j==2){
						D("!!\n");
					}*/
					umin(f[i][j],F[j-1].qry_min(a[i]));
					umax(g[i][j],G[j-1].qry_max(a[i]));
					int x=i-j+1;
					if(x>=1&&g[x][j-1]>=1){
						F_[j-1].upd_min(g[x][j-1],a[x]);
					}
					if(x>=1&&f[x][j-1]<=n){
						G_[j-1].upd_max(f[x][j-1],a[x]);
					}
					umin(f[i][j],F_[j-1].qry_min(a[i]));
					umax(g[i][j],G_[j-1].qry_max(a[i]));
					if(f[i][j]<=n||g[i][j]>=1){
						ans=max(ans,j-opt);
					}
				}
				if(opt==1){
					umin(f[i][2],a[i]);
					umax(g[i][2],a[i]);
					F[2].upd_min(a[i],a[i]);
					G[2].upd_max(a[i],a[i]);
				}
				per(j,S-1,2){
					if(f[i][j]<=n){
						F[j].upd_min(a[i],f[i][j]);
					}
					if(g[i][j]>=1){
						G[j].upd_max(a[i],g[i][j]);
					}
				}
			}
			/*rep(i,1,n)rep(j,0,S-1){
				if(f[i][j]<=n)printf("f[%d][%d]=%d\n",i,j,f[i][j]);
			}
			rep(i,1,n)rep(j,0,S-1){
				if(g[i][j]>=1)printf("g[%d][%d]=%d\n",i,j,g[i][j]);
			}*/
		}
		printf("%d\n",ans);
	}
	return 0;
}