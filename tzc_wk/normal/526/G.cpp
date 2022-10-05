#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int LOG_N=17;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
namespace dia{
	int dis1[MAXN+5],dis2[MAXN+5],rt1=1,rt2=1;
	void dfs1(int x,int f){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=val[e];if(y==f) continue;
			dis1[y]=dis1[x]+z;dfs1(y,x);
		}
	}
	void dfs2(int x,int f){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=val[e];if(y==f) continue;
			dis2[y]=dis2[x]+z;dfs2(y,x);
		}
	}
	void find_dia(){
		dfs1(1,0);for(int i=1;i<=n;i++) if(dis1[i]>dis1[rt1]) rt1=i;
		dfs2(rt1,0);for(int i=1;i<=n;i++) if(dis2[i]>dis2[rt2]) rt2=i;
	}
}
struct solver{
	int rt,dep[MAXN+5],mxdep[MAXN+5],dson[MAXN+5],top[MAXN+5];
	int fa[MAXN+5][LOG_N+2],rnk[MAXN+5];
	pii chain[MAXN+5];int chain_n=0,sum[MAXN+5];
	void dfs0(int x,int f){
		fa[x][0]=f;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=val[e];if(y==f) continue;
			dep[y]=mxdep[y]=dep[x]+z;dfs0(y,x);
			if(mxdep[y]>mxdep[x]) mxdep[x]=mxdep[y],dson[x]=y;
		}
	}
	void dfs1(int x,int tp){
		top[x]=tp;if(dson[x]) dfs1(dson[x],tp);
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==fa[x][0]||y==dson[x]) continue;
			dfs1(y,y);
		}
	}
	void init(){
		dfs0(rt,0);dfs1(rt,rt);
		for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
		for(int i=1;i<=n;i++) if(top[i]==i)
			chain[++chain_n]=mp(mxdep[i]-dep[fa[i][0]],i);
		sort(chain+1,chain+chain_n+1);reverse(chain+1,chain+chain_n+1);
//		for(int i=1;i<=chain_n;i++) printf("%d %d\n",chain[i].fi,chain[i].se);
		for(int i=1;i<=chain_n;i++) rnk[chain[i].se]=i;
		for(int i=1;i<=n;i++) rnk[i]=rnk[top[i]];
		for(int i=1;i<=chain_n;i++) sum[i]=sum[i-1]+chain[i].fi;
	}
	int getfst(int x,int rk){
		for(int i=LOG_N;~i;i--) if(rnk[fa[x][i]]>rk) x=fa[x][i];
		return fa[x][0];
	}
	int query(int x,int y){
		y=(y<<1)-1;if(y>chain_n) return sum[chain_n];
		if(rnk[x]<=y) return sum[y];int anc=getfst(x,y);
//		printf("anc=%d\n",anc);
		return max(sum[y-1]+mxdep[x]-dep[getfst(x,y-1)],sum[y]-mxdep[anc]+mxdep[x]);
	}
} t[2];
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1,u,v,w;i<n;i++){scanf("%d%d%d",&u,&v,&w);adde(u,v,w);adde(v,u,w);}
	dia::find_dia();t[0].rt=dia::rt1;t[1].rt=dia::rt2;t[0].init();t[1].init();
	int ans=0;while(qu--){
		int x,y;scanf("%d%d",&x,&y);x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
//		printf("real %d %d\n",x,y);
		printf("%d\n",ans=max(t[0].query(x,y),t[1].query(x,y)));
	}
	return 0;
}