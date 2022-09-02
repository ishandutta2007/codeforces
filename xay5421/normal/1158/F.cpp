// author: xay5421
// created: Tue Mar 23 10:14:09 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=3005;
int n,c,a[N],fac[N],inv[N],ifac[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
namespace xay1{
	int dp[2][N][1030],ans[N];
	void sol(){
		dp[0][0][0]=1;
		rep(i,1,n){
			int rb=min(i,n/c);
			rep(j,0,rb)rep(k,0,(1<<c)-1)dp[i&1][j][k]=0;
			rep(j,0,rb)rep(k,0,(1<<c)-2){
				if(!dp[(i-1)&1][j][k])continue;
				uad(dp[i&1][j][k],dp[(i-1)&1][j][k]);
				if((k|(1<<(a[i]-1)))==(1<<c)-1){
					uad(dp[i&1][j+1][0],dp[(i-1)&1][j][k]);
				}else{
					uad(dp[i&1][j][k|(1<<(a[i]-1))],dp[(i-1)&1][j][k]);
				}
			}
		}
		rep(i,0,n)rep(j,0,(1<<c)-1)uad(ans[i],dp[n&1][i][j]);
		usu(ans[0],1);
		rep(i,0,n)printf("%d ",ans[i]);
	}
}
namespace xay2{
	int dp[N][N],f[N][N],sum[N][N],cnt[N],w1[N],w2[N],iw1[N],iw2[N];
	void sol(){
		w1[0]=1;
		rep(i,1,N-1)w1[i]=ad(w1[i-1],w1[i-1]),w2[i]=su(w1[i],1);
		rep(i,0,N-1)iw1[i]=po(w1[i],P-2),iw2[i]=po(w2[i],P-2);
		rep(i,1,n){
			memset(cnt,0,(c+1)*sizeof(cnt[0]));
			int tt=1,num=1;
			rep(j,i+1,n){
				if(a[j]==a[i]){
					tt=ad(tt,tt);
				}else{
					if(++cnt[a[j]]==1)++num;
					else tt=mu(tt,iw2[cnt[a[j]]-1]);
					if(num==c)f[i][j]=tt;
					tt=mu(tt,w2[cnt[a[j]]]);
				}
			}
		}
		//rep(i,1,n)rep(j,i+1,n)D("f[%d][%d]=%d\n",i,j,f[i][j]);
		sum[n+1][0]=1;
		per(i,n,1){
			int rb=(n-i+1)/c;
			rep(j,1,rb){
				int res=0;
				rep(k,i+c-1,n){
					uad(res,mu(f[i][k],sum[k+1][j-1]));
				}
				dp[i][j]=res;
			}
			dp[i][0]=w1[n-i];
			rep(j,0,rb)sum[i][j]=ad(sum[i+1][j],dp[i][j]);
		}
		usu(sum[1][0],1);
		rep(i,0,n)printf("%d ",su(sum[1][i],sum[1][i+1]));
	}
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d%d",&n,&c);
	rep(i,1,n)scanf("%d",&a[i]);
	if(c==1){
		printf("0 ");
		rep(i,1,n)printf("%d ",C(n,i));
		return 0;
	}
	if(c<=10){
		xay1::sol();
	}else{
		xay2::sol();
	}
	return 0;
}