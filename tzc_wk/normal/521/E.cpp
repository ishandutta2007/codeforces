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
#define mt make_tuple
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
const int MAXN=2e5;
int n,m,U[MAXN+5],V[MAXN+5];
struct graph{
	int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g,ng,t;
int dfn[MAXN+5],low[MAXN+5],tim=0;
int stk[MAXN+5],tp=0,bel[MAXN+5],cmp=0,in_stk[MAXN+5];
void tarjan(int x){
//	printf("tarjan %d\n",x);
	dfn[x]=low[x]=++tim;
	for(int e=g.hd[x];e;e=g.nxt[e]){
		int y=g.to[e];
		if(!dfn[y]){
			stk[++tp]=e>>1;in_stk[e>>1]=1;
			tarjan(y);chkmin(low[x],low[y]);
			if(low[y]>=dfn[x]){
//				printf("find an edcc %d %d\n",x,y);
				cmp++;int o;do{
					o=stk[tp--];bel[o]=cmp;
					in_stk[o]=0;
				} while(o^(e>>1));
			}
		} else {
			chkmin(low[x],dfn[y]);
			if(dfn[y]<dfn[x]&&!in_stk[e>>1]){
				stk[++tp]=e>>1;in_stk[e>>1]=1;
			}
		}
	}
}
vector<int> bp[MAXN+5];
int in[MAXN+5],fa[MAXN+5],dep[MAXN+5],deg[MAXN+5];
bool vis[MAXN+5],ont[MAXN+5];
void dfs(int x){
	vis[x]=1;
	for(int e=ng.hd[x];e;e=ng.nxt[e]){
		int y=ng.to[e];
		if(!vis[y]){
			ont[e>>1]=1;t.adde(x,y);
			fa[y]=x;deg[x]++;deg[y]++;dep[y]=dep[x]+1;dfs(y);
		}
	}
}
void prt(vector<int> res1,vector<int> res2,vector<int> res3){
	puts("YES");
	printf("%d",res1.size());for(int x:res1) printf(" %d",x);printf("\n");
	printf("%d",res2.size());for(int x:res2) printf(" %d",x);printf("\n");
	printf("%d",res3.size());for(int x:res3) printf(" %d",x);printf("\n");
	exit(0);
}
void work(int id){
	for(int e:bp[id]) ng.adde(U[e],V[e]),ng.adde(V[e],U[e]);
	dfs(U[bp[id][0]]);int rt=U[bp[id][0]],cnt=0;
	for(int e=ng.hd[rt];e;e=ng.nxt[e]) cnt+=(!ont[e>>1]);
	assert(cnt>=1);
	if(cnt>=2){
		int x=0,y=0;vector<int> p1,p2,p3;p1.pb(rt),p2.pb(rt);
		for(int e=ng.hd[rt];e;e=ng.nxt[e]) if(!ont[e>>1]){
			if(!x) x=ng.to[e];else if(!y) y=ng.to[e];
		} if(dep[x]<dep[y]) swap(x,y);
		while(dep[x]>dep[y]) p1.pb(x),x=fa[x];
		while(x^y) p1.pb(x),p2.pb(y),x=fa[x],y=fa[y];
		p1.pb(x);p2.pb(x);
		while(x^rt) p3.pb(x),x=fa[x];p3.pb(rt);
		reverse(p3.begin(),p3.end());prt(p1,p2,p3);
	} else {
		int p=0,pe=0;
		for(int e=ng.hd[rt];e;e=ng.nxt[e]) if(!ont[e>>1])
			p=ng.to[e],pe=e>>1;
		if(deg[p]!=1){
			int q=p;while(deg[q]!=1){
				for(int e=t.hd[q];e;e=t.nxt[e])
					if(t.to[e]!=fa[q]){q=t.to[e];break;}
			} int r=0;for(int e=ng.hd[q];e;e=ng.nxt[e])
				if(!r||dep[r]>dep[ng.to[e]]) r=ng.to[e];
			vector<int> p1,p2,p3;int cp=p,cq=q;
			while(cp^r) p1.pb(cp),cp=fa[cp];p1.pb(cp);
			while(cp^rt) p2.pb(cp),cp=fa[cp];p2.pb(rt);
			reverse(p2.begin(),p2.end());p2.insert(p2.begin(),p);
			while(cq^p) p3.pb(cq),cq=fa[cq];p3.pb(cq);
			reverse(p3.begin(),p3.end());p3.pb(r);
			prt(p1,p2,p3);
		} else {
			int cp=p;static bool on_ch[MAXN+5]={0};
			while(cp^rt) on_ch[cp]=1,cp=fa[cp];on_ch[rt]=1;
			int u=0,v=0;vector<int> p1,p2,p3;
			for(int e=1;e<=(ng.ec>>1);e++) if(!ont[e]&&e!=pe){
				int x=ng.to[e<<1],y=ng.to[e<<1|1];
				if(on_ch[x]||on_ch[y]){u=x;v=y;break;}
			} if(dep[u]<dep[v]) swap(u,v);
			while(!on_ch[u]) p1.pb(u),u=fa[u];p1.pb(u);
			reverse(p1.begin(),p1.end());p1.pb(v);
			int cu=u,cv=v;while(cu^v) p2.pb(cu),cu=fa[cu];p2.pb(v);
			cu=p;while(cv^rt) p3.pb(cv),cv=fa[cv];p3.pb(rt);
			while(cu^u) p3.pb(cu),cu=fa[cu];p3.pb(cu);
			reverse(p3.begin(),p3.end());prt(p1,p2,p3);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&U[i],&V[i]);
		g.adde(U[i],V[i]);g.adde(V[i],U[i]);
	} for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=m;i++) bp[bel[i]].pb(i);
//	for(int i=1;i<=m;i++) printf("%d\n",bel[i]);
	for(int id=1;id<=cmp;id++){
		int cc=0;
		for(int e:bp[id]){
			if(!in[U[e]]) in[U[e]]=1,cc++;
			if(!in[V[e]]) in[V[e]]=1,cc++;
		} if(cc<bp[id].size()){
			work(id);
		} for(int e:bp[id]) in[U[e]]=in[V[e]]=0;
	} puts("NO");
	return 0;
}