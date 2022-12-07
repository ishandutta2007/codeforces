#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define mp make_pair
#define fi first
#define se second

const int N = 600;
const int M = N * N;

typedef pair<int,ll> pil;

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

int n,m;
ll dis[N+5][N+5];
pair<pair<int,int>,ll> ed[M+5];

In void chkmin(ll &x,ll y){if(y < x)x = y;}
In void chkmax(ll &x,ll y){if(y > x)x = y;}
void floyd(){
	for(rg int k = 1;k <= n;k++){
		for(rg int i = 1;i <= n;i++){
			for(rg int j = 1;j <= n;j++){
				chkmin(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
}

//// solve

int q;
bool ans[M+5];
ll f[N+5];
vector<pil> que[N+5];

void Solve(int rt){
	for(rg int i = 1;i <= n;i++)f[i] = -1;
	for(rg int i = 0;i < que[rt].size();i++){
		int v = que[rt][i].fi;ll w = que[rt][i].se;
		for(rg int j = 1;j <= n;j++){
			chkmax(f[j],w - dis[rt][j] - dis[j][v]);
		}
	}
	for(rg int i = 1;i <= m;i++){
		int u = ed[i].fi.fi,v = ed[i].fi.se;ll w = ed[i].se;
		if(dis[rt][u] + w - dis[rt][v] <= f[v])ans[i] = 1;
		if(dis[rt][v] + w - dis[rt][u] <= f[u])ans[i] = 1;
	}
}
void solve(){
	q = read();
	for(rg int i = 1;i <= q;i++){
		int u = read(),v = read();ll w = read();
		que[u].push_back(mp(v,w));
	}
	for(rg int i = 1;i <= n;i++)Solve(i);
	int rt = 0;
	for(rg int i = 1;i <= m;i++)rt += ans[i];
	write(rt),putchar('\n'); 
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
// USE LONG LONG
	n = read(),m = read();	
	memset(dis,0x3f,sizeof(dis));
	for(rg int i = 1;i <= n;i++)dis[i][i] = 0;
	for(rg int i = 1;i <= m;i++){
		int u = read(),v = read();ll w = read();
		dis[u][v] = dis[v][u] = w;
		ed[i] = mp(mp(u,v),w);
	}	
	floyd();
	solve();	
	return 0;
}