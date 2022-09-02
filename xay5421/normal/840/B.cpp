#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=300005;
int n,m,d[N],deg[N],root;
vector<int>ans;
vector<tuple<int,int> >e[N];
struct ufs{
	int fa[N];
	ufs(){iota(fa,fa+N,0);}
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
}o;
void dfs1(int k1,int k2,int k3){
	for(auto&x:e[k1]){
		int v,id;
		tie(v,id)=x;
		if(v!=k2)dfs1(v,k1,id);
	}
	if(d[k1]!=-1&&deg[k1]!=d[k1]){
		if(k1==root){puts("-1"),exit(0);}
		ans.pb(k3);
		deg[k1]^=1,deg[k2]^=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&d[i]);
	rep(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		if(o.fd(u)!=o.fd(v)){
			o.fa[o.fd(u)]=o.fd(v);
			e[u].eb(v,i),e[v].eb(u,i);
		}
	}
	root=1;
	rep(i,1,n)if(d[i]==-1){
		root=i;
		break;
	}
	dfs1(root,0,0);
	printf("%d\n",(int)ans.size());
	for(auto&x:ans)printf("%d ",x);
	return 0;
}