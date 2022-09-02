// author: xay5421
// created: Sat Oct  9 00:34:18 2021
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
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005;
int K,n,lc[N],rc[N],val[N],f[N][6];
int dp[61];
map<LL,int>mp;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	memset(val,-1,sizeof(val));
	dp[0]=1;
	rep(i,1,60){
		rep(x,0,5)rep(y,0,5)rep(z,0,5)if(x%3!=y%3&&x%3!=z%3){
			uad(dp[i],mu(dp[i-1],dp[i-1]));
		}
		dp[i]=1LL*dp[i]*po(6,P-2)%P;
	}
	int K;
	scanf("%d%d",&K,&n);
	auto ID=[&](LL x){
		static int ind=0;
		if(!mp.count(x))mp[x]=++ind;
		return mp[x];
	};
	static string strs[]={"white","green","red","yellow","blue","orange"};
	rep(i,1,n){
		LL x;
		scanf("%lld",&x);
		string s;
		cin>>s;
		val[ID(x)]=0;
		while(strs[val[ID(x)]]!=s)++val[ID(x)];
		while(x>1){
			if(x&1){
				rc[ID(x/2)]=ID(x);
			}else{
				lc[ID(x/2)]=ID(x);
			}
			x>>=1;
		}
	}
	function<void(int,int)>sol=[&](int k1,int dep){
		if(!lc[k1]&&!rc[k1]){
			if(val[k1]==-1){
				rep(i,0,5)f[k1][i]=dp[K-dep];
			}
			else{
				f[k1][val[k1]]=dp[K-dep];
			}
			return;
		}
		array<int,6>lw,rw;
		assert(dep<K);
		if(!lc[k1]){
			rep(i,0,5)lw[i]=dp[K-dep-1];
		}else{
			sol(lc[k1],dep+1);
			rep(i,0,5)lw[i]=f[lc[k1]][i];
		}
		if(!rc[k1]){
			rep(i,0,5)rw[i]=dp[K-dep-1];
		}else{
			sol(rc[k1],dep+1);
			rep(i,0,5)rw[i]=f[rc[k1]][i];
		}
		/*if(ID(2)==k1){
			D("!!\n");
			rep(i,0,5)D("%d ",lw[i]);
			D("\n");
			rep(i,0,5)D("%d ",rw[i]);
			D("\n");
		}*/
		rep(x,0,5)rep(y,0,5)rep(z,0,5)if(x%3!=y%3&&x%3!=z%3){
			uad(f[k1][x],mu(lw[y],rw[z]));
		}
		if(val[k1]!=-1){
			rep(i,0,5)if(i!=val[k1])f[k1][i]=0;
		}
		/*if(ID(2)==k1){
			D("@@\n");
			rep(i,0,5)D("%d ",f[k1][i]);
			D("\n");
		}*/
	};
	sol(ID(1),1);
	int ans=0;
	rep(i,0,5)uad(ans,f[ID(1)][i]);
	printf("%d\n",ans);
	return 0;
}