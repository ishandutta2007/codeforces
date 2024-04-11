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
const int MAXN=50;
const int MAXV=50*201+100;//remember to calculate ...
const int MAXE=5e4*2;
const int DELTA=1e6;
const ll INF=1e14;
int n,m,a[MAXN+5],b[MAXN+5],c[MAXN+5],l[MAXN+5],r[MAXN+5];
int id(int x,int y){return (x-1)*201+y+101;}
int S,T,hd[MAXV+5],nxt[MAXE+5],to[MAXE+5],ec=1;ll cap[MAXE+5];
void adde(int u,int v,ll f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
}
int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];ll z=cap[e];
			if(z&&!~dep[y]){
				dep[y]=dep[x]+1;
				now[y]=hd[y];q.push(y);
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
			cap[e]-=w;cap[e^1]+=w;ret+=w;
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
	scanf("%d%d",&n,&m);T=(S=201*n+1)+1;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		for(int j=l[u];j<=r[u];j++){
			if(l[v]<=j-w&&j-w<=r[v]) adde(id(u,j),id(v,j-w),INF);
			else if(j-w>r[v]) adde(id(u,j),T,INF);
		}
		for(int j=l[v];j<=r[v];j++){
			if(j+w<l[u]) adde(S,id(v,j),INF);
		}
	}
	for(int i=1;i<=n;i++){
		adde(S,id(i,l[i]),DELTA-l[i]*l[i]*a[i]-l[i]*b[i]-c[i]);
		for(int j=l[i]+1;j<=r[i];j++) adde(id(i,j-1),id(i,j),DELTA-j*j*a[i]-j*b[i]-c[i]);
		adde(id(i,r[i]),T,INF);
	} printf("%lld\n",n*DELTA-dinic());
	return 0;
}