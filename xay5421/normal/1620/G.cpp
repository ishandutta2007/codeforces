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
using LL=long long;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
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
int n,a[25][26],w[(1<<23)+5],val[25][26];
char s[20005];
void dfs(int step,int mask,int op){
	if(step>=n){
		if(mask){
			int coef=1;
			rep(i,0,25)coef=mu(coef,val[step][i]+1);
			w[mask]=mu(op,coef);
		}
		return;
	}
	memcpy(val[step+1],val[step],sizeof(val[step]));
	dfs(step+1,mask,op);
	memcpy(val[step+1],val[step],sizeof(val[step]));
	rep(i,0,25)umin(val[step+1][i],a[step][i]);
	dfs(step+1,mask^(1<<step),su(0,op));
}
int main(){
	scanf("%d",&n);
	rep(i,0,n-1){
		scanf("%s",s);
		for(int j=0;s[j];++j){
			++a[i][s[j]-'a'];
		}
	}
	memset(val[0],63,sizeof(val[0]));
	dfs(0,0,P-1);
	for(int i=1;i<(1<<n);i<<=1)for(int j=0;j<(1<<n);j+=i<<1)for(int k=0;k<i;++k){
		uad(w[i+j+k],w[j+k]);
	}
	LL ans=0;
	rep(mask,1,(1<<n)-1){
		int coef=0,cnt=0;
		rep(i,0,n-1)if(mask>>i&1){
			coef+=i+1;
			++cnt;
		}
		D("ans[%d]=%d\n",mask,w[mask]);
		ans^=1LL*w[mask]*coef*cnt;
	}
	printf("%lld\n",ans);
	return 0;
}