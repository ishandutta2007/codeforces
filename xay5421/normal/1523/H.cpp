// author: xay5421
// created: Thu Jun  3 11:23:56 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#pragma GCC optimize(2,3,"Ofast")
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=20005,K=15;
int n,Q,a[N],lg[N],mx[N][K],f[N][K][35];
int mymax(int i,int j){return i+a[i]>j+a[j]?i:j;}
int ask(int l,int r){
	int x=lg[r-l+1];
	return mymax(mx[l][x],mx[r-(1<<x)+1][x]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,2,N-1)lg[i]=lg[i>>1]+1;
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&a[i]),mx[i][0]=i;
	rep(j,1,K-1){
		rep(i,1,n-(1<<j)+1)mx[i][j]=mymax(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	}
	rep(k,0,30){
		rep(i,1,n){
			f[i][0][k]=min(n,i+a[i]+k);
		}
		rep(j,1,K-1){
			rep(i,1,n){
				rep(t,0,k){
					int pos=ask(i,f[i][j-1][t]);
					f[i][j][k]=max(f[i][j][k],f[pos][j-1][k-t]);
				}
			}
		}
	}
	while(Q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(l==r){puts("0");continue;}
		if(l+a[l]+k>=r){puts("1");continue;}
		static int dp[35],_dp[35];
		memset(dp,0,sizeof(dp));
		int now=1;
		rep(i,0,k)dp[i]=f[l][0][i];
		per(i,K-1,0){
			memcpy(_dp,dp,sizeof(_dp));
			rep(j,0,k){
				assert(l<=dp[j]);
				int pos=ask(l,dp[j]);
				rep(t,0,k-j){
					_dp[j+t]=max(_dp[j+t],f[pos][i][t]);
				}
			}
			if(_dp[k]>=r){
				// pass
			}else{
				now+=1<<i;
				rep(j,0,k)dp[j]=_dp[j];
			}
		}
		printf("%d\n",now+1);
	}
	return 0;
}