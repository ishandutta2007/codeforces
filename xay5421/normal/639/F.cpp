#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include<bits/stdc++.h>
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=300005,K=20;
int n,m,Q;
struct Graph{
	int pp,lnk[N],nxt[N*2],to[N*2];
	void clear(){
		while(pp>1){
			lnk[to[pp]]=lnk[to[pp^1]]=0;
			pp-=2;
		}
		pp=1;
	}
	Graph(){clear();}
	void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
	void ae2(int k1,int k2){
		D("ae %d %d\n",k1,k2);
		ae(k1,k2),ae(k2,k1);
	}
}G1,G2,G3;
vector<int>rt;
namespace N1{
	int st[N],top,dfn[N],low[N],ind,bel[N],cnt;
	void tarjan(int k1,int k2){
		st[++top]=k1,dfn[k1]=low[k1]=++ind;
		for(int i=G1.lnk[k1];i;i=G1.nxt[i])if(i/2!=k2/2){
			if(!dfn[G1.to[i]])tarjan(G1.to[i],i),low[k1]=min(low[k1],low[G1.to[i]]);
			else low[k1]=min(low[k1],dfn[G1.to[i]]);
		}
		if(low[k1]==dfn[k1]){
			++cnt;
			do{
				bel[st[top]]=cnt;
			}while(st[top--]!=k1);
		}
	}
	void init(){
		rep(i,1,n)if(!dfn[i])tarjan(i,0),rt.PB(i);
		for(int i=2;i<=G1.pp;i+=2){
			int k1=bel[G1.to[i^1]],k2=bel[G1.to[i]];
			if(k1!=k2){
				G2.ae2(k1,k2);
			}
		}
		for(auto&x:rt)x=bel[x];
	}
}
namespace N2{
	int tin[N],tou[N],ind,bel[N],dep[N],fa[N][K];
	void dfs(int k1,int k2,int k3){
		tin[k1]=++ind,bel[k1]=k3,fa[k1][0]=k2,dep[k1]=dep[k2]+1;
		for(int i=1;i<K;++i)fa[k1][i]=fa[fa[k1][i-1]][i-1];
		for(int i=G2.lnk[k1];i;i=G2.nxt[i])if(G2.to[i]!=k2){
			dfs(G2.to[i],k1,k3);
		}
		tou[k1]=ind;
	}
	void init(){
		for(auto x:rt)dfs(x,0,x);
	}
	int LCA(int k1,int k2){
		if(dep[k1]<dep[k2])swap(k1,k2);
		int ret=dep[k1]-dep[k2];
		per(i,K-1,0)if(ret>>i&1)k1=fa[k1][i];
		if(k1==k2)return k1;
		per(i,K-1,0)if(fa[k1][i]!=fa[k2][i])k1=fa[k1][i],k2=fa[k2][i];
		return fa[k1][0];
	}
}
using N2::LCA;
void bud(int rt,const vector<int>&v){
	vector<int>st;
	st.PB(rt);
	rep(i,0,SZ(v)-1)if(st.back()!=v[i]){
		int t=LCA(st.back(),v[i]);
		if(t!=st.back()){
			while(SZ(st)>1&&N2::dep[t]<N2::dep[st[SZ(st)-2]]){
				G3.ae2(st.back(),st[SZ(st)-2]);
				st.pop_back();
			}
			if(st[SZ(st)-2]!=t){
				G3.ae2(t,st.back());
				st.pop_back();
				st.PB(t);
			}else{
				G3.ae2(st[SZ(st)-2],st.back());
				st.pop_back();
			}
		}
		st.PB(v[i]);
	}
	while(SZ(st)>1){
		D(">>> ");
		G3.ae2(st.back(),st[SZ(st)-2]);
		st.pop_back();
	}
}
namespace N3{
	int st[N],top,dfn[N],low[N],ind,bel[N],cnt;
	vector<int>tmp;
	void tarjan(int k1,int k2){
		tmp.PB(k1);
		st[++top]=k1,dfn[k1]=low[k1]=++ind;
		for(int i=G3.lnk[k1];i;i=G3.nxt[i])if(i/2!=k2/2){
			if(!dfn[G3.to[i]])tarjan(G3.to[i],i),low[k1]=min(low[k1],low[G3.to[i]]);
			else low[k1]=min(low[k1],dfn[G3.to[i]]);
		}
		if(low[k1]==dfn[k1]){
			++cnt;
			do{
				bel[st[top]]=cnt;
			}while(st[top--]!=k1);
		}
	}
	int sol(const vector<int>&v,const vector<int>&vv){
		tmp.clear();
		cnt=0,ind=0;
		rep(i,0,SZ(v)-1){
			if(!dfn[v[i]]){
				tarjan(v[i],0);
			}
		}
		bool flg=1;
		rep(i,1,SZ(vv)-1)flg&=bel[vv[i]]==bel[vv[0]];
		for(auto x:tmp)dfn[x]=low[x]=0;
		return flg;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,m){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		G1.ae2(k1,k2);
	}
	N1::init();
	N2::init();
	int R=0;
	auto rotate=[&](int x){
		x=(x+R)%n;
		if(x==0)x=n;
		return x;
	};
	rep(_,1,Q){
		int n0,m0;
		scanf("%d%d",&n0,&m0);
		vector<int>v,vv;
		vector<pair<int,int> >e;
		rep(i,1,n0){
			int k1;
			scanf("%d",&k1);
			k1=rotate(k1);
			if(_==2){
				D("# %d\n",k1);
			}
			k1=N1::bel[k1];
			v.PB(k1),vv.PB(k1);
		}
		G3.clear();
		rep(i,1,m0){
			int k1,k2;
			scanf("%d%d",&k1,&k2);
			k1=rotate(k1),k2=rotate(k2);
			if(_==2){
				D("$$$ %d %d\n",k1,k2);
			}
			k1=N1::bel[k1],k2=N1::bel[k2];
			v.PB(k1),v.PB(k2);
			e.EB(k1,k2);
		}
		D("----- begin -----\n");
		sort(v.begin(),v.end(),[&](int k1,int k2){return N2::tin[k1]<N2::tin[k2];});
		v.erase(unique(v.begin(),v.end()),v.end()); //
		for(int i=0,j=0;i<SZ(v);i=j){
			while(j<SZ(v)&&N2::bel[v[i]]==N2::bel[v[j]])++j;
			bud(N2::bel[v[i]],vector<int>(v.begin()+i,v.begin()+j));
		}
		for(auto x:e){
			G3.ae2(x.X,x.Y);
		}
		D("----- end -----\n");
		int res=N3::sol(v,vv);
		if(res)(R+=_)%=n;
		puts(res?"YES":"NO");
	}
	return 0;
}