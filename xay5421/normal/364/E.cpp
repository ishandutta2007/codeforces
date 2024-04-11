// author: xay5421
// created: Thu Apr 22 09:11:51 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=2505;
int n,m,K,a[N][N],up[2][10];
LL ans;
int calc(int k1,int k2,int k3,int k4){
	return a[k3][k4]-a[k1-1][k4]-a[k3][k2-1]+a[k1-1][k2-1];
}
void sol(int k1,int k2,int k3,int k4){
	if(k1==k3&&k2==k4){
		ans+=calc(k1,k2,k3,k4)==K;
		return;
	}
	if(k3-k1>=k4-k2){
		int mid=(k1+k3)>>1;
		rep(l,k2,k4){
			up[0][0]=mid+1,up[1][0]=mid;
			rep(i,1,K+1)up[0][i]=k1,up[1][i]=k3;
			rep(r,l,k4){
				rep(i,1,K+1){
					while(calc(up[0][i],l,mid,r)>=i)++up[0][i];
					while(calc(mid+1,l,up[1][i],r)>=i)--up[1][i];
				}
				rep(i,0,K){
					ans+=(up[0][i]-up[0][i+1])*(up[1][K-i+1]-up[1][K-i]);
				}
			}
		}
		//D("[%d,%d],[%d,%d] %lld\n",k1,k2,k3,k4,ans);
		sol(k1,k2,mid,k4);
		sol(mid+1,k2,k3,k4);
	}else{
		int mid=(k2+k4)>>1;
		rep(l,k1,k3){
			up[0][0]=mid+1,up[1][0]=mid;
			rep(i,1,K+1)up[0][i]=k2,up[1][i]=k4;
			rep(r,l,k3){
				rep(i,1,K+1){
					while(calc(l,up[0][i],r,mid)>=i)++up[0][i];
					while(calc(l,mid+1,r,up[1][i])>=i)--up[1][i];
				}
				rep(i,0,K){
					ans+=(up[0][i]-up[0][i+1])*(up[1][K-i+1]-up[1][K-i]);
				}
			}
		}
		//D("[%d,%d],[%d,%d] %lld\n",k1,k2,k3,k4,ans);
		sol(k1,k2,k3,mid);
		sol(k1,mid+1,k3,k4);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	rep(i,1,n)rep(j,1,m){int c;while(!isdigit(c=getchar()));a[i][j]=c&1,a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];}
	sol(1,1,n,m);
	printf("%lld\n",ans);
	return 0;
}