#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
const int N=100005,INF=0X3F3F3F3F;
int n,lb,rb,f[N],sz[N],full,root;
bool ban[N];
vector<tuple<int,int> >e[N];
tuple<int,int,int>ans={~INF,~INF,~INF};
void get_root(int u,int father){
	sz[u]=1,f[u]=0;
	for(auto&_:e[u]){
		int v;
		tie(v,ignore)=_;
		if(!ban[v]&&v!=father){
			get_root(v,u);
			sz[u]+=sz[v];
			if(f[u]<sz[v])f[u]=sz[v];
		}
	}
	if(f[u]<full-f[u])f[u]=full-f[u];
	if(f[u]<f[root])root=u;
}
int lim;
struct node{
	int dep,tot,id;
}st[N];
int top;
int maxx,best[N],best_take[N],curs[N],curs_take[N];
void dfs1(int u,int father,int dep,int tot){
	st[++top]=(node){dep,tot,u};
	if(maxx<dep){
		++maxx;
		best[maxx]=~INF,best_take[maxx]=0;
	}
	for(auto&_:e[u]){
		int v,w;
		tie(v,w)=_;
		if(!ban[v]&&v!=father){
			dfs1(v,u,dep+1,tot+(w>=lim?1:-1));
		}
	}
}
int que[N];
tuple<bool,int,int>chk(int u,int mid){
	lim=mid;
	maxx=0;
	best[0]=0,best_take[0]=u;
	for(auto&_:e[u]){
		int v,w;
		tie(v,w)=_;
		if(!ban[v]){
			top=0;
			dfs1(v,u,1,w>=lim?1:-1);
			rep(i,1,maxx)curs[i]=~INF,curs_take[i]=0;
			rep(i,1,top)if(umax(curs[st[i].dep],st[i].tot))curs_take[st[i].dep]=st[i].id;
			int he=1,ta=0,j=maxx;
			rep(i,1,maxx)if(i<=rb){ // [lb-i,rb-i]
				auto push=[&](int x){
					while(he<=ta&&best[x]>best[que[ta]])--ta;
					que[++ta]=x;
				};
				while(j>=0&&j>=lb-i){
					push(j--);
				}
				while(he<=ta&&que[he]>rb-i)++he;
				if(he<=ta){
					if(curs[i]+best[que[he]]>=0){
						//D("ok %d %d\n",curs_take[i],best_take[que[he]]);
						return {1,curs_take[i],best_take[que[he]]};
					}
				}
			}
			rep(i,1,maxx)if(umax(best[i],curs[i]))best_take[i]=curs_take[i];
		}
	}
	return {0,0,0};
}
void sol(int u){
	int old=full;
	for(auto&_:e[u]){
		int v;
		tie(v,ignore)=_;
		sz[v]=sz[v]<sz[u]?sz[v]:old-sz[u];
	}
	sort(e[u].begin(),e[u].end(),[&](auto x,auto y){return sz[get<0>(x)]<sz[get<0>(y)];});
	ban[u]=1;
	int l=0,r=1e9;
	tuple<int,int,int>now={~INF,~INF,~INF};
	while(l<=r){
		int mid=(l+r)>>1;
		int bo,U,V;
		tie(bo,U,V)=chk(u,mid);
		if(bo){
			l=mid+1;
			now={mid,U,V};
		}else{
			r=mid-1;
		}
	}
	ans=max(ans,now);
	for(auto&_:e[u]){
		int v;
		tie(v,ignore)=_;
		if(!ban[v]){
			full=sz[v];
			root=0;
			get_root(v,0);
			sol(root);
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&lb,&rb);
	rep(i,2,n){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].eb(v,w),e[v].eb(u,w);
	}
	f[0]=INF;
	root=0;
	full=n;
	get_root(1,0);
	sol(root);
	printf("%d %d\n",get<1>(ans),get<2>(ans));
	return 0;
}