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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
int qpow(int x,int e=MOD-2){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],col[MAXN*2+5],val[MAXN*2+5],ec=0;
void adde(int u,int v,int w,int c){to[++ec]=v;col[ec]=c;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],mx[MAXN+5],cent=0,subsiz[MAXN+5];bool vis[MAXN+5];
void findcent(int x,int f,int tot){
	siz[x]=1;mx[x]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,tot);siz[x]+=siz[y];chkmax(mx[x],siz[y]);
	} chkmax(mx[x],tot-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
int c0[MAXN+5],c1[MAXN+5],mul[MAXN+5],ans=1;
vector<int> pts;
void getpath(int x,int f){
	pts.pb(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e],c=col[e];
		if(y==f||vis[y]) continue;
		mul[y]=1ll*mul[x]*z%MOD;
		c0[y]=c0[x];c1[y]=c1[x];
		(c)?(c1[y]++):(c0[y]++);
		getpath(y,x);
	}
}
struct data{
	int x,y;
	data(int _x=1,int _y=0):x(_x),y(_y){}
};
data merge(data x,data y){return data(1ll*x.x*y.x%MOD,x.y+y.y);}
struct fenwick_tree{
	data t[MAXN*4+5];
	void add(int x,data v){x+=(n<<1);for(int i=x;i<=n<<2;i+=(i&-i)) t[i]=merge(t[i],v);}
	data query(int x){x+=(n<<1);data ret;for(int i=x;i;i&=(i-1)) ret=merge(ret,t[i]);return ret;}
} t1,t2;
void clearmark(int x,int f){
	int iv=qpow(mul[x]);
	t1.add(c1[x]-2*c0[x],data(iv,-1));
	t2.add(2*c1[x]-c0[x],data(iv,-1));
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		clearmark(y,x);
	}
}
void divcent(int x){
//	printf("divcent %d\n",x);
	t1.add(0,data(1,1));t2.add(0,data(1,1));
	mul[x]=1;c1[x]=c0[x]=0;vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e],c=col[e];if(vis[y]) continue;
		mul[y]=z;c0[y]=(!c);c1[y]=(!!c);pts.clear();
		getpath(y,x);subsiz[y]=pts.size();
		for(int p:pts){
//			printf("%d %d %d %d\n",p,c0[p],c1[p],mul[p]);
			data d1=t1.query(c0[p]*2-c1[p]),d2=t2.query(c0[p]-c1[p]*2-1);
//			printf("data %d %d %d %d\n",d1.x,d1.y,d2.x,d2.y);
			int res=1ll*d1.x*qpow(d2.x)%MOD*qpow(mul[p],d1.y-d2.y)%MOD;
			ans=1ll*ans*res%MOD;
		} for(int p:pts){
			t1.add(c1[p]-2*c0[p],data(mul[p],1));
			t2.add(2*c1[p]-c0[p],data(mul[p],1));
		}
	} clearmark(x,0);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;cent=0;
		findcent(y,x,subsiz[y]);divcent(cent);
	}
}
int main(){
	scanf("%d",&n);mx[0]=INF;
	for(int i=1,u,v,w,c;i<n;i++){
		scanf("%d%d%d%d",&u,&v,&w,&c);
		adde(u,v,w,c);adde(v,u,w,c);
	} findcent(1,0,n);divcent(cent);
	printf("%d\n",ans);
	return 0;
}