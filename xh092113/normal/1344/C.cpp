#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 2e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)x = -x,putchar('-');
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
}
using namespace IO;

vector<int>in[N+5],out[N+5];
bool vis[N+5];
int f[N+5],g[N+5];
int n,m;

int dp1(int u){
	if(vis[u])return f[u];
	vis[u] = 1;
	for(auto v : in[u])f[u] = min(f[u],dp1(v));
	return f[u];
}

int dp2(int u){
	if(vis[u])return g[u];
	vis[u] = 1;
	for(auto v : out[u])g[u] = min(g[u],dp2(v));
	return g[u];
}

queue<int>q;
int ind[N+5];

bool bfs(){
	for(rg int i = 1;i <= n;i++)ind[i] = in[i].size();
//for(rg int i = 1;i <= n;i++)cout << ind[i] << " ";cout<<endl;
	for(rg int i = 1;i <= n;i++)if(!ind[i])q.push(i);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v : out[u]){
			ind[v]--;
			if(!ind[v])q.push(v);
		}
	}
	for(rg int i = 1;i <= n;i++)if(ind[i])return 0;
	return 1;
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	n = read(),m = read();
	for(rg int i = 1;i <= n;i++)f[i] = g[i] = i;
	for(rg int i = 1;i <= m;i++){
		int u = read(),v = read();
		out[u].push_back(v);
		in[v].push_back(u);
	}
	if(!bfs()){
		puts("-1");
		return 0;
	}
	memset(vis,0,sizeof(vis));
	int opt;
	for(rg int i = 1;i <= n;i++)opt = dp1(i);
	memset(vis,0,sizeof(vis));
	for(rg int i = 1;i <= n;i++)opt = dp2(i);
	int ans = 0;
	for(rg int i = 1;i <= n;i++)if(min(f[i],g[i]) == i)ans++;
	write(ans),putchar('\n');
//for(rg int i = 1;i <= n;i++)cout<<"i="<<i<<" f="<<f[i]<<" g="<<g[i]<<endl;
	for(rg int i = 1;i <= n;i++)if(min(f[i],g[i]) == i)putchar('A');
	else putchar('E');
	putchar('\n');
	return 0;
}