#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e6;

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

int n,ans[N+5],dep[N+5],son[N+5];
int buf[N+5],*now = buf,*f[N+5];
vector<int> e[N+5];

void prepro(int u,int fa){
	for(rg int i = 0;i < e[u].size();i++){
		int v = e[u][i];
		if(v == fa)continue;
		prepro(v,u);
		if(dep[v] > dep[son[u]])son[u] = v;
	}
	dep[u] = dep[son[u]] + 1;
}
void dfs(int u,int fa){
	f[u][0] = 1;ans[u] = 0;
	if(son[u]){
		f[son[u]] = f[u] + 1;
		dfs(son[u],u);
		ans[u] = ans[son[u]] + 1;
		if(f[u][ans[u]] <= 1)ans[u] = 0;
	}
	for(rg int i = 0;i < e[u].size();i++){
		int v = e[u][i];
		if(v == fa || v == son[u])continue;
		f[v] = now,now += dep[v];
		dfs(v,u);
		for(rg int j = 1;j <= dep[v];j++){
			f[u][j] += f[v][j-1];
			if(f[u][j] > f[u][ans[u]] || ((f[u][j]==f[u][ans[u]])&&(j<ans[u])))ans[u] = j;
		}
	}
}

int main(){
//	freopen("CF1009F.in","r",stdin);
//	freopen("CF1009F.out","w",stdout);
	n = read();
	for(rg int i = 1;i < n;i++){
		int u = read(),v = read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	prepro(1,0);
	f[1] = now,now += dep[1];
	dfs(1,0);
	for(rg int i = 1;i <= n;i++)write(ans[i]),putchar('\n');
	return 0;
}