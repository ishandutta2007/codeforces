// author: xay5421
// created: Tue Jun  1 10:11:32 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
typedef long long LL;
const int N=100005,K=20;
int n;
LL ans;
int pp=1,lnk[N],nxt[N*2],to[N*2],eid[N],fa[N][K];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
namespace euler{
	int lg[N*2],dep[N],tin[N],tou[N],ind,f[N*2][K],nd[N][2];
	int _min(int k1,int k2){return dep[k1]<dep[k2]?k1:k2;}
	void dfs1(int k1,int k2){
		dep[k1]=dep[k2]+1,tin[k1]=++ind,f[ind][0]=k1,fa[k1][0]=k2;
		rep(i,1,K-1)fa[k1][i]=fa[fa[k1][i-1]][i-1];
		for(int i=lnk[k1];i;i=nxt[i])if(to[i]!=k2){
			eid[to[i]]=i/2;
			nd[i/2][0]=k1,nd[i/2][1]=to[i];
			dfs1(to[i],k1);
			f[++ind][0]=k1;
		}
		tou[k1]=ind;
	}
	void init(){
		rep(i,2,N*2-1)lg[i]=lg[i>>1]+1;
		dfs1(1,0);
		rep(j,1,K-1)rep(i,1,ind-(1<<j)+1)f[i][j]=_min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	int LCA(int k1,int k2){
		int l=tin[k1],r=tin[k2];
		if(l>r)swap(l,r);
		int x=lg[r-l+1];
		return _min(f[l][x],f[r-(1<<x)+1][x]);
	}
	int DIS(int k1,int k2){
		return dep[k1]+dep[k2]-dep[LCA(k1,k2)]*2;
	}
	int _DIS(int k1,int k2){
		if(k1==k2)return 0;
		//return DIS(k1,k2);
		if(k1<=n&&k2<=n){
			return DIS(k1,k2)*2;
		}else if(k1>n&&k2>n){
			int res=0;
			rep(i,0,1)rep(j,0,1)res+=DIS(nd[k1-n][i],nd[k2-n][j]);
			return res>>1;
		}else{
			if(k1<=n)swap(k1,k2);
			int res=0;
			rep(i,0,1)res+=DIS(nd[k1-n][i],k2);
			return res;
		}
	}
	int getmid(int u,int v){
		int len=DIS(u,v);
		if(dep[u]<dep[v])swap(u,v);
		if(~len&1){
			len>>=1;
			per(i,K-1,0)if(len>>i&1)u=fa[u][i];
			return u;
		}else{
			len>>=1;
			per(i,K-1,0)if(len>>i&1)u=fa[u][i];
			return n+eid[u];
		}
	}
}
using euler::LCA;
using euler::DIS;
using euler::_DIS;
using euler::getmid;
namespace DC{
	const int N=::N*2;
	int n,pp,lnk[N],nxt[N*2],to[N*2];
	void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
	bool ban[N];
	int rt,full,f[N],sz[N],fa[N];
	void getrt(int k1,int k2){
		sz[k1]=1,f[k1]=0;
		for(int i=lnk[k1];i;i=nxt[i])if(!ban[to[i]]&&to[i]!=k2){
			getrt(to[i],k1);
			sz[k1]+=sz[to[i]];
			umax(f[k1],sz[to[i]]);
		}
		umax(f[k1],full-sz[k1]);
		if(f[k1]<f[rt])rt=k1;
	}
	void sol(int cur){
		ban[cur]=1;
		int old=full;
		for(int i=lnk[cur];i;i=nxt[i])if(!ban[to[i]]){
			full=sz[to[i]]<sz[cur]?sz[to[i]]:old-sz[cur];
			rt=0;
			getrt(to[i],cur);
			fa[rt]=cur;
			sol(rt);
		}
	}
	void init(){
		n=::n*2-1;
		f[0]=1e9;
		full=n;
		rt=0;
		getrt(1,0);
		sol(rt);
	}
	LL w1[N],w2[N];
	int cnt[N];
	void ps(int k1,int k2){
		//D("ps %d %d\n",k1,k2);
		for(int i=k1;i;i=fa[i]){
			cnt[i]+=k2;
			w1[i]+=k2*_DIS(i,k1);
			if(fa[i])w2[i]+=k2*_DIS(fa[i],k1);
		}
	}
	LL qry(int k1){
		LL res=w1[k1];
		for(int i=k1;i;i=fa[i]){
			if(fa[i]){
				res+=w1[fa[i]]-w2[i]+1LL*_DIS(fa[i],k1)*(cnt[fa[i]]-cnt[i]);
			}
		}
		//D("qry(%d)=%lld\n",k1,res);
		return res;
	}
}
struct node{
	int u,v,w;
	node(){}
	node(int _u):u(_u),v(_u),w(0){}
	node(int _u,int _v):u(_u),v(_v),w(DIS(u,v)){}
	node(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
	bool operator<(const node&k)const{return w<k.w;}
}d[N];
node mer(const node&k1,const node&k2){
	return max({k1,k2,node(k1.u,k2.u),node(k1.u,k2.v),node(k1.v,k2.u),node(k1.v,k2.v)});
}
node mer(const node&k1,int k2){
	return max({k1,node(k1.u,k2),node(k1.v,k2)});
}
struct atom{
	int pos,u;
	bool operator<(const atom&k)const{
		return pos<k.pos;
	}
}st[N*2];
int top;
LL ss[N];
void sol(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	d[mid]=node(mid),ss[mid]=0;
	per(i,mid-1,l)d[i]=mer(d[i+1],i);
	rep(i,mid+1,r)d[i]=mer(d[i-1],i),ss[i]=ss[i-1]+d[i].w;
	int p1=mid,p2=mid;
	top=0;
	LL cur=0,now=0;
	per(i,mid,l){
		while(p1<r&&mer(d[i],d[p1+1]).w==d[i].w)++p1;
		while(p2<=r&&mer(d[i],d[p2]).w>d[p2].w)++p2;
		p2=max(p2,p1+1);
		cur+=1LL*d[i].w*(p1-mid+1)+ss[r]-ss[p2-1];
		if(p1+1<=p2-1){
			now+=1LL*d[i].w*(p2-p1-1)+ss[p2-1]-ss[p1];
			int u=getmid(d[i].u,d[i].v);
			st[++top]=(atom){p1,-u};
			st[++top]=(atom){p2-1,u};
		}
	}
	sort(st+1,st+1+top);
	int j=1;
	rep(i,mid,r){
		DC::ps(getmid(d[i].u,d[i].v),1);
		while(j<=top&&st[j].pos==i){
			if(st[j].u<0){
				now-=DC::qry(-st[j].u);
			}else{
				now+=DC::qry(st[j].u);
			}
			++j;
		}
	}
	rep(i,mid,r)DC::ps(getmid(d[i].u,d[i].v),-1);
	assert(~now&1),now>>=1;
	ans+=cur+now;
	//D("[%d,%d] mid=%d ans=%lld\n",l,r,mid,ans);
	sol(l,mid-1),sol(mid+1,r);
}
signed main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		ae(k1,k2),ae(k2,k1);
		DC::ae(k1,i+n),DC::ae(i+n,k1);
		DC::ae(k2,i+n),DC::ae(i+n,k2);
	}
	euler::init();
	DC::init();
	sol(1,n);
	printf("%lld\n",ans);
	return 0;
}