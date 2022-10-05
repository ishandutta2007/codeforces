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
const int MAXP=1048576;
const int MAXPP=33554432;
const int MAXV=32003;
const int MAXE=3e5;
const int INF=0x3f3f3f3f;
int n,k,a[MAXP+5],ecnt=0;bool vis[MAXP+5];
int seq[MAXV+5],len=0;
pair<int,pii> eds[MAXPP+5];
int S,SS,T,hd[MAXV+5],to[MAXE+5],cap[MAXE+5],cst[MAXE+5],nxt[MAXE+5],ec=1;
void adde(int u,int v,int f,int c){
	to[++ec]=v;cap[ec]=f;cst[ec]=c;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;cst[ec]=-c;nxt[ec]=hd[v];hd[v]=ec;
}
int dis[MAXV+5],flw[MAXV+5],pre[MAXV+5],lste[MAXV+5];bool inq[MAXV+5];
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
				if(!inq[y]) q.push(y),inq[y]=1;
			}
		}
	} return dis[T]<INF;
}
pii mcmf(int S,int T){
	int mxfl=0,mncst=0;
	while(getdis(S,T)){
		mxfl+=flw[T];mncst+=flw[T]*dis[T];
		for(int i=T;i^S;i=pre[i]){
			cap[lste[i]]-=flw[T];cap[lste[i]^1]+=flw[T];
		}
	} return mp(mxfl,mncst);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
	priority_queue<pair<int,pii> > q;
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++)
		eds[++ecnt]=mp(a[i]+a[i^(1<<j)],mp(i,i^(1<<j)));
	int lim=min(n<<n,k*(n<<2));vector<pii> ed;
	nth_element(eds+1,eds+lim+1,eds+ecnt+1,greater<pair<int,pii> >());
	for(int i=1;i<=lim;i++){
		int x=eds[i].se.fi,y=eds[i].se.se;
		vis[x]=vis[y]=1;ed.pb(mp(x,y));
	}
	for(int i=0;i<(1<<n);i++) if(vis[i]) seq[++len]=i;
	for(int i=0;i<ed.size();i++){
		int x=ed[i].fi,y=ed[i].se;
//		printf("%d %d\n",x,y);
		if(__builtin_parity(x)) swap(x,y);
		int idx=lower_bound(seq+1,seq+len+1,x)-seq;
		int idy=lower_bound(seq+1,seq+len+1,y)-seq;
		adde(idx,idy+len,1,-a[x]-a[y]);
	} SS=(T=(S=len<<1|1)+1)+1;
	for(int i=1;i<=len;i++){
		if(__builtin_parity(seq[i])) adde(i+len,T,1,0);
		else adde(SS,i,1,0);
	} adde(S,SS,k,0);
	printf("%d\n",-mcmf(S,T).se);
	return 0;
}