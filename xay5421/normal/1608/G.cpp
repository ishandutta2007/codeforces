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
const int P=998244853;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=200005,B=31,K=18,INF=0X3F3F3F3F;
int n,m,Q,in[N],out[N],pw[N*2],ans[N];
char ss[N];
vector<pair<int,char> >e[N];
int up[N/2][K],dep[N];
struct hash_t{
	int v,len;
	bool operator==(const hash_t&k)const{
		return len==k.len&&v==k.v;
	}
	hash_t operator+(const hash_t&k)const{
		return (hash_t){ad(mu(v,pw[k.len]),k.v),len+k.len};
	}
}f[N/2][K],g[N/2][K],hss[N];
hash_t ghs(int l,int r){
	if(l==0)return hss[r];
	return (hash_t){su(hss[r].v,mu(hss[l-1].v,pw[r-l+1])),r-l+1};
}
int LCA(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	int dt=dep[u]-dep[v];
	per(i,K-1,0)if(dt>>i&1)u=up[u][i];
	if(u==v)return u;
	per(i,K-1,0)if(up[u][i]!=up[v][i]){
		u=up[u][i];
		v=up[v][i];
	}
	return up[u][0];
}
int kth_fa(int u,int k){
	per(i,K-1,0)if(k>>i&1)u=up[u][i];
	return u;
}
hash_t get_hash(int u,int v){
	hash_t a=(hash_t){0,0},b=(hash_t){0,0};
	if(dep[u]>dep[v]){
		int dt=dep[u]-dep[v];
		per(i,K-1,0)if(dt>>i&1){
			a=a+f[u][i];
			u=up[u][i];
		}
	}
	if(dep[v]>dep[u]){
		int dt=dep[v]-dep[u];
		per(i,K-1,0)if(dt>>i&1){
			b=g[v][i]+b;
			v=up[v][i];
		}
	}
	if(u==v)return a+b;
	per(i,K-1,0)if(up[u][i]!=up[v][i]){
		a=a+f[u][i];
		b=g[v][i]+b;
		u=up[u][i];
		v=up[v][i];
	}
	return a+f[u][0]+f[v][0]+b;
}
hash_t asks(int u,int v,int lca,int lim){
	if(dep[v]-dep[lca]>=lim){
		return get_hash(kth_fa(v,lim),v);
	}else{
		lim-=dep[v]-dep[lca];
		if(lim>=0&&lim<=dep[u]-dep[lca]){
			return get_hash(kth_fa(u,dep[u]-dep[lca]-lim),lca)+get_hash(lca,v);
		}else{
			return (hash_t){-1,-1};
		}
	}
}
char fa_ch[N];
int find_ch(int u,int v,int lca,int lim){
	if(dep[v]-dep[lca]>=lim){
		return fa_ch[kth_fa(v,lim-1)];
	}else{
		lim-=dep[v]-dep[lca];
		return fa_ch[kth_fa(u,dep[u]-dep[lca]-lim)];
	}
}
void dfs1(int u,int father,char father_c){
	up[u][0]=father,dep[u]=dep[father]+1,fa_ch[u]=father_c;
	if(father){
		f[u][0]=g[u][0]=(hash_t){father_c-'a'+1,1};
	}
	rep(i,1,K-1){
		up[u][i]=up[up[u][i-1]][i-1];
		if(up[u][i]){
			f[u][i]=f[u][i-1]+f[up[u][i-1]][i-1];
			g[u][i]=g[up[u][i-1]][i-1]+g[u][i-1];
		}
	}
	for(auto&_:e[u]){
		int v;
		char c;
		tie(v,c)=_;
		if(v!=father){
			dfs1(v,u,c);
		}
	}
}
struct SAM{
	int cnt,lst,fa[N*2],ch[N*2][27],len[N*2],pos[N*2],right[N*2],fuck_sz[N*2],fuck_son[N*2];
	vector<tuple<int,char> >e[N*2];
	SAM(){cnt=lst=1;}
	void ps(int c,int pos0){
		int p=lst,np=lst=++cnt; len[np]=len[p]+1,pos[np]=pos0;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p){fa[np]=1;return;}
		int q=ch[p][c];
		if(len[p]+1==len[q]){fa[np]=q;return;}
		int nq=++cnt; len[nq]=len[p]+1;
		memcpy(ch[nq],ch[q],sizeof(ch[nq]));
		fa[nq]=fa[q],fa[q]=fa[np]=nq;
		for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
	}
	vector<tuple<int,int,int> >fucks[N*2];
	void dfs(int k1){
		fuck_sz[k1]=1,right[k1]=pos[k1];
		for(auto&_:e[k1]){
			int x;
			tie(x,ignore)=_;
			dfs(x);
			fuck_sz[k1]+=fuck_sz[x];
			if(fuck_sz[x]>fuck_sz[fuck_son[k1]]){
				fuck_son[k1]=x;
			}
			if(!right[k1]){
				right[k1]=right[x];
			}
			get<1>(_)=ss[right[x]-len[k1]];
		}
	}
	void bud(){
		rep(i,2,cnt)e[fa[i]].eb(i,0);
		dfs(1);
	}
	int sz[N*2],f[N*2],full,root;
	bool ban[N*2];
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
	void get_ans(int L,int R,int u,int id){
		L=in[L],R=out[R];
		fucks[u].eb(L,R,id);
	}
	void sol(int u,const vector<tuple<int,int,int,int,int,int> >&qs){ // u,v,lca,l,r,id
		ban[u]=1;
		int old=full;
		vector<vector<tuple<int,int,int,int,int,int> > >vec(SZ(e[u])+1);
		for(auto&x:qs){ // special u=1
			int dis=dep[get<0>(x)]+dep[get<1>(x)]-dep[get<2>(x)]*2;
			if(u==1||(len[fa[u]]+1<=dis&&asks(get<0>(x),get<1>(x),get<2>(x),len[fa[u]]+1)==ghs(right[u]-len[fa[u]],right[u]))){
				if(len[fa[u]]+1<=dis&&dis<=len[u]){
					if(get_hash(get<0>(x),get<1>(x))==ghs(right[u]-dis+1,right[u])){
						get_ans(get<3>(x),get<4>(x),u,get<5>(x));
					}
				}else if(asks(get<0>(x),get<1>(x),get<2>(x),len[u])==ghs(right[u]-len[u]+1,right[u])){
					int ch=find_ch(get<0>(x),get<1>(x),get<2>(x),len[u]+1);
					rep(i,0,SZ(e[u])-1)if(get<1>(e[u][i])==ch){
						vec[i].pb(x);
						break;
					}
				}
			}else{
				vec[SZ(e[u])].pb(x);
			}
		}
		rep(i,0,SZ(e[u])){
			int v=i==SZ(e[u])?fa[u]:get<0>(e[u][i]);
			if(v&&!ban[v]){
				full=sz[v]<sz[u]?sz[v]:old-sz[u];
				root=0;
				int vv=v;
				while(vv!=1&&!ban[fa[vv]])vv=fa[vv];
				get_root(vv,0);
				sol(root,vec[i]);
			}
		}
	}
	struct fuck_tree{
		int t[N*2];
		void upd(int fuck,int x){
			for(int i=fuck;i<N*2;i+=i&-i){
				t[i]+=x;
			}
		}
		int qry(int fuck){
			int fucks=0;
			for(int i=fuck;i;i&=i-1){
				fucks+=t[i];
			}
			return fucks;
		}
		int qry(int fuck_l,int fuck_r){
			return qry(fuck_r)-qry(fuck_l-1);
		}
	}t;
	void fuck_up(int u,int x){
		if(pos[u])t.upd(pos[u],x);
		for(auto&_:e[u]){
			int v;
			tie(v,ignore)=_;
			fuck_up(v,x);
		}
	}
	void fuck(int u){
		for(auto&_:e[u]){
			int v;
			tie(v,ignore)=_;
			if(v!=fuck_son[u]){
				fuck(v);
				fuck_up(v,-1);
			}
		}
		if(fuck_son[u]){
			fuck(fuck_son[u]);
		}
		for(auto&_:e[u]){
			int v;
			tie(v,ignore)=_;
			if(v!=fuck_son[u]){
				fuck_up(v,1);
			}
		}
		if(pos[u])t.upd(pos[u],1);
		for(auto&x:fucks[u]){
			ans[get<2>(x)]+=t.qry(get<0>(x),get<1>(x));
		}
	}
	void main(const vector<tuple<int,int,int,int,int,int> >&qs){
		f[0]=INF;
		root=0;
		full=cnt;
		get_root(1,0);
		D("! 1\n");
		sol(root,qs);
		D("! 2\n");
		fuck(1);
	}
}A;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,N*2-1)pw[i]=mu(pw[i-1],B);
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,2,n){
		int u,v,c;
		scanf("%d%d",&u,&v);
		while(!islower(c=getchar()));
		e[u].eb(v,c);
		e[v].eb(u,c);
	}
	dfs1(1,0,0);
	int len=0;
	static char s[N];
	rep(i,1,m){
		scanf("%s",s);
		int ll=strlen(s);
		in[i]=len+1;
		for(int j=0;j<ll;++j){
			A.ps(s[j]-'a',++len);
			ss[len]=s[j];
		}
		A.ps('z'-'a'+1,++len);
		ss[len]='z'+1;
		out[i]=len;
	}
	rep(i,1,len){
		hss[i]=hss[i-1]+(hash_t){ss[i]-'a'+1,1};
	}
	A.bud();
	vector<tuple<int,int,int,int,int,int> >qs;
	rep(_,1,Q){
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		qs.eb(u,v,LCA(u,v),l,r,_);
	}
	A.main(qs);
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}