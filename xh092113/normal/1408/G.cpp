#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const ll mod = 998244353;
const int N = 1500;

namespace IO{
	In int read(){
		int s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(int x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
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
};
using namespace ModCalc;

int n,a[N+5][N+5],cnt;

struct edge{
	edge(){}
	edge(int _u,int _v,int _w){u = _u,v = _v,w = _w;}
	int u,v,w;
}e[N*N+5];
In bool cmp(edge a,edge b){
	return a.w < b.w;
}

struct DSU{
	int cnt;
	int fa[2*N+5],lf[2*N+5],en[2*N+5];
	bool flag[2*N+5];
	vector<ll> f[2*N+5];
	vector<ll> son[2*N+5];
	void init(){
		cnt = n;
		for(rg int i = 1;i <= n;i++)fa[i] = i,lf[i] = 1,en[i] = 0,flag[i] = 1;
	}	
	int getfa(int x){
		int y = fa[x];
		if(fa[y] == y)return y;
		else return fa[x] = getfa(y);
	}
	In bool check(int u){
		return en[u] == (lf[u] * (lf[u]-1) >> 1);
	}
	void con(int x,int y){
		int fx = getfa(x);
		int fy = getfa(y);
		if(fx == fy){
			en[fx]++;
			if(check(fx))flag[fx] = 1;
			return;
		}
		cnt++;
		son[cnt].push_back(fx);
		son[cnt].push_back(fy);
		fa[fx] = fa[fy] = fa[cnt] = cnt;
		lf[cnt] = lf[fx] + lf[fy];
		en[cnt] = en[fx] + en[fy] + 1;
		if(check(cnt))flag[cnt] = 1;
	}
	void dfs(int u){
		f[u].resize(lf[u] + 1);
		if(!son[u].size()){f[u][1] = 1;return;}
		int lc = son[u][0],rc = son[u][1];
//cout<<"u="<<u<<" lc="<<lc<<" rc="<<rc<<" lf="<<lf[u]<<endl;
		dfs(lc),dfs(rc);
		for(rg int i = 1;i <= lf[lc];i++)
			for(rg int j = 1;j <= lf[rc];j++)
				Inc(f[u][i+j],f[lc][i] * f[rc][j] % mod);
		if(flag[u])f[u][1] = 1;
	}
	void dp(){
		dfs(cnt);
		for(rg int i = 1;i <= n;i++){
			write(f[cnt][i]);
			putchar(i == n ? '\n' : ' ');
		}
	}
}D;

int main(){
//	freopen("CF1408G.in","r",stdin);
//	freopen("CF1408G.out","w",stdout);

/////////////////////////////////////////////////// memory limit!!!

	n = read();
	for(rg int i = 1;i <= n;i++)
		for(rg int j = 1;j <= n;j++)a[i][j] = read();
	for(rg int i = 1;i <= n;i++)
		for(rg int j = i + 1;j <= n;j++)e[++cnt] = edge(i,j,a[i][j]);
	sort(e + 1,e + cnt + 1,cmp);	
	
	D.init();	
	for(rg int i = 1;i <= cnt;i++)D.con(e[i].u,e[i].v);
	D.dp();
	
	return 0;
}