#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int n,ans,pre[N];vector<int>G[N];
void dfs1(int k1,int k2){
	for(auto j:G[k1])if(j!=k2){
		dfs1(j,k1);
	}
	if(k2&&!pre[k2]&&!pre[k1]){
		pre[k1]=k2,pre[k2]=k1;
		ans+=2;
	}
}
void dfs2(int k1,int k2){
	if(!pre[k1]){
		pre[k1]=pre[k2],pre[k2]=k1;
		ans+=2;
	}
	for(auto j:G[k1])if(j!=k2){
		dfs2(j,k1);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int k1,k2;scanf("%d%d",&k1,&k2);
		G[k1].push_back(k2),G[k2].push_back(k1);
	}
	dfs1(1,0);
	int rt=1;
	rep(i,1,n)if(pre[i])rt=i;
	dfs2(rt,0);
	printf("%d\n",ans);
	rep(i,1,n)printf("%d ",pre[i]);
	return 0;
}