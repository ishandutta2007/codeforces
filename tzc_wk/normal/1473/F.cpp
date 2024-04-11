//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
const int MAXN=3000;
const int MAXM=100;
const int MAXV=3002;
const int MAXE=8e4;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5],b[MAXN+5],S,T,pre[MAXM+5],sum=0;
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
} int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(z&&!~dep[y]){
				dep[y]=dep[x]+1;
				q.push(y);now[y]=hd[y];
			}
		}
	} return ~dep[T];
}
int getflow(int x,int f){
	if(x==T) return f;int ret=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(z&&dep[y]==dep[x]+1){
			int w=getflow(y,min(f-ret,z));
			cap[e]-=w;cap[e^1]+=w;ret+=w;
			if(ret==f) return ret;
		}
	} return ret;
}
int dinic(){
	int ret=0;
	while(getdep()) ret+=getflow(S,INF);
	return ret;
}
int main(){
	scanf("%d",&n);T=(S=n+1)+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]>0) sum+=b[i],adde(S,i,b[i]);
		else adde(i,T,-b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=MAXV;j++) if(a[i]%j==0){
			if(pre[j]) adde(i,pre[j],INF);
		} pre[a[i]]=i;
	} printf("%d\n",sum-dinic());
	return 0;
}