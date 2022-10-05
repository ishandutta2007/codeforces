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
const int MAXN=5e5;
const int MAXMSK=1<<20;
int n,a[MAXN+5],b[MAXN+5];
vector<int> nei[MAXMSK+5];
bool vis[MAXMSK+5];
void dfs(int x){
	if(vis[x]) return;vis[x]=1;
	for(int i=0;i<nei[x].size();i++) dfs(nei[x][i]);
}
int hd[MAXMSK+5],to[MAXN*2+5],nxt[MAXN*2+5],idu[MAXN*2+5],idv[MAXN*2+5],ec=1;
bool used[MAXN*2+5];
vector<int> ret;
void adde(int u,int v,int x,int y){
	to[++ec]=v;idu[ec]=x;idv[ec]=y;nxt[ec]=hd[u];hd[u]=ec;
}
void cir(int x){
	for(int &e=hd[x];e;e=nxt[e]) if(!used[e>>1]){
		used[e>>1]=1;int u=idu[e],v=idv[e];
		cir(to[e]);ret.pb(v);ret.pb(u);
	}
}
void end(int x){
	int lim=(1<<x)-1;
	for(int i=1;i<=n;i++){
		adde(a[i]&lim,b[i]&lim,i*2-1,i*2);
		adde(b[i]&lim,a[i]&lim,i*2,i*2-1);
	} cir(a[1]&lim);
	printf("%d\n",x);
	for(int u:ret) printf("%d ",u);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=20;i;i--){
		int lim=(1<<i)-1;
		for(int j=0;j<=lim;j++) nei[j].clear(),vis[j]=0;
		for(int j=1;j<=n;j++){
			nei[a[j]&lim].pb(b[j]&lim);
			nei[b[j]&lim].pb(a[j]&lim);
		} bool flg=1,hav=0;
		for(int j=0;j<=lim;j++) if(nei[j].size()&1){flg=0;break;}
		for(int j=0;j<=lim;j++) if(nei[j].size()>=1&&!vis[j]){
			if(hav){flg=0;break;}hav=1;dfs(j);
		}
		if(flg){end(i);return 0;}
	} end(0);
	return 0;
}