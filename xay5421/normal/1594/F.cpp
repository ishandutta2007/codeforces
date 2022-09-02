// author: xay5421
// created: Fri Oct  8 23:08:57 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int T;
int sol(LL s,LL n,LL K){
	if(K==s)return 1;
	if(K>s)return 0;
	if(s/n>K)return 0;
	// s/n<=K<=s
	if(n-1<K&&s-n+1>K)return 0;
	if(s>=n+K*max(1LL,n/K))return 0;
	if(n*2<=s)return 0;
	if(K>n)return 0;
	if(s%n==0){
		if(K%(s/n)!=0)return 0;
	}else{
		if(K%(s/n)!=0&&K%(s/n)!=s%n%(s/n))return 0;
	}
	return 1;
}
int brute(LL s,LL n,LL K){
	vector<int>v(n);
	function<void(int,int)>dfs=[&](int n_,int s_){
		if(n_>=n){
			if(s_!=s)return;
			bool gg=0;
			for(int i=0,j=0,ss=0;i<SZ(v);++i){
				while(j<SZ(v)&&ss<K)ss+=v[j++];
				if(ss==K)gg=1;
				ss-=v[i];
			}
			if(!gg){
				throw 0;
			}
			return;
		}
		for(int x=1;s_+x+n-n_-1<=s;++x){
			v[n_]=x;
			dfs(n_+1,s_+x);
		}
	};
	try{
		dfs(0,0);
		throw 1;
	}catch(int x){
		return x;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		LL s,n,K;
		scanf("%lld%lld%lld",&s,&n,&K);
		//if(s/n<=K&&K<s&&brute(s,n,K)==1)D("s=%lld n=%lld K=%lld\n",s,n,K),assert(n*2>s);
		puts(sol(s,n,K)?"YES":"NO");
		//D("s=%lld n=%lld K=%lld\n",s,n,K);
		//D("sol=%d brute=%d\n",sol(s,n,K),brute(s,n,K));
		//assert(sol(s,n,K)==brute(s,n,K));
	}
	return 0;
}