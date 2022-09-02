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
const int N=1005,M=1005,INF=0X3F3F3F3F;
int n,m;
int S,T;
tuple<int,int,int>g[M];
vector<pair<int,int> >e[N],ie[N];
struct mf_graph{
	int pp=1,lnk[N],cur[N],nxt[M*4],to[M*4],we[M*4];
	void ae(int k1,int k2,int k3){
		to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
		to[++pp]=k1,we[pp]=0, nxt[pp]=lnk[k2],lnk[k2]=pp;
	}
	int q[N],dep[N];
	bool bfs(){
		fill(dep+1,dep+1+n,INF);
		int he=0,ta=0;
		dep[S]=0;
		q[++ta]=S;
		while(he!=ta){
			int k1=q[++he];
			for(int i=lnk[k1];i;i=nxt[i])if(we[i]&&dep[k1]+1<dep[to[i]]){
				dep[to[i]]=dep[k1]+1;
				q[++ta]=to[i];
			}
		}
		return dep[T]<INF;
	}
	int dfs(int k1,int k2){
		if(k1==T)return k2;
		int k3=k2;
		for(int&i=cur[k1];i;i=nxt[i])if(we[i]&&dep[k1]+1==dep[to[i]]){
			int f=dfs(to[i],min(k3,we[i]));
			k3-=f,we[i]-=f,we[i^1]+=f;
			if(!k3)return k2;
		}
		dep[k1]=INF;
		return k2-k3;
	}
	int sol(){
		int ans=0;
		while(bfs()){
			copy(lnk+1,lnk+1+n,cur+1);
			ans+=dfs(S,INF);
		}
		return ans;
	}
}f;
int res[M];
pair<int,int>pre1[N],pre2[N];
bool vis1[N],vis2[N];
void add1(int u,int k){
	if(u==S){
		throw 0;
	}
	if(vis1[u])return;
	vis1[u]=1;
	for(auto&x:ie[u]){
		res[x.second]+=k;
		if(!vis1[x.first]){
			pre1[x.first]={u,x.second};
			add1(x.first,k);
		}
		res[x.second]-=k;
	}
}
void add2(int u,int k){
	if(u==T){
		throw 0;
	}
	if(vis2[u])return;
	vis2[u]=1;
	for(auto&x:e[u]){
		res[x.second]+=k;
		if(!vis2[x.first]){
			pre2[x.first]={u,x.second};
			add2(x.first,k);
		}
		res[x.second]-=k;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	vector<pair<int,int> >others;
	rep(i,1,m){
		int u,v,opt;
		scanf("%d%d%d",&u,&v,&opt);
		g[i]={u,v,opt};
		if(opt==1){
			e[u].eb(v,i);
			ie[v].eb(u,i);
			others.eb(v,u);
			f.ae(u,v,1);
		}else{
			f.ae(u,v,INF); //  >0 =0  INF
		}
	}
	for(auto&_:others){
		int u,v;
		tie(u,v)=_;
		f.ae(u,v,INF);
	}
	int ans=f.sol();
	printf("%d\n",ans);
	rep(i,1,m)if(get<2>(g[i])&&res[i]==0){
		bool gg=0;
		try{
			fill(vis1+1,vis1+1+n,0);
			fill(pre1+1,pre1+1+n,pair<int,int>{0,0});
			add1(get<0>(g[i]),1);
			gg=1;
		}catch(int x){
			
		}
		try{
			fill(vis2+1,vis2+1+n,0);
			fill(pre2+1,pre2+1+n,pair<int,int>{0,0});
			add2(get<1>(g[i]),1);
			gg=1;
		}catch(int x){
			
		}
		if(gg){
			bool found=0;
			rep(u,1,n)if(vis1[u]&&vis2[u]){
				{
					int k1=u;
					while(k1!=get<0>(g[i])){
						++res[pre1[k1].second];
						k1=pre1[k1].first;
					}
				}
				{
					int k1=u;
					while(k1!=get<1>(g[i])){
						++res[pre2[k1].second];
						k1=pre2[k1].first;
					}
				}
				++res[i];
				found=1;
				break;
			}
			assert(found);
		}else{
			++res[i];
		}
	}
	rep(i,1,m){
		int u,v,opt;
		tie(u,v,opt)=g[i];
		if(opt==0){
			int cut=f.dep[u]<INF&&f.dep[v]>=INF;
			puts("0 1");
		}else{
			int cut=f.dep[u]<INF&&f.dep[v]>=INF;
			printf("%d %d\n",res[i],res[i]+!cut);
		}
	}
	return 0;
}