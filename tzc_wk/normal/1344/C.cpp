//Created time: 2022/3/27 14:26:51
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=2e5;
const int INF=0x3f3f3f3f;
int n,m,deg[MAXN+5],f[MAXN+5],g[MAXN+5];
char res[MAXN+5];
struct graph{
	int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} G,rev;
int calc_f(int x){
	if(f[x]!=INF) return f[x];f[x]=x;
	for(int e=G.hd[x];e;e=G.nxt[e]) chkmin(f[x],calc_f(G.to[e]));
	return f[x];
}
int calc_g(int x){
	if(g[x]!=INF) return g[x];g[x]=x;
	for(int e=rev.hd[x];e;e=rev.nxt[e]) chkmin(g[x],calc_g(rev.to[e]));
	return g[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);deg[v]++;
		G.adde(u,v);rev.adde(v,u);
	}
	queue<int> q;
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=G.hd[x];e;e=G.nxt[e]) if(!--deg[G.to[e]]) q.push(G.to[e]);
	}
	for(int i=1;i<=n;i++) if(deg[i]) return puts("-1"),0;
	memset(f,63,sizeof(f));memset(g,63,sizeof(g));
	for(int i=1;i<=n;i++) f[i]=calc_f(i),g[i]=calc_g(i);
	for(int i=1;i<=n;i++) res[i]='E';int cc=0;
	for(int i=1;i<=n;i++) if(min(f[i],g[i])==i) res[i]='A',cc++;
	printf("%d\n%s\n",cc,res+1);
	return 0;
}