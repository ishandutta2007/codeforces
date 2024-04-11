#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long 

const int N = 3e5;
const ll mod = 998244353;

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
}
using namespace IO;

namespace ModCalc{
	In void Inc(ll &x,ll y){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y){
		x -= y;if(x < 0)x += mod;	
	}
	In ll Add(ll x,ll y){
		Inc(x,y);return x;
	}
	In ll Sub(ll x,ll y){
		Dec(x,y);return x;
	}
}
using namespace ModCalc;

ll f[N+5][2],g[N+5];
vector<int>link[N+5];

void dfs(int u,int fa){
	if(link[u].size() == 1 && u != 1){
		f[u][0] = f[u][1] = g[u] = 1;
		return;
	}
	f[u][0] = f[u][1] = g[u] = 1;
	for(auto v : link[u]){
		if(v == fa)continue;
		dfs(v,u);
		f[u][0] = f[u][0] * Sub(Add(2*f[v][0]%mod,2*f[v][1]%mod),g[v]) % mod; 
		f[u][1] = f[u][1] * Sub(Add(2*f[v][0]%mod,f[v][1]),g[v]) % mod;
		g[u] = g[u] * Sub(Add(f[v][0],f[v][1]),g[v]) % mod;
	}
}

int main(){
//	freopen("F.in","r",stdin);
	int n = read();
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		link[u].push_back(v);
		link[v].push_back(u);
	}
	dfs(1,0);
//for(rg int i = 1;i <= n;i++)cout<<"i="<<i<<" f0="<<f[i][0]<<" f1="<<f[i][1]<<" g="<<g[i]<<endl;
	write(Sub(Add(f[1][0],f[1][1]),Add(g[1],1))),putchar('\n');
	return 0;
}