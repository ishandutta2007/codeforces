// author: xay5421
// created: Fri Sep  3 09:05:55 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int n,K,sz[11],sz_[11];
bool vis[41];
LL s[11],ss[11][45];
LL sort_(LL st,int x,int y){
	int tt=__builtin_popcountll(st&s[x])+y;
	//assert(tt<=sz[x]);
	return (st&~s[x])|ss[x][tt];
}
bool dfs(int k1,LL st){
	if(k1>=K){
		return (st&(st+1))==0;
	}
	rep(i,0,sz_[k1]){
		if(!dfs(k1+1,sort_(st,k1,i))){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&K);
	if(n==1)puts("ACCEPTED"),exit(0);
	rep(i,0,K-1){
		int k;
		scanf("%d",&k);
		sz[i]=k;
		vector<int>v;
		while(k--){
			int x;
			scanf("%d",&x);
			--x;
			s[i]|=1LL<<x;
			v.push_back(x);
			if(!vis[x])++sz_[i],vis[x]=1;
		}
		LL now=0;
		rep(j,0,SZ(v)){
			ss[i][j]=now;
			if(j<SZ(v))now^=1LL<<v[j];
		}
	}
	rep(i,0,n-1)if(!vis[i])puts("REJECTED"),exit(0);
	puts(dfs(0,0)?"ACCEPTED":"REJECTED");
	return 0;
}