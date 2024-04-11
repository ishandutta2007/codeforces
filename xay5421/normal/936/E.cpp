#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
static char ibuf[1<<20];char *fis=ibuf,*fit=ibuf;
inline char getc(){return fis==fit&&(fit=(fis=ibuf)+fread(ibuf,1,1<<20,stdin),fis==fit)?EOF:*fis++;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005,INF=0X3F3F3F3F,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,bel[N],ind,rk[N];
pair<int,int>p[N];
struct ff{
	int x,l,r;
	vector<int>v;
	vector<int>t1,t2;
	void init(int n){
		t1.assign(n+1,INF);
		t2.assign(n+1,INF);
	}
	void upd1(int k1,int k2){
		for(int i=k1;i<SZ(t1);i+=i&-i)umin(t1[i],k2);
	}
	int qry1(int k1){ // prefix
		//D("qry1 %d\n",k1);
		int k2=INF;
		for(int i=k1;i;i&=i-1)umin(k2,t1[i]);
		return k2;
	}
	void upd2(int k1,int k2){
		for(int i=k1;i;i&=i-1)umin(t2[i],k2);
	}
	int qry2(int k1){ // suffix
		int k2=INF;
		for(int i=k1;i<SZ(t2);i+=i&-i)umin(k2,t2[i]);
		return k2;
	}
	void upd(int k1,int k2){
		upd1(k1,k2-k1);
		upd2(k1,k2+k1);
	}
	int qry(int k1){
		return min(qry1(k1)+k1,qry2(k1)-k1);
	}
}V[N];
struct hsmap{
	static const int P=5000005;
	int pp,lnk[P+5],nxt[N*2],we[N*2];
	pair<int,int>to[N*2];
	int ha(const pair<int,int>&x)const{return (1LL*x.X*20050403+x.Y)%P+1;}
	int count(const pair<int,int>&x)const{
		for(int i=lnk[ha(x)];i;i=nxt[i])if(to[i]==x)return 1;
		return 0;
	}
	int&operator[](const pair<int,int>&x){
		int k1=ha(x);
		for(int i=lnk[k1];i;i=nxt[i])if(to[i]==x)return we[i];
		to[++pp]=x,nxt[pp]=lnk[k1],lnk[k1]=pp;
		return we[pp];
	}
}mp;
struct ufs{
	int fa[N];
	int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
	void init(int n){
		rep(i,1,n)fa[i]=i;
	}
}o;
vector<int>G[N];
void bud(){
	o.init(n);
	rep(i,1,n)mp[p[i]]=i;
	rep(i,1,n){
		if(mp.count({p[i].X,p[i].Y-1})){
			o.fa[o.fd(mp[{p[i].X,p[i].Y-1}])]=o.fd(i);
		}
	}
	rep(i,1,n)if(o.fd(i)==i){
		bel[i]=++ind;
		V[ind].x=p[i].X;
		V[ind].l=V[ind].r=p[i].Y;
	}
	rep(i,1,n){
		bel[i]=bel[o.fd(i)];
		umin(V[bel[i]].l,p[i].Y);
		umax(V[bel[i]].r,p[i].Y);
	}
	rep(i,1,ind)V[i].init(V[i].r-V[i].l+1);
	rep(i,1,n)rk[i]=p[i].Y-V[bel[i]].l+1;
	auto link=[&](int k1,int k2){
		if(rk[k1]==1||rk[k2]==1){
			k1=bel[k1],k2=bel[k2];
			G[k1].PB(k2);
			G[k2].PB(k1);
		}
	};
	rep(i,1,n){
		if(mp.count({p[i].X-1,p[i].Y})){
			link(mp[{p[i].X-1,p[i].Y}],i);
		}
	}
}
struct DC{
	int sz[N],f[N],ban[N],all,rt,tim[N];
	vector<int>anc[N],dis[N];
	DC(){f[0]=INF;}
	void getsz(int k1,int k2){
		//sz[k1]=V[k1].r-V[k1].l+1;
		sz[k1]=1;
		for(auto j:G[k1])if(j!=k2&&!ban[j])getsz(j,k1),sz[k1]+=sz[j];
	}
	void getrt(int k1,int k2){
		f[k1]=0;
		for(auto j:G[k1])if(j!=k2&&!ban[j]){
			getrt(j,k1);
			umax(f[k1],sz[j]);
		}
		umax(f[k1],all-f[k1]);
		if(f[k1]<f[rt])rt=k1;
	}
	int q[N],he,ta;
	void sol(int k1){
		getsz(k1,0);
		all=sz[k1];
		rt=0;
		getrt(k1,0);
		k1=rt;
		//D("sol %d\n",k1);
		he=ta=0;
		rep(i,V[k1].l,V[k1].r){
			int u=mp[{V[k1].x,i}];
			anc[u].PB(u);
			dis[u].PB(0);
			q[++ta]=u;
			tim[u]=k1;
		}
		while(he!=ta){
			int u=q[++he];
			int x=p[u].X,y=p[u].Y;
			rep(i,0,3){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(mp.count({nx,ny})){
					int v=mp[{nx,ny}];
					if(!ban[bel[v]]&&tim[v]!=k1){
						anc[v].PB(anc[u].back());
						dis[v].PB(dis[u].back()+1);
						tim[v]=k1;
						q[++ta]=v;
					}
				}
			}
		}
		ban[k1]=1;
		for(auto j:G[k1])if(!ban[j]){
			sol(j);
		}
	}
	void open(int k1){
		rep(i,0,SZ(anc[k1])-1){
			int id=anc[k1][i];
			V[bel[id]].upd(rk[id],dis[k1][i]);
		}
	}
	int qry(int k1){
		int ans=INF;
		rep(i,0,SZ(anc[k1])-1){
			int id=anc[k1][i];
			ans=min(ans,V[bel[id]].qry(rk[id])+dis[k1][i]);
		}
		return ans>=INF/2?-1:ans;
	}
}dc;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n){
		rd(p[i].X),rd(p[i].Y);
	}
	bud();
	dc.sol(1);
	rd(m);
	rep(i,1,m){
		int o,x,y;
		rd(o),rd(x),rd(y);
		if(o==1){
			if(mp.count({x,y}))dc.open(mp[{x,y}]);
		}else{
			if(mp.count({x,y}))pt(dc.qry(mp[{x,y}]),'\n');
			else puts("-1");
		}
	}
	return 0;
}