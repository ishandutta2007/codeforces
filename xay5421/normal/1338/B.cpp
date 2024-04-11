#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005;
int n,dep[N],cnt[2],val[N],fa[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	dep[k1]=dep[k2]+1;
	for(auto&x:e[k1])if(x!=k2){
		dfs1(x,k1);
	}
	if(SZ(e[k1])<=1){
		++cnt[dep[k1]&1];
	}
}
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
int main(){
	scanf("%d",&n);
	iota(fa+1,fa+1+n,1);
	rep(i,2,n){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	rep(i,1,n)if(SZ(e[i])<=1){
		if(val[e[i][0]]){
			fa[fd(i)]=fd(val[e[i][0]]);
		}
		val[e[i][0]]=i;
	}
	if(cnt[0]==0||cnt[1]==0){
		printf("1 ");
	}else{
		printf("3 ");
	}
	int res=-1;
	rep(i,1,n)res+=fd(i)==i;
	printf("%d\n",res);
	return 0;
}