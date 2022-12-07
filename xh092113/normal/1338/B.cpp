#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const ll N = 1e5;

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

vector<int>link[N+5];
int deg[N+5];
int n,rt;
int dep[N+5],n0,n1;

void dfs1(int u,int fa){
	dep[u] = dep[fa] + 1;
	if(deg[u] == 1){
		if(dep[u] % 2 == 0)n0++;
		else n1++;
		return;
	}
	for(auto v : link[u]){
		if(v == fa)continue;
		dfs1(v,u);
	}
}

ll dfs2(int u,int fa){
	ll ans = 0;
	for(auto v : link[u]){
		if(v == fa)continue;
		if(deg[v] == 1)ans = 1;
	}
	for(auto v : link[u]){
		if(v == fa)continue;
		if(deg[v] != 1)ans += dfs2(v,u) + 1;
	}
//cout<<"u="<<u<<" fa="<<fa<<" ans="<<ans<<endl;

	return ans;
}

void calc(){
	int minn,maxn;
	dfs1(rt,0);
	if(n0 && n1)minn = 3;else minn = 1;
	maxn = dfs2(rt,0);
	write(minn),putchar(' '),write(maxn),putchar('\n');
}

int main(){
//	freopen("B.in","r",stdin);
	n = read();
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		deg[u]++;
		deg[v]++;
		link[u].push_back(v);
		link[v].push_back(u);
	}

	for(rg int i = 1;i <= n;i++)if(deg[i] > 1){
		rt = i;
		break;
	}
	calc();
	return 0;
}