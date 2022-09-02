#include<cstdio>
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=200005;
typedef long long ll;const ll INF=0x3f3f3f3f3f3f3f3fll;
template<typename T>inline void rd(T&x){int f=0,c;while(c=getchar(),c<48||57<c)f^=!(c^45);x=(c&15);while(c=getchar(),47<c&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
int n,m,rt,maxw,ful,ind,cnt,nowe,sz[N],fa[N],ls[N],rs[N],eu[N],ev[N],val[N];
struct da{int u,v,dis;bool operator<(const da&b)const{return dis<b.dis;}}ans[N];
struct ed{ed*nxt;int to,id;};
struct gr{ed pool[N<<1],*p=pool,*lnk[N];void ae(int u,int v,int id){*++p=(ed){lnk[u],v,id},lnk[u]=p;debug("E:%lld %lld %lld %lld\n",u,v,id,val[id]);}}G0,G,H;
void reb(int u,int fa){
	int lst=u;
	for(ed*i=G0.lnk[u];i;i=i->nxt)if(i->to!=fa){
		G.ae(lst,++ind,++nowe),G.ae(ind,lst,nowe);
		G.ae(ind,i->to,i->id),G.ae(i->to,ind,i->id);
		lst=ind;
	}
	for(ed*i=G0.lnk[u];i;i=i->nxt)if(i->to!=fa)reb(i->to,u); 
}
namespace SP{
	int ind,fa[N],sz[N],dep[N],son[N],tin[N],bel[N],t[N],id[N],iid[N];
	void add(int i,int x){
//		debug("add:%lld %lld\n",i,x);
		for(;i<=::ind;i+=i&-i)t[i]+=x;//
	}
	int qry(int i){
		int res=0;
		for(;i;i&=i-1)res+=t[i];
		return res;
	}
	int qry(int l,int r){return qry(r)-qry(l-1);}
	void pre(int u){
		sz[u]=1;
		for(ed*i=G.lnk[u];i;i=i->nxt)if(i->to!=fa[u]){
			fa[i->to]=u,dep[i->to]=dep[u]+1,id[i->to]=i->id,iid[i->id]=i->to;
			pre(i->to);
			sz[u]+=sz[i->to];
			if(sz[i->to]>sz[son[u]])son[u]=i->to;
		}
	}
	void dfs(int u){
		tin[u]=++ind;
		add(tin[u],val[id[u]]);
		if(son[u])bel[son[u]]=bel[u],dfs(son[u]);
		for(ed*i=G.lnk[u];i;i=i->nxt)if(i->to!=fa[u]&&i->to!=son[u]){
			bel[i->to]=i->to;
			dfs(i->to);
		}
	}
	void change(int i,int a,int b){
		add(tin[iid[i]],b-a);
	}
	int query(int u,int v){
		int res=0;
		while(bel[u]!=bel[v]){
			if(dep[bel[u]]<dep[bel[v]])u^=v^=u^=v;
			res+=qry(tin[bel[u]],tin[u]);
			u=fa[bel[u]];
		}
		if(dep[u]<dep[v])u^=v^=u^=v;
		if(u!=v)res+=qry(tin[v]+1,tin[u]);
		return res;
	}
	void init(){
		dep[1]=1,pre(1);
		bel[1]=1,dfs(1);
	}
}
int tmp1[5],tmp2[5];
void upd(int u){
	if(u==7){
		debug("2333");
	}
	*tmp1=*tmp2=0;ans[u].dis=-0x3f3f3f3f;
	if(ls[u]){
		tmp1[++*tmp1]=ans[ls[u]].u;
		tmp1[++*tmp1]=ans[ls[u]].v;
		if(ans[u]<ans[ls[u]])ans[u]=ans[ls[u]];
	}else{
		tmp1[++*tmp1]=eu[u];
	}
	if(rs[u]){
		tmp2[++*tmp2]=ans[rs[u]].u;
		tmp2[++*tmp2]=ans[rs[u]].v;
		if(ans[u]<ans[rs[u]])ans[u]=ans[rs[u]];
	}else{
		tmp2[++*tmp2]=ev[u];
	}
	rep(i,1,*tmp1)rep(j,1,*tmp2){
		da t=(da){tmp1[i],tmp2[j],SP::query(tmp1[i],tmp2[j])};
		if(ans[u]<t)
			ans[u]=t;
	}
}
void getrt(int u,int fa,int&uu,int&vv,int&dd){
	sz[u]=1;
	for(ed*i=G.lnk[u];i;i=i->nxt)if(i->to!=fa&&i->to!=-1){
		getrt(i->to,u,uu,vv,dd),sz[u]+=sz[i->to];
		if(max(sz[i->to],ful-sz[i->to])<max(sz[vv],ful-sz[vv]))uu=u,vv=i->to,dd=i->id;
	}
}
int bud(int u,int d,int full){
	if(full==1)return 0;
	int uu=0,vv=0,dd=0;
	ful=full,getrt(u,0,uu,vv,dd);
	for(ed*i=G.lnk[uu];i;i=i->nxt)if(i->to==vv){i->to=-1;break;}
	for(ed*i=G.lnk[vv];i;i=i->nxt)if(i->to==uu){i->to=-1;break;}
	eu[dd]=uu,ev[dd]=vv;
	ls[dd]=bud(uu,d+1,full-sz[vv]);
	rs[dd]=bud(vv,d+1,sz[vv]);
	fa[ls[dd]]=fa[rs[dd]]=dd;
	upd(dd);
	return dd;
}
void mdf(int u){
	while(u){
		upd(u);
		u=fa[u];
	}
}
signed main(){
	rd(n),rd(m),rd(maxw),ind=n;nowe=n-1;
	rep(i,1,n-1){
		int u,v;
		rd(u),rd(v),rd(val[i]);G0.ae(u,v,i),G0.ae(v,u,i);
	}
	debug("233\n");
	reb(1,0);
	SP::init();
	rt=bud(1,0,ind);
	int lst=0;
	while(m--){
		int a,b;rd(a),rd(b);
		a=(a+lst)%(n-1)+1,b=(b+lst)%maxw;
		SP::change(a,val[a],b);
		val[a]=b;
		mdf(a);
		pt(lst=ans[rt].dis,'\n');
	}
	return 0;
}