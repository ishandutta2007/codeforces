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
const int MAXN=6000;
int n,a[MAXN+5],key[MAXN+5],uni[MAXN+5],num=0;
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
struct bitree{
	int t[MAXN+5];
	void add(int x,int v){for(int i=x;i<=num;i+=(i&-i)) chkmax(t[i],v);}
	int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) chkmax(ret,t[i]);return ret;}
	void clear(int x){for(int i=x;i<=num;i+=(i&-i)) t[i]=0;}
} t1,t2;
int wson[MAXN+5],dp1[MAXN+5],dp2[MAXN+5],siz[MAXN+5],ans=0;
void dfs1(int x=1,int f=0){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs1(y,x);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void del(int x,int f){
	t1.clear(a[x]);t2.clear(num-a[x]+1);
	for(int e=hd[x];e;e=nxt[e]) if(to[e]!=f) del(to[e],x);
}
vector<int> seq;
void add(int x,int f){
	seq.pb(x);for(int e=hd[x];e;e=nxt[e]) if(to[e]!=f) add(to[e],x);
}
void dfs2(int x=1,int f=0){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		dfs2(y,x);del(y,x);
	} if(wson[x]) dfs2(wson[x],x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||y==wson[x]) continue;
		seq.clear();add(y,x);
		for(int u:seq){
			chkmax(ans,dp1[u]+t2.query(num-a[u]));
			chkmax(ans,dp2[u]+t1.query(a[u]-1));
			if(a[u]<a[x]) chkmax(ans,dp1[u]+t2.query(num-a[x])+1);
			if(a[u]>a[x]) chkmax(ans,dp2[u]+t1.query(a[x]-1)+1);
		}
		for(int u:seq){
			t1.add(a[u],dp1[u]);t2.add(num-a[u]+1,dp2[u]);
		}
	} dp1[x]=t1.query(a[x]-1)+1;dp2[x]=t2.query(num-a[x])+1;
	t1.add(a[x],dp1[x]);t2.add(num-a[x]+1,dp2[x]);
	chkmax(ans,dp1[x]);chkmax(ans,dp2[x]);
//	printf("%d %d %d\n",x,dp1[x],dp2[x]);
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]),key[i]=a[i];
	sort(key+1,key+n+1);for(int i=1;i<=n;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++) a[i]=lower_bound(uni+1,uni+num+1,a[i])-uni;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs1();dfs2();printf("%d\n",ans);
	return 0;
}