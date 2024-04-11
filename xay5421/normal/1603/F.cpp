// author: xay5421
// created: Tue Nov  2 16:22:07 2021
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
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int T;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		int n,K,x;
		scanf("%d%d%d",&n,&K,&x);
		if(x==0){
			int ans=1;
			int pw=1,cur=po(2,K);
			rep(i,0,n-1){
				ans=mu(ans,su(cur,pw));
				pw=mu(pw,2);
				if(ans==0)break;
			}
			printf("%d\n",ans);
		}else{
			/*vector<int>f(K+1);
			f[0]=1;
			rep(_,1,n){
				vector<int>nf(K+1);
				rep(i,0,K){
					uad(nf[i],mu(f[i],po(2,i)));
					if(i<K)uad(nf[i+1],mu(f[i],su(po(2,K),po(2,i))));
				}
				f=nf;
			}*/
			const int inv2=(P+1)>>1;
			vector<int>q_dw(K+1),q_ifac(K+1);
			{
				int cur=po(2,n);
				q_dw[0]=1;
				rep(i,1,K){
					q_dw[i]=mu(q_dw[i-1],su(1,cur));
					cur=mu(cur,inv2);
				}
			}
			{
				q_ifac[0]=1;
				int pw=1;
				rep(i,1,K){
					pw=ad(pw,pw);
					q_ifac[i]=mu(q_ifac[i-1],su(1,pw));
				}
				q_ifac[K]=po(q_ifac[K],P-2);
				per(i,K,1){
					q_ifac[i-1]=mu(q_ifac[i],su(1,pw));
					pw=mu(pw,inv2);
				}
			}
			int ans=0,pw=1;
			auto q_binom=[&](int m,int r){
				/*assert(m==n);
				int fz=1,fm=1;
				rep(i,1,r){
					fz=mu(fz,su(1,po(2,m-i+1)));
					fm=mu(fm,su(1,po(2,i)));
				}
				assert(fz==q_dw[r]);
				assert(fm==po(q_ifac[r],P-2));
				return mu(fz,po(fm,P-2));*/
				return mu(q_dw[r],q_ifac[r]);
			};
			const int powK=po(2,K);
			int w1=1;
			for(int i=0;i<=K&&i<=n;++i){
				int res=0;
				if(i==0)res=1;
				else{
					w1=mu(w1,su(powK,pw));
					uad(res,mu(w1,q_binom(n,i)));
					pw=ad(pw,pw);
				}
				uad(ans,mu(res,pw-1));
			}
			ans=mu(ans,po(powK-1,P-2));
			ans=su(po(2,1LL*n*K%(P-1)),ans);
			printf("%d\n",ans);
		}
	}
	return 0;
}