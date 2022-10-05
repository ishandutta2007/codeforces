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
const int MAXN=1e5;
const int MAXM=2e5;
const int MAXB=60;
const int MOD=1e9+7;
const int INV2=5e8+4;
int n,m,cnt=0,num[MAXB+5];ll a[MAXB+5];
int hd[MAXN+5],to[MAXM*2+5],nxt[MAXM*2+5],ec=0;ll val[MAXM*2+5];
void adde(int u,int v,ll w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
void init(){memset(a,0,sizeof(a));cnt=0;}
void ins(ll x){
	for(int i=MAXB;~i;i--) if(x>>i&1){
		if(!a[i]){++cnt;a[i]=x;return;}
		else x^=a[i];
	}
}
bitset<MAXN+5> vis;
ll dis[MAXN+5];vector<int> v;
void dfs(int x,ll cur){
	dis[x]=cur;vis[x]=1;v.pb(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];ll z=val[e];
		if(!vis[y]) dfs(y,cur^z);
		else ins(dis[x]^dis[y]^z);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;ll w;scanf("%d%d%lld",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);
	}
	int ans=0;
	for(int i=1;i<=n;i++) if(!vis[i]){
		init();memset(num,0,sizeof(num));v.clear();dfs(i,0);
		for(int j=0;j<=MAXB;j++) for(int u:v)
			if(dis[u]>>j&1) num[j]++;
		for(int j=0;j<=MAXB;j++){
			bool flg=0;
			for(int k=0;k<=MAXB;k++) if(a[k]>>j&1) flg=1;
			if(flg) ans=(ans+(1ll<<j)%MOD*((1ll<<cnt-1)%MOD)%MOD*v.size()%MOD*(v.size()-1)%MOD*INV2)%MOD;
			else ans=(ans+(1ll<<j)%MOD*((1ll<<cnt)%MOD)%MOD*num[j]%MOD*(v.size()-num[j]))%MOD;
		}
	} printf("%d\n",ans);
	return 0;
}