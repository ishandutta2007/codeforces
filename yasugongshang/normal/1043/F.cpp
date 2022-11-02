#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
namespace IO{
	const int L=1<<15;char ibuf[L|1],*iS=ibuf,*iT=ibuf,obuf[L|1],*oS=obuf,*oT=obuf+L,c,st[66];int tp=0,f;
	inline char gc(){if(iS==iT) iT=(iS=ibuf)+fread(ibuf,sizeof(char),L,stdin);return (*iS++);}
	inline void flush(){fwrite(obuf,sizeof(char),oS-obuf,stdout);oS = obuf;}
	inline void pc(char c){*oS++=c;if(oS==oT) flush();}
	#define getchar gc
	#define pc putchar
	inline ll read(){ll x=0;f=1,c=gc();for(;!isdigit(c);c=gc())if(c=='-')f=-1;for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c&15);return x*f;}
	inline void write(ll x){if(!x) pc('0');if(x<0) pc('-'),x=-x;while(x) st[++tp]=x%10+'0',x/=10;while(tp) pc(st[tp--]);}
	inline void writeln(ll x){write(x);pc('\n');}
	inline void wri(ll x){write(x),pc(' ');}
	struct IOflusher{~IOflusher(){flush();}}_ioflusher_;
}using IO::read;using IO::write;using IO::writeln;using IO::wri;//using IO::gc;using IO::pc;
const int maxn = 300500;
int n,f[maxn],g[maxn],a[maxn],mx;
inline void solve(int n){
	for(register int i=1;i<=n;++i)
		for(register int j=i+i;j<=n;j+=i)
			g[i]+=g[j];
	Rep(i,1,n) g[i]=g[i]*f[i];
	for(register int i=n;i>=1;--i)
		for(register int j=i+i;j<=n;j+=i)
			g[i]-=g[j];
	Rep(i,1,n) g[i]=g[i]?1:0;
}
int main(){
	n = read();
	int G = 0;
	mx=0;
	Rep(i,1,n) a[i] = read(),f[a[i]] = 1,G=__gcd(G,a[i]),g[a[i]] = 1,mx=max(mx,a[i]);
	Rep(i,1,mx)for(register int j=2*i;j<=mx;j+=i)f[i]+=f[j];
	if(G!=1){
		puts("-1");
		return 0;
	}
	int ans = 1;
	while(g[1] == 0){
		ans++; 
		if(ans==7){
			cout<<ans<<endl; return 0;
		}
		solve(mx);
	}
	writeln(ans);	
}