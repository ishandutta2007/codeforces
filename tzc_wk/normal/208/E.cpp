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
int n,qu,fa[MAXN+5][LOG_N+2];
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int tmp[MAXN+5],*pt=tmp,*f[MAXN+5];
int ans[MAXN+5],dep[MAXN+5],mxdep[MAXN+5],dson[MAXN+5];
vector<pii> qv[MAXN+5];
void dfs0(int x=0){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=mxdep[y]=dep[x]+1;dfs0(y);
		if(mxdep[y]>mxdep[x]) mxdep[x]=mxdep[y],dson[x]=y;
	}
}
void dfs(int x=0){
	if(dson[x]) f[dson[x]]=f[x]+1,dfs(dson[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==dson[x]) continue;
		f[y]=pt;pt+=mxdep[y]-dep[y]+1;dfs(y);
		for(int j=0;j<=mxdep[y]-dep[y];j++) f[x][j+1]+=f[y][j];
	} f[x][0]++;
	for(int i=0;i<qv[x].size();i++){
		int k=qv[x][i].fi,id=qv[x][i].se;
		if(dep[x]+k<=mxdep[x]) ans[id]=f[x][k]-1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&fa[i][0]),adde(fa[i][0],i);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	dfs0();scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		int x,k;scanf("%d%d",&x,&k);
		for(int j=0;j<=LOG_N;j++) if(k>>j&1) x=fa[x][j];
		if(x) qv[x].pb(mp(k,i));
	} f[0]=pt;pt+=mxdep[0]-dep[0]+1;dfs();
	for(int i=1;i<=qu;i++) printf("%d%c",ans[i],(i==qu)?'\n':' ');
	return 0;
}