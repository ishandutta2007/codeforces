//Created time: 2022/3/19 15:22:48
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
const int INF=0x3f3f3f3f;
int n,L,R,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int VAL;tuple<int,int,int> MX;
vector<int> g[MAXN+5];int RT;
int siz[MAXN+5],mx[MAXN+5],vis[MAXN+5],cent;
void findcent(int x,int f,int tot){
	siz[x]=1;mx[x]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,tot);siz[x]+=siz[y];
		chkmax(mx[x],siz[y]);
	}
	chkmax(mx[x],tot-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
void divcent(int x){
	vis[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;cent=0;
		findcent(y,x,siz[y]);g[x].pb(cent);divcent(cent);
	}
}
int dep[MAXN+5],dis[MAXN+5];
void getdep(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f||vis[y]) continue;
		dep[y]=dep[x]+1;dis[y]=dis[x]+((z<VAL)?-1:1);
		getdep(y,x);
	}
}
vector<int> pt;
void findpts(int x,int f){
	pt.pb(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findpts(y,x);
	}
}
void solve(int x){
	vis[x]=1;dis[x]=dep[x]=0;getdep(x,0);
	vector<pii> A,vec;A.pb(mp(0,x));
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		pt.clear();findpts(y,x);int mxdep=0;
		for(int z:pt) chkmax(mxdep,dep[z]);
		vec.pb(mp(mxdep,y));
	}
	sort(vec.begin(),vec.end());
	for(pii pp:vec){
		int y=pp.se;pt.clear();findpts(y,x);
		vector<pii> B;B.resize(pp.fi+1);
		for(int i=0;i<=pp.fi;i++) B[i]=mp(-INF,0);
		for(int z:pt) chkmax(B[dep[z]],mp(dis[z],z));
		static pii q[MAXN+5];int FR=1,TL=0;
		for(int i=min((int)(B.size())-1,R);i>=L;i--){
			while(FR<=TL&&q[TL]<B[i]) --TL;
			q[++TL]=B[i];
		}
		for(int i=0;i<min((int)A.size(),R);i++){
			while(FR<=TL&&dep[q[FR].se]+i>R) ++FR;
			if(FR<=TL) chkmax(MX,mt(q[FR].fi+A[i].fi,q[FR].se,A[i].se));
			int id=L-i-1;
			if(id<B.size()&&id>=0){
				while(FR<=TL&&q[TL]<B[id]) --TL;
				q[++TL]=B[id];
			}
		}
		swap(A,B);
		for(int i=0;i<B.size();i++) chkmax(A[i],B[i]);
	}
	for(int y:g[x]){
		solve(y);
		if(get<0>(MX)>=0) return;
	}
}
bool check(int v){
	memset(vis,0,sizeof(vis));
	VAL=v;MX=mt(-INF,0,0);solve(RT);
	return get<0>(MX)>=0;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);int mxv=0;
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);chkmax(mxv,w);
	}
	mx[0]=INF;findcent(1,0,n);RT=cent;divcent(cent);
	int l=0,r=mxv,p=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) p=mid,l=mid+1;
		else r=mid-1;
	}
	check(p);
	printf("%d %d\n",get<1>(MX),get<2>(MX));
	return 0;
}