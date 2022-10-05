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
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=100;
const int MAXV=3000;
const int MAXE=1e5;
const int INF=3*3*7*257*65537;
int n,b[MAXN+5],S,T;char s[MAXN+5];
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],cst[MAXE+5],ec=1;
void adde(int u,int v,int f,int c){
//	printf("adde %d %d %d %d\n",u,v,f,c);
	to[++ec]=v;cap[ec]=f;cst[ec]=c;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;cst[ec]=-c;nxt[ec]=hd[v];hd[v]=ec;
}
int dis[MAXV+5],flw[MAXV+5],pre[MAXV+5],lste[MAXV+5];
bool inq[MAXV+5];
bool getdis(int S,int T){
	memset(dis,63,sizeof(dis));memset(flw,0,sizeof(flw));
	dis[S]=0;flw[S]=INF;queue<int> q;q.push(S);inq[S]=1;
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e],w=cst[e];
			if(z&&dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;flw[y]=min(flw[x],z);
				pre[y]=x;lste[y]=e;
				if(!inq[y]) inq[y]=1,q.push(y);
			}
		}
	} return dis[T]<INF;
}
pii mcmf(){
	int mxfl=0,mncst=0;
	while(getdis(S,T)){
		mxfl+=flw[T];mncst+=flw[T]*dis[T];
		for(int i=T;i!=S;i=pre[i]){
			cap[lste[i]]-=flw[T];cap[lste[i]^1]+=flw[T];
		}
	} return mp(mxfl,mncst);
}
int cnt[28];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
	int ncnt=n+2;T=(S=n+1)+1;
	for(int i=0;i<26;i++) if(cnt[i]){
		int id=++ncnt;adde(S,id,cnt[i],0);
		for(int j=1;j<=n>>1;j++){
			++ncnt;adde(id,ncnt,1,0);
			if(s[j]-'a'==i) adde(ncnt,j,1,-b[j]);
			else adde(ncnt,j,1,0);
			if(s[n-j+1]-'a'==i) adde(ncnt,n-j+1,1,-b[n-j+1]);
			else adde(ncnt,n-j+1,1,0);
		}
	}
	for(int j=1;j<=n;j++) adde(j,T,1,0);
	printf("%d\n",-mcmf().se);
	return 0;
}