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
int n,mod,hd[MAXN+5],to[MAXN*2+5],num[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,x,y);int tmp=x;x=y;y=tmp-a/b*y;
}
int inv(int x){
	int a,b;exgcd(x,mod,a,b);
	return (a+mod)%mod;
}
void adde(int u,int v,int w){to[++ec]=v;num[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int pw[MAXN*2+5],ipw[MAXN*2+5];
int a[MAXN+5],b[MAXN+5],dep[MAXN+5];
int siz[MAXN+5],wson[MAXN+5];
void dfs(int x=1,int f=0){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=num[e];if(y==f) continue;
		a[y]=(a[x]+1ll*pw[dep[x]]*z%mod)%mod;
		b[y]=(10ll*b[x]+z)%mod;dep[y]=dep[x]+1;dfs(y,x);
		if(siz[y]>siz[wson[x]]) wson[x]=y;siz[x]+=siz[y];
	}
}
map<int,int> mp_a,mp_b;
ll ans=0;int seq[MAXN+5],seq_num=0;
void add(int x,int f){
	seq[++seq_num]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		add(y,x);
	}
}
void calc(int x=1,int f=0){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		calc(y,x);mp_a.clear();mp_b.clear();
	} int val=(1ll*a[x]*ipw[dep[x]<<1]+b[x])%mod;
	if(wson[x]) calc(wson[x],x);
	ans+=mp_a[a[x]];ans+=mp_b[b[x]];
	mp_a[a[x]]++;mp_b[b[x]]++;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		seq_num=0;add(y,x);
		for(int i=1,u;i<=seq_num;i++){
			u=seq[i];
			ans+=mp_a[1ll*(val-b[u]+mod)*pw[dep[x]<<1]%mod];
			ans+=mp_b[(val-1ll*a[u]*ipw[dep[x]<<1]%mod+mod)%mod];
		}
		for(int i=1;i<=seq_num;i++) mp_a[a[seq[i]]]++,mp_b[b[seq[i]]]++;
	}
}
int main(){
	scanf("%d%d",&n,&mod);
	if(mod==1) return printf("%lld\n",1ll*n*(n-1)),0;
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		++u;++v;adde(u,v,w);adde(v,u,w);
	} pw[0]=1;
	for(int i=1;i<=(n<<1);i++) pw[i]=10ll*pw[i-1]%mod;
	ipw[n<<1]=inv(pw[n<<1]);
	for(int i=(n<<1)-1;~i;i--) ipw[i]=10ll*ipw[i+1]%mod;
	dfs();for(int i=1;i<=n;i++) b[i]=1ll*b[i]*ipw[dep[i]]%mod;
//	for(int i=1;i<=n;i++) printf("%d %d\n",a[i],b[i]);
	calc();printf("%lld\n",ans);
	return 0;
}