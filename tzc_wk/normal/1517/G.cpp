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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
const int MAXN=1e3;
const int MAXV=2e3+2;
const int MAXE=2e4*2;
const ll INF=1e18;
int n,x[MAXN+5],y[MAXN+5],w[MAXN+5],tp[MAXN+5],S=2001,T=2002;
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],ec=1;ll cap[MAXE+5];
void adde(int u,int v,ll f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
} int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];ll z=cap[e];
			if(z&&!~dep[y]){
				dep[y]=dep[x]+1;
				q.push(y);now[y]=hd[y];
			}
		}
	} return ~dep[T];
}
ll getflow(int x,ll f){
	if(x==T) return f;ll ret=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e];ll z=cap[e];
		if(dep[y]==dep[x]+1&&z){
			ll w=getflow(y,min(f-ret,z));
			ret+=w;cap[e]-=w;cap[e^1]+=w;
			if(ret==f) return ret;
		}
	} return ret;
}
ll dinic(){
	ll ret=0;
	while(getdep()) ret+=getflow(S,INF);
	return ret;
}
int main(){
	scanf("%d",&n);ll sum=0;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&w[i]);
	for(int i=1;i<=n;i++) tp[i]=((x[i]&1)|((y[i]&1)<<1));
	for(int i=1;i<=n;i++){
		if(tp[i]==1) adde(S,i,INF);
		if(tp[i]==3) adde(i+n,T,INF);
		adde(i,i+n,w[i]);sum+=w[i];
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(i==j) continue;
		if(abs(x[i]-x[j])+abs(y[i]-y[j])!=1) continue;
		if((tp[i]==1&&tp[j]==0)||(tp[i]==0&&tp[j]==2)||(tp[i]==2&&tp[j]==3))
			adde(i+n,j,INF);
	} printf("%lld\n",sum-dinic());
	return 0;
}