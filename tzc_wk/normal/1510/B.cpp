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
const int MAXD=10;
const int MAXN=1<<10;
const int MAXV=2100;
const int MAXE=1e5*2;
const int INF=0x3f3f3f3f;
int n,d,S=2049,T=2050,id[MAXN+5],p[MAXN+5];char s[MAXD+3];
int hd[MAXV+5],cap[MAXE+5],nxt[MAXE+5],to[MAXE+5],cst[MAXE+5],ec=1;
void adde(int u,int v,int f,int c){
//	printf("%d %d %d %d\n",u,v,f,c);
	to[++ec]=v;cap[ec]=f;cst[ec]=c;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;cst[ec]=-c;nxt[ec]=hd[v];hd[v]=ec;
}
bool inq[MAXV+5];
int dis[MAXV+5],flw[MAXV+5],pre[MAXV+5],lste[MAXV+5];
bool getdis(int s,int t){
	memset(dis,63,sizeof(dis));memset(flw,0,sizeof(flw));
	dis[s]=0;flw[s]=INF;queue<int> q;q.push(s);inq[s]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e],w=cst[e];
			if(dis[y]>dis[x]+w&&z){
				dis[y]=dis[x]+w;flw[y]=min(flw[x],z);
				pre[y]=x;lste[y]=e;
				if(!inq[y]){inq[y]=1;q.push(y);}
			}
		}
	} return dis[t]<INF;
}
pii mcmf(int s,int t){
	int mxfl=0,mncst=0;
	while(getdis(s,t)){
		mxfl+=flw[t];mncst+=flw[t]*dis[t];
		for(int i=t;i^s;i=pre[i]){
			cap[lste[i]]-=flw[t];cap[lste[i]^1]+=flw[t];
		}
	} return mp(mxfl,mncst);
}
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]) if(to[e]!=S&&cap[e^1]){
		int y=to[e]-n-1,msk=p[y]^p[x];
		for(int j=0;j<d;j++) if(msk>>j&1) printf("%d ",j);
		dfs(y);
	}
}
int main(){
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);int msk=0;
		for(int j=1;j<=d;j++){
			if(s[j]^48) msk|=(1<<j-1);
		} id[msk]=i;p[i]=msk;
	} id[0]=n+1;
	for(int i=0;i<(1<<d);i++){
		for(int j=i;j;j=(j-1)&i){
//			printf("%d %d\n",i,j);
			if(id[i]&&id[j]&&(i!=j)){
				adde(id[j],id[i]+n+1,1,__builtin_popcount(i)-
				__builtin_popcount(j));
			}
		}
		if(id[i]&&i!=0){
			adde(id[0],id[i]+n+1,1,__builtin_popcount(i));
		}
	} adde(S,n+1,INF,1);
	for(int i=1;i<=n;i++){adde(i+n+1,T,1,0);adde(S,i,1,0);}
	int ret=mcmf(S,T).se,fst=1;printf("%d\n",ret-1);
	for(int e=hd[n+1];e;e=nxt[e]){
		int y=to[e];if(y==S||!cap[e^1]) continue;
		if(!fst) printf("R ");int id=to[e]-n-1;fst=0;
		for(int j=0;j<d;j++) if(p[id]>>j&1) printf("%d ",j);
		dfs(id);
	}
	return 0;
}