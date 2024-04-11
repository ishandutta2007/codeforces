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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
int n,m,a[MAXN+5],f[MAXN+5],sm[MAXN+5];bool vis[MAXN+5];
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int calc(int x){
	if(~f[x]) return f[x];f[x]=0;
	for(int e=hd[x];e;e=nxt[e]) calc(to[e]);
	for(int e=hd[x];e;e=nxt[e]) vis[calc(to[e])]=1;
	while(vis[f[x]]) ++f[x];
	for(int e=hd[x];e;e=nxt[e]) vis[calc(to[e])]=0;
	return f[x];
}
int main(){
//	freopen("game.in","r",stdin);freopen("game.out","w",stdout);
//	freopen("game2.in","r",stdin);
	scanf("%d%d",&n,&m);memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v);
	for(int i=1;i<=n;i++) sm[calc(i)]^=a[i];
//	for(int i=1;i<=n;i++) printf("%d%c",calc(i)," \n"[i==n]);
	int ps=-1;
	for(int i=0;i<=n;i++) if(sm[i]) ps=i;
	if(!~ps) puts("LOSE");else{
		puts("WIN");int x=-1;
		for(int i=1;i<=n;i++) if(f[i]==ps&&(a[i]^sm[ps])<a[i]) x=i;
		assert(~x);a[x]^=sm[ps];
		for(int e=hd[x];e;e=nxt[e]){int y=to[e];a[y]^=sm[f[y]];sm[f[y]]=0;}
		for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}