//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int LOG_N=18;
int n,m;
struct graph{
	int hd[MAXN*2+5],to[MAXN*4+5],nxt[MAXN*4+5],ec=1;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g,gt,T;
namespace spanning{
	int bel[MAXN+5],cmp=0,fa[MAXN+5][LOG_N+2],dep[MAXN+5];
	void dfs(int x){
		bel[x]=cmp;
		for(int e=g.hd[x];e;e=g.nxt[e]){
			int y=g.to[e];if(bel[y]) continue;
			dep[y]=dep[x]+1;fa[y][0]=x;
			dfs(y);gt.adde(x,y);
		}
	}
	int getlca(int x,int y){
		if(dep[x]<dep[y]) x^=y^=x^=y;
		for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
		if(x==y) return x;
		for(int i=LOG_N;~i;i--) if(fa[x][i]^fa[y][i]) x=fa[x][i],y=fa[y][i];
		return fa[x][0];
	}
	int getdis(int x,int y){return dep[x]+dep[y]-(dep[getlca(x,y)]<<1);}
	void prework(){
		for(int i=1;i<=n;i++) if(!bel[i]) ++cmp,dfs(i);
		for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	}
}
namespace edcc{
	int dfn[MAXN+5],low[MAXN+5],tim=0,stk[MAXN+5],tp=0;
	int e_stk[MAXN+5],e_top,ncnt,bel[MAXN+5],in[MAXN+5];
	void tarjan(int x){
		dfn[x]=low[x]=++tim;stk[++tp]=x;
		for(int e=g.hd[x];e;e=g.nxt[e]){
			int y=g.to[e];if(!dfn[y]){
				e_stk[++e_top]=e>>1;in[e>>1]=1;
				tarjan(y);chkmin(low[x],low[y]);
				if(low[y]>=dfn[x]){
					int o;++ncnt;do{o=stk[tp--];
						T.adde(ncnt,o);T.adde(o,ncnt);
//						printf("%d ",o);
					} while(o^y);
					T.adde(ncnt,x);T.adde(x,ncnt);
//					printf("%d\n",x);
					do{
						o=e_stk[e_top--];
//						printf("ed %d\n",o);
						bel[o]=ncnt;in[o]=0;
					} while(o^(e>>1));
				}
			} else{
				chkmin(low[x],dfn[y]);
				if(dfn[y]<dfn[x]&&!in[e>>1]) e_stk[++e_top]=e>>1;
			}
		}
	}
	void getecc(){
		ncnt=n;
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
//		for(int i=1;i<=m;i++) printf("%d\n",bel[i]);
	}
}
bool is[MAXN*2+5];
int col[MAXN+5];
void dye(int x,int c){
	if(~col[x]) return;col[x]=c;
	for(int e=g.hd[x];e;e=g.nxt[e]){
		int y=g.to[e];
		if(!~col[y]) dye(y,1-c);
		else if(col[x]==col[y]) is[edcc::bel[e>>1]]=1;
	}
}
namespace tree{
	int fa[MAXN*2+5][LOG_N+2],has[MAXN*2+5][LOG_N+2],dep[MAXN*2+5];
	bool vis[MAXN*2+5];
	void dfs(int x,int f){
//		printf("%d %d\n",x,f);
		fa[x][0]=f;vis[x]=1;has[x][0]=is[x];
		for(int e=T.hd[x];e;e=T.nxt[e]){
			int y=T.to[e];if(y==f) continue;
			dep[y]=dep[x]+1;dfs(y,x);
		}
	}
	void prework(){
		for(int i=1;i<=edcc::ncnt;i++) if(!vis[i]) dfs(i,0);
		for(int i=1;i<=LOG_N;i++) for(int j=1;j<=edcc::ncnt;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			has[j][i]=has[j][i-1]|has[fa[j][i-1]][i-1];
		}
	}
	int jumpath(int x,int y){
//		printf("%d %d\n",x,y);
		int res=0;
		if(dep[x]<dep[y]) x^=y^=x^=y;
		for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y])
			res|=has[x][i],x=fa[x][i];
//		printf("%d %d\n",x,y);
		if(x==y) return res|has[x][0];
		for(int i=LOG_N;~i;i--) if(fa[x][i]^fa[y][i]){
			res|=has[x][i];x=fa[x][i];
			res|=has[y][i];y=fa[y][i];
		} return res|has[x][1]|has[y][1];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g.adde(u,v);g.adde(v,u);
	} spanning::prework();edcc::getecc();
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++) if(!~col[i]) dye(i,0);
	tree::prework();int qu;scanf("%d",&qu);
	while(qu--){
		int u,v;scanf("%d%d",&u,&v);
		if(spanning::bel[u]!=spanning::bel[v]) puts("No");
		else{
			int d=spanning::getdis(u,v);
			if(d&1) puts("Yes");
			else{
				if(tree::jumpath(u,v)) puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}
/*
20 20
15 13
8 20
1 12
1 16
18 16
12 19
16 12
11 16
9 20
8 9
3 7
12 17
8 2
18 19
5 20
3 16
17 2
9 11
3 18
20 18
1
5 7
*/