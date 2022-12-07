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


namespace IO{

	In char gc(){

		static char buf[100000],*p1 = buf,*p2 = buf;

		if(p1 == p2)p2 = buf + fread(p1 = buf,1,100000,stdin);

		return p1 == p2 ? EOF : *p1++;

	}

	In ll read(){

		ll s = 0,ww = 1;

		char ch = gc();

		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = gc();}

		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = gc();}

		return s * ww;

	}

	In void write(ll x){

		if(x < 0)putchar('-'),x = -x;

		if(x > 9)write(x / 10);

		putchar('0' + x % 10);

	}

};

using namespace IO;


const int N = 200;
const ll mod = 1e9 + 7;
const ll v2 = (mod + 1) >> 1;


namespace ModCalc{

	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}

	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}

	In ll Add(ll x,ll y){Inc(x,y);return x;}

	In ll Sub(ll x,ll y){Dec(x,y);return x;}

};

using namespace ModCalc;



template<typename T> void chkmin(T &x,T y){if(y < x)x = y;}

template<typename T> void chkmax(T &x,T y){if(y > x)x = y;}


int n; 
ll dis[N+5][N+5];
ll jc[N+5],iv[N+5];
ll f[N+5][N+5];
ll g[N+5][N+5];

In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}
void floyd(){
	rep(k,1,n)rep(i,1,n)rep(j,1,n)chkmin(dis[i][j],dis[i][k] + dis[k][j]);
}
vector<int> e[N+5];
int fa[N+5][10],dep[N+5];
void dfs(int u,int ff){
	fa[u][0] = ff;dep[u] = dep[ff] + 1;
	for(int v : e[u])if(v != ff)dfs(v,u);
}
int lca(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	dwn(i,8,0)if(dep[fa[u][i]] >= dep[v])u = fa[u][i];
	if(u == v)return u;
	dwn(i,8,0)if(fa[u][i] != fa[v][i])u = fa[u][i],v = fa[v][i];
	return fa[u][0];
}
ll calcg(int x,int y){
	if(x == 0)return  0;
	if(y == 0)return 1;
	ll fy = 0,fx = 0;
	rep(i,0,x - 1)Inc(fy,f[i][y-1] * v2 % mod);
	return fy;
//	rep(j,0,y - 1)Inc(fx,f[x-1][j] * v2 % mod);
//	return fy * power(Add(fx,fy),mod-2) % mod;
}
void solve(){
	ll ans = 0;
	jc[0] = 1;rep(i,1,N)jc[i] = jc[i-1] * i % mod;
	rep(i,0,N)iv[i] = power(jc[i],mod - 2);
	
	f[0][0] = 1;
	rep(i,0,N - 1)rep(j,0,N - 1){
		Inc(f[i+1][j],f[i][j] * v2 % mod);
		Inc(f[i][j+1],f[i][j] * v2 % mod);
	}
	
//	rep(i,0,N)rep(j,0,N)f[i][j] = jc[i+j] * iv[i] % mod * iv[j] % mod * power(v2,i + j) % mod;	
	
	rep(i,0,N)rep(j,0,N)g[i][j] = calcg(i,j);

	
	rep(rt,1,n){
		dfs(rt,0);
		rep(j,1,8)rep(u,1,n)fa[u][j] = fa[fa[u][j-1]][j-1];
		ll cur = 0;
		rep(u,1,n)rep(v,u + 1,n){
			int l = lca(u,v);
//cout<<"u="<<u<<" v="<<v<<" l="<<l<<endl;
			//ll d1 = dis[l][u],d2 = dis[l][v];
			//Inc(cur,d1 * power(Add(d1,d2),mod-2) % mod);
			Inc(cur,g[dis[l][u]][dis[l][v]]);
		}
//cout<<"rt="<<rt<<" cur="<<cur<<endl;
		Inc(ans,cur);
	}
	ans = ans * power(n,mod - 2) % mod;
	write(ans),putchar('\n');
}


int main(){

//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	n = read();
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n)dis[i][i] = 0;
	rep(i,1,n - 1){
		int u = read(),v = read();
		e[u].pb(v),e[v].pb(u);
		dis[u][v] = dis[v][u] = 1;
	}
	floyd();
	solve();
	return 0;

}