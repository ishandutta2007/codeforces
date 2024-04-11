#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i,k,j) for(int i=(k);i>=(j);i--)
#define For(i,k,j) for(int i=(k);i<=(j);i++)
#define Foe(i,u) for(int i=lst[u],v=e[i].v;i;i=e[i].nxt,v=e[i].v)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1<<30)-1)
//#define int long long
const int P=1e9+7; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  void write(ll x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=5e5+5;
int n,m,c[MN]; 


struct atom {
	int mn,cnt;
	atom() {mn=1e9,cnt=1;} 
	atom(int MN,int CNT):mn(MN),cnt(CNT){}
	
};
inline atom operator + (const atom &a,const atom &b) {
	return a.mn<b.mn?a:(a.mn!=b.mn?b:atom(a.mn,a.cnt+b.cnt));	
}
inline int gogo(const atom &it) { if(it.mn!=0) return 0; return it.cnt; }
struct SMT {
	static const int N=MN<<2;
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	int tag[N]; atom a[N];;
	bool cov[N];
	int M,L[N];
	void pushr(int k,int v)  { tag[k]+=v; a[k].mn+=v; }
	void pushc(int k) { cov[k]=1,tag[k]=0;a[k]=atom(0,L[k]);}
	void pushdown(int k) { 
		if(k>=M) return; 
		if(cov[k]) {pushc(ls),pushc(rs); cov[k]=0; }
		if(tag[k]) { pushr(ls,tag[k]),pushr(rs,tag[k]); tag[k]=0; } 
	}
	void build(int n) {
		for(M=1;M<=n+1;M<<=1); L[M]=0,a[M]=atom(1e9,1);
		for(int i=1;i<=n;i++) a[M+i]=atom(0,1),L[M+i]=1;
		for(int i=n+1;i<M;i++) a[M+i]=atom(1e9,1),L[M+i]=0;
		for(int k=M-1;k>=1;k--) a[k]=a[ls]+a[rs],L[k]=L[ls]+L[rs];
	}
	int stk[20],top;
	void upd(int x) {
		for(top=0;x;x>>=1) stk[top++]=x;
		while(top--) pushdown(stk[top]);
	}
	int qryupd(int s,int t) {
		int xs=0,xt=0,res=0;
		for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1) {	
			if(~s&1) {
				if(!xs) upd(xs=s^1); res+=gogo(a[s^1]); pushr(s^1,1);
			}
			if(t&1) {
				if(!xt) upd(xt=t^1); res+=gogo(a[t^1]);	pushr(t^1,1);
			}
		}
		for(xs>>=1;xs;xs>>=1) a[xs]=a[xs<<1]+a[xs<<1|1];
		for(xt>>=1;xt;xt>>=1) a[xt]=a[xt<<1]+a[xt<<1|1];
		return res;
	}
	int updqry(int s,int t) {
		int xs=0,xt=0,res=0;
		for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1) {
			if(~s&1) {
				if(!xs) upd(xs=s^1); pushr(s^1,-1); res+=gogo(a[s^1]);
			}
			if(t&1) {
				if(!xt) upd(xt=t^1); pushr(t^1,-1); res+=gogo(a[t^1]);	
			}
		}
		for(xs>>=1;xs;xs>>=1) a[xs]=a[xs<<1]+a[xs<<1|1];
		for(xt>>=1;xt;xt>>=1) a[xt]=a[xt<<1]+a[xt<<1|1];
		return res;
	}
}tr; 

int VRT=1e9,RT,siz[MN],vis[MN],f[MN],dsiz[MN],ban[MN];  
vi e[MN],g[MN];
void getroot(int u,int fa,int allsiz) {
	siz[u]=1; int mx=0;
	for(auto v:e[u]) { if(v==fa||vis[v]) continue; 
		getroot(v,u,allsiz); siz[u]+=siz[v]; ckmax(mx,siz[v]);
	}
	ckmax(mx,allsiz-siz[u]);
	if(mx<VRT) VRT=mx,RT=u;
}


void dfz(int u,int allsiz) {
	vis[u]=1,dsiz[u]=allsiz-1; 
	for(auto v:e[u]) { if(vis[v]) continue;
		int tsiz=siz[u]>siz[v]?siz[v]:allsiz-siz[u]; VRT=1e9;
		getroot(v,u,tsiz); f[RT]=u; g[u].pb(RT); dfz(RT,tsiz);
	}
}
struct ele {
	int x,y,z;
	ele(){} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
	bool operator < (const ele &b) const {
		if(x!=b.x) return x<b.x;
		return y<b.y;
	}
};

ll ans[MN],nowans;
int bel[MN],L[MN],R[MN],ind=0;
vector<ele> q[MN];
int tsiz[MN];
ele qr[MN*5]; int qcnt=0;
void dfs(int u,int fa,int st) {
	bel[u]=st; L[u]=++ind; siz[u]=1;
	for(auto &it:q[u]) {qr[++qcnt]=it;}
	for(auto v:e[u]) { if(v==fa||vis[v]) continue;
		dfs(v,u,st); siz[u]+=siz[v];
	} R[u]=ind; tsiz[u]=siz[u];
	
}
int tmp[MN*5]; int tmpcnt;
void solve(int x) {
	vis[x]=1; 
	ll val=0,tval=0; int ban=0; ind=0,qcnt=0;
	for(auto &it:q[x]) {qr[++qcnt]=it;}
	for(auto v:e[x]) { if(vis[v]) continue; int lind=ind;
		dfs(v,x,v); int siz=ind-lind;
		val+=2ll*siz*lind;
	} val+=ind*2+1; tval=val;
	if(!qcnt) return;
	tr.build(dsiz[x]);
	sort(qr+1,qr+1+qcnt);
	ll lst=val,nowans=val;
	For(i,1,qcnt) { 
		int u=abs(qr[i].z),v=qr[i].z>=0,id=qr[i].y;
		if(qr[i].x!=qr[i-1].x) { 
			tr.pushc(1); ban=0,val=lst=nowans=tval; 
			For(i,1,tmpcnt) siz[tmp[i]]=tsiz[tmp[i]];
			tmpcnt=0;
		}
		if(u==x) {
			if(v==1) { nowans-=(!ban)*val; ban++; }	
			else { nowans+=(ban==1)*val; ban--; }
			ans[id]+=lst-nowans; lst=nowans;
			continue;
		}
		int l=L[u],r=R[u];
		int all=gogo(tr.a[1])+1,ex=all-siz[bel[u]];
		if(v==1) {
			if(!ban) nowans-=val;
			int sn=tr.qryupd(l,r); val-=2ll*ex*sn; siz[bel[u]]-=sn;
			tmp[++tmpcnt]=bel[u];
			if(!ban) nowans+=val;
		} else {
			if(!ban) nowans-=val;
			int sn=tr.updqry(l,r); val+=2ll*ex*sn; siz[bel[u]]+=sn;
			tmp[++tmpcnt]=bel[u];
			if(!ban) nowans+=val;
		}
		ans[id]+=lst-nowans; lst=nowans;
	}
	for(auto v:g[x]) {
		solve(v);
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
//	cerr<<sizeof(tr)<<endl;
	n=read(),m=read();
	For(i,1,n) { c[i]=read(); q[i].pb(ele(c[i],0,i))  ; }
	For(i,1,n-1) {int u=read(),v=read(); e[u].pb(v),e[v].pb(u); }
	For(i,1,m) {
		int x=read(),nc=read();
		q[x].pb(ele(c[x],i,-x));
		c[x]=nc; q[x].pb(ele(c[x],i,x));
	}
	getroot(1,0,n); int TRT=RT;  dfz(RT,n); mst(vis,0);
	
	solve(TRT);
	FO(ans[0]); FO('\n');
	For(i,1,m) ans[i]+=ans[i-1],FO(ans[i]),FO('\n');
	return FastIO::Fflush(),0;
}

// ???