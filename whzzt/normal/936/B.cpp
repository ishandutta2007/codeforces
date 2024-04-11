#include<bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector")
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
		#define gc()getchar()
	#else
		#define gc()(iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
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

const int N=100005;

vector<int>e[N];
int n,m,qu[N<<1],fl[N<<1],ql,qr,c,S,from[N][2];
bool vi[N][2],draw;

void dfs(int u,int c){
	if(u==S&&c==0){
		printf("%d ",u);
		return;
	}
	dfs(from[u][c],c^1);
	printf("%d ",u);
}

bool in[N],vv[N];
void dfs(int u){
	vv[u]=true;in[u]=true;
	for(int v:e[u]){
		if(vv[v]){
			draw|=in[v];
		}else dfs(v);
	}
	in[u]=false;
}

int main(){
	gi(n);gi(m);
	fo(i,1,n){
		gi(c);e[i].resize(c);
		fo(j,0,c-1)gi(e[i][j]);
	}
	gi(S);
	qu[ql=qr=1]=S;fl[1]=0;
	while(ql<=qr){
		int u=qu[ql],d=fl[ql]^1;ql++;
		for(int v:e[u]){
			if(!vi[v][d]){
				vi[v][d]=true;
				from[v][d]=u;
				qu[++qr]=v;
				fl[qr]=d;
			}
		}
	}
	fo(i,1,n)if(!e[i].size()&&vi[i][1])puts("Win"),dfs(i,1),exit(0);
	dfs(S);
	if(draw)puts("Draw");else puts("Lose");
	return 0;
}