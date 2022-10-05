//Created time: 2022/3/13 8:43:19
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
const int INF=1e9;
ll _gcd(ll x,ll y){return (!y)?x:_gcd(y,x%y);}
int n,m,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
namespace HLD{
	int fa[MAXN+5],siz[MAXN+5],wson[MAXN+5],dep[MAXN+5];
	int top[MAXN+5];
	void dfs1(int x,int f){
		fa[x]=f;siz[x]=1;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			dep[y]=dep[x]+1;dfs1(y,x);siz[x]+=siz[y];
			if(siz[y]>siz[wson[x]]) wson[x]=y;
		}
	}
	void dfs2(int x,int tp){
		top[x]=tp;if(wson[x]) dfs2(wson[x],tp);
		for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x]&&to[e]!=wson[x])
			dfs2(to[e],to[e]);
	}
	int getlca(int x,int y){
		while(top[x]^top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		return (dep[x]<dep[y])?x:y;
	}
	int getdis(int x,int y){return dep[x]+dep[y]-(dep[getlca(x,y)]<<1);}
}
using namespace HLD;
struct frac{
	ll x,y;
	frac(){x=0;y=1;}
	frac(ll V){x=V;y=1;}
	frac(ll _x,ll _y){
		ll d=_gcd(abs(_x),abs(_y));
		x=_x/d;y=_y/d;if(y<0) y=-y,x=-x;
	}
	friend frac operator +(frac X,frac Y){return frac(1ll*X.x*Y.y+1ll*Y.x*X.y,1ll*X.y*Y.y);}
	friend frac operator -(frac X,frac Y){return frac(1ll*X.x*Y.y-1ll*Y.x*X.y,1ll*X.y*Y.y);}
	friend frac operator *(frac X,frac Y){return frac(1ll*X.x*Y.x,1ll*X.y*Y.y);}
	friend frac operator /(frac X,frac Y){return frac(1ll*X.x*Y.y,1ll*X.y*Y.x);}
	friend bool operator <(frac X,frac Y){return 1ll*X.x*Y.y<1ll*Y.x*X.y;}
	friend bool operator <=(frac X,frac Y){return 1ll*X.x*Y.y<=1ll*Y.x*X.y;}
	friend bool operator >(frac X,frac Y){return 1ll*X.x*Y.y>1ll*Y.x*X.y;}
	friend bool operator >=(frac X,frac Y){return 1ll*X.x*Y.y>=1ll*Y.x*X.y;}
	friend bool operator ==(frac X,frac Y){return 1ll*X.x*Y.y==1ll*Y.x*X.y;}
	void print(){printf("%lld/%lld",x,y);}
	void print(char c){printf("%lld/%lld",x,y);putchar(c);}
};
frac curT;
struct path{
	frac k,b,l,r;
	path(){/*var nothing*/}
	path(frac _k,frac _b,frac _l,frac _r){k=_k;b=_b-_k*_l;l=_l;r=_r;}
	friend bool operator <(path A,path B){
		return mt(A.k*curT+A.b,A.k,A.b,A.l,A.r)<mt(B.k*curT+B.b,B.k,B.b,B.l,B.r);
	}
	void print(){k.print(' ');b.print(' ');l.print(' ');r.print('\n');}
};
vector<path> light[MAXN+5],heavy[MAXN+5];
void dealpath(int u,int v,frac S,frac V){
	frac T=S+frac(getdis(u,v))/V;
	while(top[u]^top[v]){
		if(dep[top[u]]>dep[top[v]]){
			heavy[top[u]].pb(path(frac(0)-V,frac(dep[u]),S,S+(dep[u]-dep[top[u]])/V));
			S=S+(dep[u]-dep[top[u]])/V;
			light[top[u]].pb(path(frac(0)-V,frac(dep[top[u]]),S,S+frac(1)/V));
			S=S+frac(1)/V;u=fa[top[u]];
		} else {
			heavy[top[v]].pb(path(V,frac(dep[top[v]]),T-(dep[v]-dep[top[v]])/V,T));
			T=T-(dep[v]-dep[top[v]])/V;
			light[top[v]].pb(path(V,frac(dep[fa[top[v]]]),T-frac(1)/V,T));
			T=T-frac(1)/V;v=fa[top[v]];
		}
	}
	assert(S+frac(abs(dep[u]-dep[v]))/V==T);
	if(dep[u]<dep[v]) heavy[top[u]].pb(path(V,frac(dep[u]),S,T));
	else heavy[top[u]].pb(path(frac(0)-V,frac(dep[u]),S,T));
}
frac get(path X,path Y){
	if(X.k==Y.k) return (X.b==Y.b)?(max(X.l,Y.l)):frac(INF);
	else{
		frac t=(X.b-Y.b)/(Y.k-X.k);
		return (max(X.l,Y.l)<=t&&t<=min(X.r,Y.r))?t:frac(INF);
	}
}
frac res=frac(INF);
void calc(vector<path> vec){
	if(vec.empty()) return;
//	for(auto p:vec) p.print();
	multiset<path> st;vector<pair<path,int> > eve;
	for(auto p:vec) eve.pb(mp(p,0)),eve.pb(mp(p,1));
	sort(eve.begin(),eve.end(),[&](pair<path,int> A,pair<path,int> B){
		frac T1=(A.se)?A.fi.r:A.fi.l,T2=(B.se)?B.fi.r:B.fi.l;
		return (T1==T2)?(A.se<B.se):(T1<T2);
	});
	for(int i=0;i<eve.size();i++){
		frac tim=(eve[i].se)?eve[i].fi.r:eve[i].fi.l;
		curT=tim;if(curT>=res) break;
		if(!eve[i].se){
			st.insert(eve[i].fi);
			multiset<path>::iterator it=st.lower_bound(eve[i].fi);
			multiset<path>::iterator pre=it,nxt=it;++nxt;
			if(pre!=st.begin()) chkmin(res,get(eve[i].fi,*--pre));
			if(nxt!=st.end()) chkmin(res,get(eve[i].fi,*nxt));
		} else {
			multiset<path>::iterator it=st.lower_bound(eve[i].fi);
			multiset<path>::iterator pre=it,nxt=it;++nxt;
			if(pre!=st.begin()&&nxt!=st.end()) chkmin(res,get(*--pre,*nxt));
			st.erase(st.find(eve[i].fi));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs1(1,0);dfs2(1,1);
//	for(int i=1;i<=n;i++) printf("%d%c",top[i]," \n"[i==n]);
	while(m--){
		int S,V,u,v;scanf("%d%d%d%d",&S,&V,&u,&v);
		dealpath(u,v,frac(S),frac(V));
	}
	for(int i=1;i<=n;i++) calc(heavy[i]),calc(light[i]);
	if(res==frac(INF)) puts("-1");
	else printf("%.10lf\n",1.0*res.x/res.y);
	return 0;
}
/*
10 2
6 9
5 2
9 8
5 8
1 6
3 6
8 10
7 1
7 4
608 7 1 4
608 28 8 7
*/