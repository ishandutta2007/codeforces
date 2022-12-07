#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair

const int N = 400;
const int M = 600;
const int inf = 0x3f3f3f3f;
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
};
using namespace IO;

namespace ModCalc{
	In void Inc(ll &x,ll y){
		x += y;if(x >= mod)x -= mod;
	}
	In void Dec(ll &x,ll y){
		x -= y;if(x < 0)x += mod;
	}
	In ll Add(ll x,ll y){Inc(x,y);return x;}
	In ll Sub(ll x,ll y){Dec(x,y);return x;}
};
using namespace ModCalc;

int n,m;
int dis[N+5][N+5];
int pre[N+5],pren[N+5],dir[N+5];
bool vis[N+5];
vector<int> e[N+5];
ll ans[N+5][N+5],f[N+5];
ll pw[N+5][N+5];
queue<int> Q;
vector<int> path;

void floyd(){
	for(rg int k = 1;k <= n;k++)
		for(rg int i = 1;i <= n;i++)
			for(rg int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
}
bool check(int u,int v){
	for(rg int i = v;i != u;i = pre[i])if(pren[i] > 1)return 0;
	return 1;
}
In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = s * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}
void calcpre(int s){
	for(rg int u = 1;u <= n;u++){
		pren[u] = 0;
		if(u == s)pre[u] = 0;
		else{
			for(auto v : e[u])if(dis[s][v] + 1 == dis[s][u])pre[u] = v,pren[u]++;
		}
	}
}
void calcdir(int s1,int s2){
	for(rg int u = 1;u <= n;u++){
		dir[u] = 0;
		for(auto v : e[u]){
			if(dis[s1][v] + 1 == dis[s1][u] &&
			   dis[s2][v] + 1 == dis[s2][u])dir[u]++;
		}
	}
}

//int num[N+5];
vector<int> vc;
void dfs(int s1,int s2,int u){
	for(auto v : e[u]){
		if(dis[s1][u] + 1 != dis[s1][v])continue;
		if(dis[s2][u] + 1 != dis[s2][v])continue;
		if(vis[v])continue;
		vis[v] = 1;
		vc.push_back(v);
		dfs(s1,s2,v);
	}
}
ll check(int s1,int s2,int u){
//cout<<"check: s1="<<s1<<" s2="<<s2<<" u="<<u<<endl;
	vc.resize(0);
	dfs(s1,s2,u);
	ll rt = 1;
	for(auto v : vc)rt = rt * dir[v] % mod;
	return rt;
}
	/*
	int maxn = 0;
for(auto x : vc)cout<<"x="<<x<<endl;
	for(auto x : vc){
		num[x-dis[s1][u]]++;
		maxn = max(maxn,x - dis[s1][u]);
	}
for(rg int i = 0;i <= maxn;i++)cout<<num[i]<<" ";cout<<endl;
	ll rt = 1;
	for(rg int i = 0;i < maxn;i++)rt = rt * pw[num[i]][num[i+1]] % mod;
	for(rg int i = 0;i <= maxn;i++)num[i] = 0;
	return rt;
}*/
/*
ll getdd(int s1,int s2,int u){
	if(dd[u] != 0)return dd[u];
	int cur = 0;
	for(auto v : e[u])if(dis[s1][v] + 1 == dis[s1][u] || dis[s2][v] + 1 == dis[s2][u]){
		int x = getdd(s1,s2,v);
		if(cur == 0)cur = x;
		else if(cur != x)cur = -1;
	}
	return dd[u] = cur;
}*/
/*ll check(vector<int> hg){
	int maxn = 0;
	for(auto x : hg){
		num[x]++;
		maxn = max(maxn,x);
	}
	ll rt = 1;
	for(rg int i = 0;i < maxn;i++)rt = rt * pw[num[i]][num[i+1]] % mod;
	for(rg int i = 0;i <= maxn;i++)num[i] = 0;
	return rt;
}*/
ll solve(int u,int v){
//cout<<"solve: u="<<u<<" v="<<v<<endl;
//for(rg int i = 1;i <= n;i++)cout<<"i="<<i<<" pre="<<pre[i]<<" pren="<<pren[i]<<endl;
	// u -> v has only one nearest path
	calcdir(u,v);
	if(!check(u,v))return 0;
	path.resize(0);
	memset(vis,0,sizeof(vis));
	for(rg int i = v;i;i = pre[i])path.push_back(i),vis[i] = 1;
	ll rt = 1;
//cout<<"path:"<<endl;
//for(auto w : path)cout<<"w="<<w<<endl;
	for(auto w : path)rt = rt * check(u,v,w) % mod;
	for(rg int i = 1;i <= n;i++)if(!vis[i])return 0;
	return rt;
/*	
//	memset(vis,0,sizeof(vis));
	memset(dd,0,sizeof(dd));
	for(rg int i = 1;i <= n;i++){dd[i] = getdd(u,v,i);if(dd[i] == -1)return 0;}
	for(auto w : path)hg[w].resize(0);
	for(rg int i = 1;i <= n;i++)hg[dd[i]].push_back(dis[u][i] - dis[u][dd[i]]);
	for(auto w : path)rt = rt * check(hg[w]) % mod;
	return rt;
	
	for(rg int i = 1;i <= n;i++)if(i != u && i != v){
		int nu = 0,nv = 0,posu,posv;
		for(auto w : path){
			if(dis[u][w] + dis[w][i] == dis[u][i])nu++,posu = w;
			if(dis[v][w] + dis[w][i] == dis[v][i])nv++,posv = w;
		}
		if(nu != 1 || nv != 1)return 0;
		if(posu != posv)return 0;
		hg[posu].push_back(
	}*/
	
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
// USE LONG LONG
// time LIMIT
	n = read(),m = read();
	for(rg int i = 0;i <= n;i++)	
		for(rg int j = 0;j <= n;j++)pw[i][j] = power(i,j);
	memset(dis,0x3f,sizeof(dis));
	for(rg int i = 1;i <= n;i++)dis[i][i] = 0;
	for(rg int i = 1;i <= m;i++){
		int u = read(),v = read();
		dis[u][v] = dis[v][u] = 1;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	floyd();
/*for(rg int i = 1;i <= n;i++){
	for(rg int j = 1;j <= n;j++)cout<<dis[i][j]<<" ";cout<<endl;
}*/
	for(rg int i = 1;i <= n;i++){
		calcpre(i);
		for(rg int j = i;j <= n;j++)ans[i][j] = ans[j][i] = solve(i,j);
	}
	for(rg int i = 1;i <= n;i++){
		for(rg int j = 1;j <= n;j++)cout<<ans[i][j]<<" ";cout<<endl;
	}
	return 0;
}