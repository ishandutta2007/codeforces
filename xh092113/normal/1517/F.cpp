#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 300;
const ll mod = 998244353;
const ll v2 = (mod + 1) >> 1;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}
template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}

namespace ModCalc{
	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}
	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}
	In ll Add(ll x,ll y){Inc(x,y);return x;}
	In ll Sub(ll x,ll y){Dec(x,y);return x;}
};
using namespace ModCalc;

int n,sz[N+5],fa[N+5];
vector<int> e[N+5];
ll f[N+5][N+5],g[N+5][N+5];
ll tf[N+5],tg[N+5],pregu[N+5],pregv[N+5],prefu[N+5],prefv[N+5];

In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}
void prepro(int u,int ff){
	fa[u] = ff;
	sz[u] = 1;
	for(auto v : e[u])if(v != ff){
		prepro(v,u);
		sz[u] += sz[v];
	}
}
void dfs(int u,int d){
//cout<<"dfs: u="<<u<<" d="<<d<<endl;
	int cursz = 1;
	memset(f[u],0,sizeof(ll) * (sz[u]+1));
	memset(g[u],0,sizeof(ll) * (d+1));
	f[u][0] = g[u][d] = 1;
	for(auto v : e[u])if(v != fa[u]){
		dfs(v,d);
		memset(tf,0,sizeof(ll) * (cursz+sz[v]+1));
		memset(tg,0,sizeof(ll) * (d+1));
		
		pregu[0] = g[u][0];rep(j,1,d)pregu[j] = Add(pregu[j-1],g[u][j]);
		pregv[0] = g[v][0];rep(j,1,d)pregv[j] = Add(pregv[j-1],g[v][j]);
		prefu[0] = f[u][0];rep(j,1,cursz)prefu[j] = Add(prefu[j-1],f[u][j]);
		prefv[0] = f[v][0];rep(j,1,sz[v])prefv[j] = Add(prefv[j-1],f[v][j]);
		 
		pregv[d+1] = pregv[d];
		rep(i,0,d)Inc(tg[i],pregu[i] * pregv[i+1] % mod);
		dwn(i,d,1)Dec(tg[i],tg[i-1]); // g&g
		
		rep(i,0,cursz)rep(j,0,sz[v])Inc(tf[max(i,j+1)],f[u][i] * f[v][j] % mod); // f&f
		
		rep(i,0,cursz)Inc(tf[i],pregv[min(i,d)] * f[u][i] % mod);
		rep(j,1,d)Inc(tg[j-1],prefu[min(j-1,cursz)] * g[v][j] % mod); // f&g
		
		rep(i,1,d)Inc(tg[i],prefv[min(i-1,sz[v])] * g[u][i] % mod);
		rep(j,0,sz[v])Inc(tf[j+1],pregu[min(j,d)] * f[v][j] % mod); // g&f
				
//		rep(i,0,cursz)rep(j,0,d)Inc(j - 1 >= i ? tg[j-1] : tf[i],f[u][i] * g[v][j] % mod); // f&g
//		rep(i,0,d)rep(j,0,sz[v])Inc(i >= j + 1 ? tg[i] : tf[j+1],g[u][i] * f[v][j] % mod); // g&f
		
		cursz += sz[v];
		memcpy(f[u],tf,sizeof(ll) * (cursz+1));
		memcpy(g[u],tg,sizeof(ll) * (d+1));
	}
/*cout<<"u="<<u<<endl;
rep(i,0,sz[u])cout<<f[u][i]<<" ";cout<<endl;
rep(i,0,d)cout<<g[u][i]<<" ";cout<<endl;*/
}
In ll calc(int d){ // cases which ans < d
//cout<<"calc: d="<<d<<endl;
	dfs(1,d);
	ll ans = 0;
	rep(i,0,n)Inc(ans,g[1][i]);
//cout<<"d="<<d<<" ans="<<ans<<endl;
	return ans;
}

int main(){
//	freopen("F.in","r",stdin);
//	freopen("F.out","w",stdout);
	n = read();
	rep(i,1,n - 1){
		int u = read(),v = read();
		e[u].pb(v);
		e[v].pb(u);
	}
	prepro(1,0);
	ll ans = 0,All = power(2,n);
	rep(i,1,n - 1)Inc(ans,Sub(All,calc(i)));
	ans = ans * power(v2,n) % mod;
	write(ans),putchar('\n');
	return 0;
}
// T: Think
// E: Enough array size
// M: Memory limit
// P: Precision
// B: Boundary
// O: Overflow
// T: Time limit
// M: Mod
// F: File