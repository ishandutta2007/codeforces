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
using namespace fastio;
void chkmin(int &x,int y){(y-x>>31)&&(x=y);}
const int MAXN=1e4;
const int MAXM=2e4;
const int MAXK=10;
const int MAXMSK=1<<10;
const int INF=0x3f3f3f3f;
int n,m,k,qu,sum[MAXMSK+5];
int su[MAXK+5],sv[MAXK+5],sw[MAXK+5];
struct graph{
	short int hd[MAXN+5],to[MAXM+5],nxt[MAXM+5],cap[MAXM+5],ec=1;
	void adde(int u,int v,int w){
		to[++ec]=v;cap[ec]=w;nxt[ec]=hd[u];hd[u]=ec;
		to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
	} short int dep[MAXN+5],now[MAXN+5];
	bool getdep(){
		memset(dep,-1,sizeof(dep));dep[1]=0;
		queue<int> q;q.push(1);now[1]=hd[1];
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int e=hd[x];e;e=nxt[e]){
				int y=to[e],z=cap[e];
				if(z&&!~dep[y]){
					dep[y]=dep[x]+1;
					now[y]=hd[y];q.push(y);
				}
			}
		} return ~dep[n];
	}
	int getflow(int x,int f){
		if(x==n) return f;int ret=0;
		for(short int &e=now[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(dep[y]==dep[x]+1&&z){
				int w=getflow(y,min(f-ret,z));
				ret+=w;cap[e]-=w;cap[e^1]+=w;
				if(ret==f) return ret;
			}
		} return ret;
	}
	int dinic(){
		int ret=0;
		while(getdep()) ret+=getflow(1,INF);
		return ret;
	}
	int ff_bfs(){
		memset(dep,-1,sizeof(dep));dep[1]=0;
		queue<int> q;q.push(1);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int e=hd[x];e;e=nxt[e]){
				int y=to[e],z=cap[e];
				if(z&&!~dep[y]){
					dep[y]=dep[x]+1;now[y]=e;
					q.push(y);if(~dep[n]) break;
				}
			} if(~dep[n]) break;
		} if(!~dep[n]) return 0;
		int mn=25;
		for(int i=n;i^1;i=to[now[i]^1]) chkmin(mn,cap[now[i]]);
		for(int i=n;i^1;i=to[now[i]^1]) cap[now[i]]-=mn,cap[now[i]^1]+=mn;
		return mn;
	}
	int ff(){
		int delta=0,ret=0;
		while(delta=ff_bfs()) ret+=delta;
		return ret;
	}
} g[MAXMSK+5];
int flw[MAXMSK+5];
int main(){
	read(n);read(m);read(k);read(qu);
	for(int i=1;i<=k;i++) read(su[i]),read(sv[i]),read(sw[i]);
	for(int i=k+1,u,v,w;i<=m;i++) read(u),read(v),read(w),g[0].adde(u,v,w);
	flw[0]=g[0].dinic();
	for(int i=1;i<(1<<k);i++){
		int lwb=i&-i;g[i]=g[i^lwb];
		int id=32-__builtin_clz(lwb);
		g[i].adde(su[id],sv[id],25);
		flw[i]=flw[i^lwb]+g[i].ff();
//		printf("%d %d\n",i,flw[i]);
	}
//	if(n==9743&&qu==200000&&sv[1]==209) cout<<clock()<<endl;
	while(qu--){
		for(int i=1;i<=k;i++) read(sw[i]);
		for(int i=1;i<(1<<k);i++){
			int lwb=i&-i,id=32-__builtin_clz(lwb);
			sum[i]=sum[i^lwb]+sw[id];
		} int ans=INF;
		for(int i=0;i<(1<<k);i++){
//			printf("%d %d %d\n",i,sum[i],flw[((1<<k)-1)^i]);
			chkmin(ans,sum[i]+flw[((1<<k)-1)^i]);
		} print(ans);putc('\n');
	} print_final();
	return 0;
}