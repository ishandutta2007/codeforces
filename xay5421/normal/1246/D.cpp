#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005,INF=0X3F3F3F3F;
int n,fa[N],f[N],g[N],who[N];
vector<int>e[N];
void dfs1(int k1){
	if(SZ(e[k1])==0){
		f[k1]=0;
		g[k1]=0;
	}else if(SZ(e[k1])==1){
		dfs1(e[k1][0]);
		f[k1]=f[e[k1][0]];
		g[k1]=g[e[k1][0]]+1;
	}else{
		tuple<int,int>dt={INF,-1};
		for(auto&x:e[k1]){
			dfs1(x);
			g[k1]+=g[x]+1;
			dt=min(dt,{f[x]-g[x]-1,x});
		}
		f[k1]=g[k1]+get<0>(dt);
		who[k1]=get<1>(dt);
	}
}
int nd[N],len;
vector<int>v;
void dfs2(int k1,int opt){
	nd[++len]=k1;
	if(SZ(e[k1])==0){
	}else if(SZ(e[k1])==1){
		dfs2(e[k1][0],opt);
		if(opt==1){
			v.pb(len+1);
		}
	}else{
		if(opt==0){
			for(auto&x:e[k1])if(x!=who[k1]){
				dfs2(x,1);
				v.pb(len+1);
			}
			if(who[k1]){
				dfs2(who[k1],0);
			}
		}else{
			for(auto&x:e[k1]){
				dfs2(x,1);
				v.pb(len+1);
			}
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d",&fa[i]);
		e[fa[i]].pb(i);
	}
	dfs1(0);
	dfs2(0,0);
	rep(i,1,len)printf("%d ",nd[i]);
	printf("\n%d\n",SZ(v));
	for(auto&x:v)printf("%d ",nd[x]);
	puts("");
	return 0;
}