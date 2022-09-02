// author: xay5421
// created: Wed Aug 18 22:36:02 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
void sol(){
	int n,K;
	scanf("%d%d",&n,&K);
	int n_=n;
	vector<int>v;
	while(n_>0){
		v.push_back(n_%10);
		n_/=10;
	}
	vector<int>v_(SZ(v));
	function<void(int,int,int)>dfs=[&](int i,int vis,int big){
		if(i<0){
			n_=0;
			per(i,SZ(v)-1,0)n_=n_*10+v_[i];
			throw n_;
		}
		rep(j,big?0:v[i],9){
			v_[i]=j;
			int vis_=vis|(1<<j);
			if(__builtin_popcount(vis_)>K)continue;
			dfs(i-1,vis_,big|(j>v[i]));
		}
	};
	dfs(SZ(v)-1,0,0);
	assert(0);
	//throw n;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		try{
			sol();
		}catch(int res){
			printf("%d\n",res);
		}
	}
	return 0;
}