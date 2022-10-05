#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
namespace fastio{
	#define FILE_SIZE 1<<25
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc((x%10)+'0');}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
int f[100],id[MAXN+5];
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXN*2+5];vector<int> seq;
int siz[MAXN+5],mx[MAXN+5],cent=0,edg[MAXN+5],fa[MAXN+5];
void dfs(int x,int f,int sz){
	siz[x]=1;mx[x]=0;edg[x]=fa[x]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[e]) continue;
		dfs(y,x,sz);siz[x]+=siz[y];chkmax(mx[x],siz[y]);
	} chkmax(mx[x],sz-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
void rdfs(int x,int f){
	siz[x]=1;seq.pb(x);fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[e]) continue;
		rdfs(y,x);siz[x]+=siz[y];edg[y]=e;
	}
}
bool check(int x,int sz){
	if(sz<=2) return 1;if(!id[sz]) return 0;
	seq.clear();cent=0;dfs(x,0,sz);rdfs(cent,0);
	vector<int> tt=seq;
	for(int i=0;i<tt.size();i++){
		int v=tt[i];
		if(siz[v]==f[id[sz]-2]){
			int tmp=fa[v],ee=edg[v];vis[ee]=vis[ee^1]=1;
//			printf("%d %d %d %d %d\n",x,v,siz[v],ee,tmp);
			if(check(v,f[id[sz]-2])&&check(tmp,f[id[sz]-1])) return 1;
			vis[ee]=vis[ee^1]=0;
		}
	} return 0;
}
int main(){
	f[0]=1;f[1]=1;mx[0]=0x3f3f3f3f;
	for(int i=2;i<=40;i++) f[i]=f[i-1]+f[i-2];
	for(int i=1;i<=40;i++) if(f[i]<=MAXN) id[f[i]]=i;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	} if(check(1,n)) puts("YES");else puts("NO");
	return 0;
}
/*
8
1 2
2 3
2 4
1 5
5 6
6 7
5 8
*/