// author: xay5421
// created: Mon May 31 15:02:42 2021
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
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
const int INF=0X3F3F3F3F;
int n,m,xa[15],ya[15],xb[105],yb[105],t[105],f[105][(1<<14)+5],g[105][(1<<14)+5],h[105][(1<<14)+5],I[15][(1<<14)+5];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	rep(i,0,n-1)scanf("%d%d",&xa[i],&ya[i]);
	{
		static int _xb[105],_yb[105],_t[105],id[105];
		rep(i,1,m)scanf("%d%d%d",&_xb[i],&_yb[i],&_t[i]),id[i]=i;
		sort(id+1,id+1+m,[&](int k1,int k2){return _t[k1]<_t[k2];});
		rep(i,1,m){
			xb[i]=_xb[id[i]];
			yb[i]=_yb[id[i]];
			t[i]=_t[id[i]];
		}
	}
	memset(h,63,sizeof(h));
	rep(i,1,m){
		rep(s,1,(1<<n)-1){
			int j=__builtin_ctz(s);
			h[i][s]=min(h[i][s&(s-1)],abs(xb[i]-xa[j])+abs(yb[i]-ya[j]));
		}
	}
	memset(I,63,sizeof(I));
	rep(i,0,n-1){
		rep(s,1,(1<<n)-1){
			int j=__builtin_ctz(s);
			I[i][s]=min(I[i][s&(s-1)],abs(xa[i]-xa[j])+abs(ya[i]-ya[j]));
		}
	}
	memset(f,192,sizeof(f));
	memset(g,63,sizeof(g));
	rep(i,0,n-1)g[0][1<<i]=0;
	rep(i,1,m)f[i][0]=1;
	rep(s,0,(1<<n)-1){
		rep(i,1,m){
			for(int j=m;j>=0&&j>=f[i][s];--j){
				if(g[j][s]+h[i][s]<=t[i]){
					f[i][s]=j+1;
					break;
				}
			}
		}
		rep(i,1,m){
			rep(j,1,i-1)if(t[j]+min(abs(xb[i]-xb[j])+abs(yb[i]-yb[j]),h[i][s])<=t[i]){
				f[i][s]=max(f[i][s],f[j][s]+1);
			}
		}
		rep(i,1,m)if(f[i][s]>=0)rep(j,0,n-1)if(~s>>j&1){
			umin(g[f[i][s]][s^(1<<j)],t[i]+min(I[j][s],abs(xa[j]-xb[i])+abs(ya[j]-yb[i])));
		}
		rep(i,0,m-1)rep(j,0,n-1)if(~s>>j&1){
			umin(g[i][s^(1<<j)],g[i][s]+I[j][s]);
		}
	}
	rep(i,0,m)rep(j,0,(1<<n)-1)if(f[i][j]>0)D("f[%d][%d]=%d\n",i,j,f[i][j]);
	rep(i,0,n)rep(j,0,(1<<n)-1)if(g[i][j]<INF)D("g[%d][%d]=%d\n",i,j,g[i][j]);
	/*per(i,m,1){
		rep(j,0,(1<<n)-1)if(g[i][j]<INF)printf("%d\n",i),exit(0);
	}*/
	int ans=0;
	rep(i,1,m)rep(j,0,(1<<n)-1)ans=max(ans,f[i][j]);
	printf("%d\n",ans);
	return 0;
}