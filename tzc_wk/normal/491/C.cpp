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
const int MAXN=2e6;
const int MAXK=52;
const int MAXV=120;
const int MAXE=3e3*2;
const int INF=0x3f3f3f3f;
int n,k,S,T,c[MAXK+5][MAXK+5];char s1[MAXN+5],s2[MAXN+5];
int id(char c){return (c<'a')?(c-'A'+27):(c-'a'+1);}
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cst[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f,int c){
	to[++ec]=v;cap[ec]=f;cst[ec]=c;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;cst[ec]=-c;nxt[ec]=hd[v];hd[v]=ec;
}
bool inq[MAXV+5];
int dis[MAXV+5],flw[MAXV+5],lste[MAXV+5],pre[MAXV+5];
bool getdis(){
	memset(dis,63,sizeof(dis));memset(flw,0,sizeof(flw));
	dis[S]=0;flw[S]=INF;queue<int> q;q.push(S);inq[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e],w=cst[e];
			if(z&&dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;flw[y]=min(flw[x],z);
				pre[y]=x;lste[y]=e;
				if(!inq[y]){q.push(y);inq[y]=1;}
			}
		}
	} return dis[T]<INF;
}
pii mcmf(){
	int mxfl=0,mncst=0;
	while(getdis()){
		mxfl+=flw[T];mncst+=flw[T]*dis[T];
		for(int i=T;i^S;i=pre[i]){
			cap[lste[i]]-=flw[T];cap[lste[i]^1]+=flw[T];
		}
	} return mp(mxfl,mncst);
}
int main(){
	scanf("%d%d%s%s",&n,&k,s1+1,s2+1);T=(S=2*k+1)+1;
	for(int i=1;i<=n;i++) c[id(s1[i])][id(s2[i])]++;
	for(int i=1;i<=k;i++) adde(S,i,1,0),adde(i+k,T,1,0);
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) adde(i,j+k,1,-c[i][j]);
	printf("%d\n",-mcmf().se);
	for(int i=1;i<=k;i++){
		for(int e=hd[i];e;e=nxt[e]){
			if(to[e]^S&&cap[e^1]){
				if(to[e]-k>=27) putchar('A'+to[e]-k-27);
				else putchar(to[e]-k-1+'a');
			}
		}
	} printf("\n");
	return 0;
}