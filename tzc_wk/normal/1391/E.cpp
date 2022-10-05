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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int MAXM=1e6;
int n,m,hd[MAXN+5],nxt[MAXM*2+5],to[MAXM*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],dep[MAXN+5],tim=0,fa[MAXN+5];
vector<int> deps[MAXN+5];
int mx=-1,id=0;
void dfs(int x){
	if(dep[x]>mx) mx=dep[x],id=x;
	deps[dep[x]].pb(x);dfn[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]) dep[y]=dep[x]+1,fa[y]=x,dfs(y);
	}
}
void clear(){
	for(int i=1;i<=n;i++) hd[i]=dfn[i]=0;tim=ec=0;
	for(int i=0;i<=n;i++) deps[i].clear();
	mx=-1;id=0;
}
void solve(){
	scanf("%d%d",&n,&m);clear();int lim=n+1>>1;
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1);
	if(mx+1>=lim){
		printf("PATH\n%d\n",mx+1);
		for(;id^1;id=fa[id]) printf("%d ",id);
		printf("1\n");
	} else {
//		printf("%d\n",mx);
		int sum=0;for(int i=0;i<=mx;i++) sum+=(deps[i].size()>>1);
		printf("PAIRING\n%d\n",sum);
		for(int i=0;i<=mx;i++){
			for(int j=0;j<deps[i].size()>>1;j++){
				printf("%d %d\n",deps[i][j<<1],deps[i][j<<1|1]);
			}
		}
	}
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}