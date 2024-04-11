#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
//#define int long long
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
typedef long long LL;
const int N=400005,M=N*40,INF=0X3F3F3F3F;
int n,Q,p[N],ind;
struct gg{
	int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
	gg(){pp=1;}
	void ae(int k1,int k2,int k3){
		//D("ae %d %d %d\n",k1,k2,k3);
		to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;
	}
}G,H;
void rebud(int k1,int k2){
	int k3=k1;
	for(int i=H.lnk[k1];i;i=H.nxt[i])if(H.to[i]!=k2){
		++ind;
		assert(ind<N);
		G.ae(k3,ind,0);
		G.ae(ind,k3,0);
		G.ae(H.to[i],ind,H.we[i]);
		G.ae(ind,H.to[i],H.we[i]);
		k3=ind;
	}
	for(int i=H.lnk[k1];i;i=H.nxt[i])if(H.to[i]!=k2)rebud(H.to[i],k1);
}
namespace DC{
	int lc[N],rc[N],fa[N],rt,sz[N],all;
	pair<int,int>nrt;
	vector<int>dir[N];
	vector<LL>dis[N];
	void getsz(int k1,int k2){
		sz[k1]=1;
		for(int i=G.lnk[k1];i;i=G.nxt[i]){
			if(G.to[i]!=k2&&G.to[i]!=-1){
				getsz(G.to[i],k1);
				sz[k1]+=sz[G.to[i]];
			}
		}
	}
	void getrt(int k1,int k2){
		for(int i=G.lnk[k1];i;i=G.nxt[i]){
			if(G.to[i]!=k2&&G.to[i]!=-1){
				getrt(G.to[i],k1);
				nrt=min(nrt,make_pair(max(sz[G.to[i]],all-sz[G.to[i]]),i));
			}
		}
	}
	void put(int k1,int k2,int k3,LL k4){
		dir[k1].PB(k3),dis[k1].PB(k4);
		for(int i=G.lnk[k1];i;i=G.nxt[i])if(G.to[i]!=k2&&G.to[i]!=-1){
			put(G.to[i],k1,k3,k4+G.we[i]);
		}
	}
	int bud(int k1){
		getsz(k1,0);
		if(sz[k1]==1)return 0;
		nrt=make_pair(INF,0);
		all=sz[k1];
		getrt(k1,0);
		int id=nrt.Y;
		int a=G.to[id],b=G.to[id^1];
		G.to[id]=G.to[id^1]=-1;
		put(a,0,0,0);
		put(b,0,1,0);
		id/=2;
		lc[id]=bud(a);
		if(lc[id]){
			fa[lc[id]]=id;
		}
		rc[id]=bud(b);
		if(rc[id]){
			fa[rc[id]]=id;
		}
		return id;
	}
	void bud(){
		rt=bud(1);
	}
}
namespace SEG{
	signed rt[N],sz[M],lc[M],rc[M],ind;
	LL sum[M][2];
	void ins(signed*k1,int k2,int u){
		//D("ins %d\n",u);
		//int*tmp=k1;
		rep(i,0,SZ(DC::dir[u])-1){
			*k1=++ind;
			sz[*k1]=sz[k2]+1;
			lc[*k1]=lc[k2];
			rc[*k1]=rc[k2];
			sum[*k1][0]=sum[k2][0];
			sum[*k1][1]=sum[k2][1];
			if(DC::dir[u][i]==0){
				//D("%d",0);
				sum[*k1][0]+=DC::dis[u][i];
				k1=&lc[*k1];
				k2=lc[k2];
			}
			else{
				//D("%d",1);
				sum[*k1][1]+=DC::dis[u][i];
				k1=&rc[*k1];
				k2=rc[k2];
			}
		}
		*k1=++ind;
		sz[*k1]=1;
		//D("\n");
		/*int cur=*tmp;
		rep(i,0,SZ(DC::dir[u])-1){
			assert(sz[cur]==sz[lc[cur]]+sz[rc[cur]]);
			if(DC::dir[u][i]==0)cur=lc[cur];else cur=rc[cur];
		}*/
	}
	void bud(){
		rep(i,1,n){
			ins(&rt[i],rt[i-1],p[i]);
		}
	}
	void swap(int x){
		std::swap(p[x],p[x+1]);
		ins(&rt[x],rt[x-1],p[x]);
		ins(&rt[x+1],rt[x],p[x+1]);
	}
	LL qry(int k1,int k2,int u){
		LL res=0;
		int cur=DC::rt;
		rep(i,0,SZ(DC::dir[u])-1){
			if(DC::dir[u][i]==0){
				//D(">>> %d\n",sz[rc[k1]]-sz[rc[k2]]);
				res+=1LL*(sz[rc[k1]]-sz[rc[k2]])*(G.we[cur*2]+DC::dis[u][i])+sum[k1][1]-sum[k2][1];
				k1=lc[k1],k2=lc[k2],cur=DC::lc[cur];
			}else{
				//D("!!! %d\n",sz[lc[k1]]-sz[lc[k2]]);
				res+=1LL*(sz[lc[k1]]-sz[lc[k2]])*(G.we[cur*2]+DC::dis[u][i])+sum[k1][0]-sum[k2][0];
				k1=rc[k1],k2=rc[k2],cur=DC::rc[cur];
			}
		}
		return res;
	}
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(Q),ind=n;
	rep(i,1,n)rd(p[i]);
	rep(i,2,n){
		int k1,k2,k3;
		rd(k1),rd(k2),rd(k3);
		H.ae(k1,k2,k3),H.ae(k2,k1,k3);
	}
	rebud(1,0);
	DC::bud();
	SEG::bud();
	LL ans=0;
	rep(_,1,Q){
		int o;
		rd(o);
		if(o==1){
			int l,r,v;
			rd(l),rd(r),rd(v);
#ifndef xay5421
			l^=ans,r^=ans,v^=ans;
#endif
			//D("l=%d r=%d v=%d\n",l,r,v);
			ans=SEG::qry(SEG::rt[r],SEG::rt[l-1],v);
			pt(ans,'\n');
			ans=ans&((1<<30)-1);
		}else{
			int x;
			rd(x);
#ifndef xay5421
			x^=ans;
#endif
			assert(x<=n);
			SEG::swap(x);
		}
	}
	return 0;
}