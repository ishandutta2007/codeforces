//Created time: 2022/3/19 22:12:10
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
const int MAXN=5e4;
const int MAXP=MAXN<<7;
int n,m,qu,C,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0,col[MAXN+5],foo[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5],siz[MAXN+5],wson[MAXN+5],dep[MAXN+5];
int top[MAXN+5],dfn[MAXN+5],tim=0;
void dfs1(int x){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=dep[x]+1;
		dfs1(y);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;dfn[x]=++tim;if(wson[x]) dfs2(wson[x],tp);
	for(int e=hd[x];e;e=nxt[e]){int y=to[e];if(y!=wson[x]) dfs2(y,y);}
}
struct dat{
	ll c0,c1,c2;
	dat(){c0=c1=c2=0;}
	dat(ll _c0,ll _c1,ll _c2){c0=_c0;c1=_c1;c2=_c2;}
	friend dat operator +(const dat &X,const dat &Y){return dat(X.c0+Y.c0,X.c1+Y.c1,X.c2+Y.c2);}
	friend dat operator *(const dat &X,const int &Y){return dat(X.c0,X.c1+1ll*X.c0*Y,X.c2+2ll*X.c1*Y+1ll*X.c0*Y*Y);}
};
struct node{int ch[2],lz;dat val;} s[MAXP+5];
int rt[MAXN+5],ncnt;
void modify(int &k,int l,int r,int ql,int qr,int v){
	if(!k) k=++ncnt,s[k].val.c0=r-l+1;
	if(ql<=l&&r<=qr) return s[k].val=s[k].val*v,s[k].lz+=v,void();
	int mid=l+r>>1;
	if(qr<=mid) modify(s[k].ch[0],l,mid,ql,qr,v);
	else if(ql>mid) modify(s[k].ch[1],mid+1,r,ql,qr,v);
	else modify(s[k].ch[0],l,mid,ql,mid,v),modify(s[k].ch[1],mid+1,r,mid+1,qr,v);
	s[k].val=s[s[k].ch[0]].val+s[s[k].ch[1]].val;
	s[k].val.c0=r-l+1;s[k].val=s[k].val*s[k].lz;
}
void ins(int x,int c,int coef){
	while(x){
//		printf("modify %d [%d,%d] %d\n",c,dfn[top[x]],dfn[x],coef);
		modify(rt[c],1,n,dfn[top[x]],dfn[x],coef);
		x=fa[top[x]];
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&qu,&C);
	for(int i=1;i<=n;i++) scanf("%d",&col[i]);
	for(int i=2;i<=n;i++) scanf("%d",&fa[i]),adde(fa[i],i);
	for(int i=1;i<=m;i++) scanf("%d",&foo[i]);
	dfs1(1);dfs2(1,1);
//	for(int i=1;i<=n;i++) printf("%d%c",top[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) ins(i,col[i],1);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x,c;scanf("%d%d",&x,&c);
			ins(x,col[x],-1);col[x]=c;ins(x,col[x],1);
		} else {
			int c;scanf("%d",&c);
//			printf("! %d (%lld,%lld,%lld)\n",rt[c],s[rt[c]].val.c2,s[rt[c]].val.c1,s[rt[c]].val.c0);
			ll sum=1ll*C*C*n+1ll*s[rt[c]].val.c2*foo[c]*foo[c]-2ll*s[rt[c]].val.c1*foo[c]*C;
			printf("%.10lf\n",1.0*sum/n);
		}
	}
	return 0;
}