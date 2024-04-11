// author: xay5421
// created: Fri Sep 10 15:28:52 2021
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
typedef long long LL;
int n,n_,m,K,e[15],u[15],v[15],s;
LL pw[15],ans;
vector<LL>st;
void dfs2(int k1,int k2,LL k3){
	if(k1>=n_){
		st.push_back(k3);
		return;
	}
	rep(i,0,k2+1){
		k3+=pw[u[k1]]*i;
		k3+=pw[v[k1]]*i;
		dfs2(k1+1,k2+(i>k2),k3);
		k3-=pw[u[k1]]*i;
		k3-=pw[v[k1]]*i;
	}
}
void dfs1(int k1,int k2,int k3){
	if(k1>=n){
		vector<vector<int> >dp((1<<n_),vector<int>(n_));
		rep(i,0,n_-1)if(e[u[i]]>>v[i]&1)dp[1<<i][i]=1;
		rep(i,0,(1<<n_)-1){
			rep(j,0,n_-1)if(i>>j&1)if(dp[i][j]){
				rep(k,0,n_-1)if((~i>>k&1)&&(((e[u[j]]>>u[k]&1)&&(e[v[j]]>>v[k]&1))||((e[v[j]]>>u[k]&1)&&(e[u[j]]>>v[k]&1)))){
					dp[i^(1<<k)][k]=1;
				}
			}
		}
		bool flg=0;
		rep(i,0,n_-1)if(dp[(1<<n_)-1][i])flg=1;
		if(flg){
			dfs2(1,0,0);
		}
		return;
	}
	if(k2>>k1&1){
		dfs1(k1+1,k2,k3);
	}else{
		rep(i,k1+1,n-1)if(~k2>>i&1){
			u[k3]=k1,v[k3]=i;
			dfs1(k1+1,k2^(1<<k1)^(1<<i),k3+1);
			u[k3]=v[k3]=0;
		}
	}
}
int main(){
	pw[0]=1;
	rep(i,1,14)pw[i]=pw[i-1]*6;
	scanf("%d%d%d",&n,&m,&K),n_=n>>1;
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		--k1,--k2;
		e[k1]|=1<<k2;
		e[k2]|=1<<k1;
	}
	dfs1(0,0,0);
	sort(st.begin(),st.end());
	st.erase(unique(st.begin(),st.end()),st.end());
	auto debug_out=[&](LL x){
		D("! ");
		rep(i,0,n-1){
			D("%lld ",x%6);
			x/=6;
		}
		D("\n");
	};
	vector<int>f(n_);
	for(auto x:st){
		int mx=0;
		LL now=x;
		while(now){
			mx=max(mx,(int)(now%6));
			now/=6;
		}
		++f[mx];
	}
	auto calc=[&](int t){
		LL res=1;
		rep(i,1,t)res*=K-i+1;
		return res;
	};
	rep(i,0,n_-1){
		ans+=f[i]*calc(i+1);
	}
	printf("%lld\n",ans);
	return 0;
}