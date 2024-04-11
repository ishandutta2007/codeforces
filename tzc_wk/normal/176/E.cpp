//Created time: 2022/3/12 20:35:42
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
const int MAXN=1e5;
const int LOG_N=18;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5][LOG_N+2];ll dis[MAXN+5];
int dfn[MAXN+5],rid[MAXN+5],tim,dep[MAXN+5];
void dfs0(int x,int f){
	rid[dfn[x]=++tim]=x;fa[x][0]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		dep[y]=dep[x]+1;dis[y]=dis[x]+z;dfs0(y,x);
	}
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
ll getdis(int x,int y){return dis[x]+dis[y]-(dis[getlca(x,y)]<<1);}
set<int> st;ll sum=0;
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),adde(u,v,w),adde(v,u,w);
	dfs0(1,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&qu);st.insert(0);st.insert(n+1);
	while(qu--){
		static char opt[4];scanf("%s",opt+1);
		if(opt[1]=='+'){
			int x;scanf("%d",&x);
			int pv=*--st.lower_bound(dfn[x]);
			int nt=*st.upper_bound(dfn[x]);
			st.insert(dfn[x]);
			if(pv) sum+=getdis(x,rid[pv]);
			if(nt!=n+1) sum+=getdis(x,rid[nt]);
			if(pv&&nt!=n+1) sum-=getdis(rid[pv],rid[nt]);
		} else if(opt[1]=='-'){
			int x;scanf("%d",&x);
			int pv=*--st.lower_bound(dfn[x]);
			int nt=*st.upper_bound(dfn[x]);
			st.erase(dfn[x]);
			if(pv) sum-=getdis(x,rid[pv]);
			if(nt!=n+1) sum-=getdis(x,rid[nt]);
			if(pv&&nt!=n+1) sum+=getdis(rid[pv],rid[nt]);
		} else {
			printf("%lld\n",(st.size()==2)?0:((sum+getdis(rid[*++st.begin()],rid[*++st.rbegin()]))/2));
		}
	}
	return 0;
}