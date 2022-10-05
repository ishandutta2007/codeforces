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
const int MAXN=2e5;
int n,m,k,l[MAXN+5],r[MAXN+5],res[MAXN+5];
struct graph{
	int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g,rev;
int deg[MAXN+5];
pair<pii,int> p[MAXN+5];
void calc(graph &G,int op){
	for(int i=1;i<=n;i++) for(int e=G.hd[i];e;e=G.nxt[e]) deg[G.to[e]]++;
	queue<int> q;
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=G.hd[x];e;e=G.nxt[e]){
			int y=G.to[e];
			if(op) chkmax(l[y],l[x]+1);
			else chkmin(r[y],r[x]-1);
			if(!--deg[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++) if(deg[i]) puts("-1"),exit(0);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x) l[i]=r[i]=x;
		else l[i]=1,r[i]=k;
	}
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g.adde(u,v);rev.adde(v,u);
	} calc(g,0);calc(rev,1);
	for(int i=1;i<=n;i++) if(l[i]>r[i]) return puts("-1"),0;
//	for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
	for(int i=1;i<=n;i++) p[i]=mp(mp(l[i],r[i]),i);
	sort(p+1,p+n+1);set<pii> st;
	for(int i=1,j=1;i<=k;i++){
		while(j<=n&&p[j].fi.fi<=i) st.insert(mp(p[j].fi.se,p[j].se)),++j;
		if(st.empty()) return puts("-1"),0;
//		printf("%d finished\n",i);
		if((st.begin()->fi)>i){
			pii p=*st.begin();st.erase(st.find(p));
			res[p.se]=i;
		} else {
			while(!st.empty()){
				pii p=*st.begin();if(p.fi!=i) break;
				st.erase(st.find(p));res[p.se]=i;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}