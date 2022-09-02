// author: xay5421
// created: Thu Oct 28 17:59:39 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int n,K,dep[N],pre[N],ans[N];
vector<int>e[N];
bool vis[N];
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1,pre[k1]=k2;
	for(auto x:e[k1])if(x!=k2)dfs1(x,k1);
}
int mx;
void dfs2(int k1,int k2,int k3,int k4,int k5){
	mx=max(mx,k3),ans[k1]=k4;
	for(auto x:e[k1])if(x!=k2&&!vis[x]){
		dfs2(x,k1,k3+1,(k4+k5-1)%K+1,k5);
	}
}
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	dfs1(1,0);
	if(K==2){
		puts("Yes");
		rep(i,1,n)printf("%d ",dep[i]&1?1:2);
		exit(0);
	}
	int root1=max_element(dep+1,dep+1+n)-dep;
	dfs1(root1,0);
	int root2=max_element(dep+1,dep+1+n)-dep;
	vector<int>lu;
	for(int i=root2;i;i=pre[i])lu.pb(i),vis[i]=1;
	rep(i,0,SZ(lu)-1){
		mx=0;
		if(i<SZ(lu)/2){
			dfs2(lu[i],0,0,i%K+1,K-1);
			if(mx>0&&mx+i+1>=K){
				puts("No"),exit(0);
			}
		}else{
			dfs2(lu[i],0,0,i%K+1,1);
			if(mx>0&&mx+SZ(lu)-i>=K){
				puts("No"),exit(0);
			}
		}
	}
	puts("Yes");
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}