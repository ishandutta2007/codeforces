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

const int N = 1e5;

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

In void chkmin(ll &x,ll y){if(y < x)x = y;}
In void chkmax(ll &x,ll y){if(y > x)x = y;}

int n;
ll f[N+5][2],a[N+5][2];
vector<int> e[N+5];

void dfs(int u,int fa){
	f[u][0] = f[u][1] = 0;
	for(auto v : e[u])if(v != fa){
		dfs(v,u);
		f[u][0] += max(f[v][0] + abs(a[u][0]-a[v][0]),f[v][1] + abs(a[u][0]-a[v][1]));
		f[u][1] += max(f[v][0] + abs(a[u][1]-a[v][0]),f[v][1] + abs(a[u][1]-a[v][1]));
	}
//cout<<"dfs: u="<<u<<" f0="<<f[u][0]<<" f1="<<f[u][1]<<endl;
}
void solve(){
	n = read();
	rep(i,1,n)e[i].resize(0);
	rep(i,1,n)a[i][0] = read(),a[i][1] = read();
	rep(i,1,n - 1){
		int u = read(),v = read();
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1,0);
	write(max(f[1][0],f[1][1])),putchar('\n');
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--)solve();
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