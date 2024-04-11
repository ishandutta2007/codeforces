// author: xay5421
// created: Mon Oct 18 17:24:14 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,K=20;
int n,Q,dep[N],val[N],start[N],f[N][K],g[N][K],id[N],mx[N],ans[N][2];
vector<pair<int,int> >e[N];
struct ufs{
	int n;
	vector<int>fa;
	ufs(int n):n(n){
		fa.assign(n,0);
		rep(i,0,n-1)fa[i]=i;
	}
	void reset(int n_){
		n=n_;
		rep(i,0,n-1)fa[i]=i;
	}
	void clear(){
		rep(i,0,n-1)fa[i]=i;
	}
	int fd(int k1){
		return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);
	}
	int chk(int k1,int k2){
		return fd(k1)==fd(k2);
	}
	int mer(int k1,int k2){
		k1=fd(k1),k2=fd(k2);
		if(k1==k2)return 0;
		fa[k1]=k2;
		return 1;
	}
};
void dfs1(int k1,int k2,int k3){
	dep[k1]=dep[k2]+1;
	f[k1][0]=k2,g[k1][0]=k3;
	rep(i,1,K-1)f[k1][i]=f[f[k1][i-1]][i-1];
	rep(i,1,K-1)g[k1][i]=max(g[k1][i-1],g[f[k1][i-1]][i-1]);
	for(auto x:e[k1])if(x.first!=k2)dfs1(x.first,k1,x.second);
}
int qmax(int k1,int k2){
	if(dep[k1]<dep[k2])swap(k1,k2);
	int dt=dep[k1]-dep[k2];
	int mx=0;
	per(i,K-1,0)if(dt>>i&1)mx=max(mx,g[k1][i]),k1=f[k1][i];
	if(k1==k2)return mx;
	per(i,K-1,0)if(f[k1][i]!=f[k2][i])mx=max({mx,g[k1][i],g[k2][i]}),k1=f[k1][i],k2=f[k2][i];
	return max({mx,g[k1][0],g[k2][0]});
}
struct node{
	int res,any;
}w[N];
node mer(node k1,node k2){
	return (node){max({k1.res,k2.res,qmax(k1.any,k2.any)}),k1.any};
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",&mx[i]);
	vector<tuple<int,int,int,int> >es;
	rep(i,2,n){
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		e[a].eb(b,t);
		e[b].eb(a,t);
		es.eb(c,a,b,t);
	}
	dfs1(1,0,0);
	sort(es.begin(),es.end());
	reverse(es.begin(),es.end());
	rep(i,1,Q){
		scanf("%d%d",&val[i],&start[i]);
		id[i]=i;
	}
	sort(id+1,id+1+Q,[&](int x,int y){
		return val[x]>val[y];
	});
	rep(i,1,n){
		w[i]=(node){0,i};
	}
	ufs o(n+1);
	auto ps=[&](tuple<int,int,int,int>x,int v){
		int a,b,c,t;
		tie(c,a,b,t)=x;
		if(c<v)return 0;
		if(!o.chk(a,b)){
			int k1=o.fd(a);
			int k2=o.fd(b);
			if(mx[k1]==mx[k2]){
				w[k2]=mer(w[k2],w[k1]);
			}else if(mx[k1]>mx[k2]){
				mx[k2]=mx[k1];
				w[k2]=w[k1];
			}
			o.mer(k1,k2);
		}
		return 1;
	};
	int j=0;
	rep(_,1,Q){
		int i=id[_];
		while(j<SZ(es)&&ps(es[j],val[i]))++j;
		int x=start[i];
		int k1=o.fd(x);
		ans[i][0]=mx[k1];
		ans[i][1]=max(w[k1].res,qmax(w[k1].any,x));
	}
	rep(i,1,Q)printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}