#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=300005,K=20;
int n,m,dep[N],eu[N],ev[N],id[N],tin[N],tou[N],ind,ans,fa[N][K];
vector<int>e[N];
void dfs1(int k1){
	tin[k1]=++ind;
	for(auto x:e[k1])dfs1(x);
	tou[k1]=ind;
}
int jump(int u,int k){
	per(i,K-1,0)if(k>>i&1)u=fa[u][i];
	return u;
}
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	int qry(int l,int r){
		return qry(r)-qry(l-1);
	}
}t;
int qry_sub(int u){
	return t.qry(tin[u],tou[u]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,2,n){
		scanf("%d",&fa[i][0]),dep[i]=dep[fa[i][0]]+1;
		rep(j,1,K-1)fa[i][j]=fa[fa[i][j-1]][j-1];
		e[fa[i][0]].pb(i);
	}
	dfs1(1);
	vector<pair<int,int> >cross_e;
	rep(i,1,m){
		scanf("%d%d",&eu[i],&ev[i]);
		if(dep[eu[i]]>dep[ev[i]])swap(eu[i],ev[i]);
		if(fa[ev[i]][0]==eu[i]){
			puts("-1"),exit(0);
		}
		id[i]=i;
	}
	sort(id+1,id+1+m,[&](int x,int y){return dep[eu[x]]>dep[eu[y]];});
	rep(_,1,m){
		int i=id[_];
		if(dep[eu[i]]==dep[ev[i]]){
			cross_e.eb(eu[i],ev[i]);
			continue;
		}
		int u=jump(ev[i],dep[ev[i]]-dep[eu[i]]-1);
		if(fa[u][0]!=eu[i]){
			cross_e.eb(eu[i],ev[i]);
			continue;
		}
		if(qry_sub(u)==qry_sub(ev[i])){
			t.upd(tin[u],1);
			++ans;
		}
	}
	rep(_,0,SZ(cross_e)-1){
		int u,v;
		tie(u,v)=cross_e[_];
		if(qry_sub(u)+qry_sub(v)==ans){++ans;break;}
	}
	printf("%d\n",ans);
	return 0;
}