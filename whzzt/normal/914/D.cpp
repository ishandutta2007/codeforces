#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define Bitcount(n) __builtin_popcount(n)
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc() getchar()
	#else
		#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

const int N=500005;

int n,q,g[N<<2];
void modify(int x,int l,int r,int p,int u){
	if(l==r)return (void)(g[x]=u);
	int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
	if(p<=mid)modify(ls,l,mid,p,u);else modify(rs,mid+1,r,p,u);
	g[x]=GCD(g[ls],g[rs]);
}
int ql(int x,int l,int r,int s,int t,int v){
	if(g[x]%v==0)return l-1;
	if(l==r&&g[x]%v!=0)return r;
	int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
	if(t<=mid)return ql(ls,l,mid,s,t,v);
	if(s>mid)return ql(rs,mid+1,r,s,t,v);
	int ret=ql(rs,mid+1,r,mid+1,t,v);
	if(ret<=mid)return ql(ls,l,mid,s,mid,v);
	return ret;
}
int qr(int x,int l,int r,int s,int t,int v){
	if(g[x]%v==0)return r+1;
	if(l==r&&g[x]%v!=0)return r;
	int ls=x<<1,rs=ls|1,mid=(l+r)>>1;
	if(t<=mid)return qr(ls,l,mid,s,t,v);
	if(s>mid)return qr(rs,mid+1,r,s,t,v);
	int ret=qr(ls,l,mid,s,mid,v);
	if(ret>mid)return qr(rs,mid+1,r,mid+1,t,v);
	return ret;
}

int main(){
	gi(n);int o,l,r,v;
	fo(i,1,n)gi(v),modify(1,1,n,i,v);
	gi(q);
	while(q--){
		gi(o);gi(l);gi(r);
		if(o==1){
			gi(v);
			if(qr(1,1,n,l,n,v)>=ql(1,1,n,1,r,v))ps("YES\n");else ps("NO\n");
		}else modify(1,1,n,l,r);
	}
	io::flush();
	return 0;
}