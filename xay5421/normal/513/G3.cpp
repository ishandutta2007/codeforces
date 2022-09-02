// author: xay5421
// created: Fri Nov 27 15:06:59 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=105;
int n,K,p[N];
double odp[N][N],dp[N][N];
int calc(int x){
	return x*(x+1)/2;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&K),K=min(K,1000);
	const int tot=n*(n+1)/2;
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)rep(j,i+1,n)dp[i][j]=1;
	rep(_,1,K){
		memcpy(odp,dp,sizeof(odp));
		rep(i,1,n)rep(j,i+1,n){
			dp[i][j]=odp[i][j]*(calc(i-1)+calc(j-i-1)+calc(n-j))/tot;
			rep(k,1,j-1){
				dp[i][j]+=odp[k][j]*min(min(k,i),min(j-i,j-k))/tot;
			}
			rep(k,i+1,n){
				dp[i][j]+=odp[i][k]*min(min(j-i,k-i),min(n-j+1,n-k+1))/tot;
			}
			const int len=j-i+1;
			rep(k,1,n-len+1){
				dp[i][j]+=(1.-odp[k][k+len-1])*min(min(i,k),min(n-k-len+1+1,n-j+1))/tot;
			}
			//D("dp[%d][%d]=%f\n",i,j,dp[i][j]);
		}
	}
	double ans=0;
	rep(i,1,n)rep(j,i+1,n)if(p[i]>p[j])ans+=dp[i][j];else ans+=1-dp[i][j];
	printf("%.20f\n",ans);
	return 0;
}