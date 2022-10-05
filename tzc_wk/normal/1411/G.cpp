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
const int MAXN=1e5;
const int MAXP=1<<17;
const int MOD=998244353;
const int INV2=499122177;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,m,deg[MAXN+5],hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
map<int,int> vis[MAXN+5];int sg[MAXN+5],a[MAXP+5];
void FWTxor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++){
				int X=a[j+k],Y=a[(i>>1)+j+k];
				a[j+k]=1ll*type*(X+Y)%MOD;
				a[(i>>1)+j+k]=1ll*type*(X-Y+MOD)%MOD;
			}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),deg[u]++,adde(v,u);
	queue<int> q;
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		while(vis[x][sg[x]]) ++sg[x];
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];vis[y][sg[x]]=1;
			if(!--deg[y]) q.push(y);
		}
	} int ivn=qpow(n+1,MOD-2);
	for(int i=1;i<=n;i++) a[sg[i]]++;
	for(int i=0;i<n;i++) a[i]=1ll*a[i]*ivn%MOD;
	FWTxor(a,MAXP,1);
	for(int i=0;i<MAXP;i++) a[i]=qpow((1-a[i]+MOD)%MOD,MOD-2);
	FWTxor(a,MAXP,INV2);
	printf("%d\n",(1-1ll*a[0]*ivn%MOD+MOD)%MOD);
	return 0;
}