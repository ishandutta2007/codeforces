#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long
#define rep(i,l,r) for(rg int i = (l);i <= (r);i++)
#define dwn(i,r,l) for(rg int i = (r);i >= (l);i--)
#define mp make_pair
#define fi first
#define se second

const int N = 500;
const int K = 20;
const ll inf = 0x3f3f3f3f;

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

ll f[N+5][N+5],g[N+5][N+5],dp[N+5][N+5][K+5];
int n,m,k;

void solve(){
	rep(i,1,n)rep(j,1,m - 1)f[i][j] = read();
	rep(i,1,n - 1)rep(j,1,m)g[i][j] = read();
	if(k & 1){
		rep(i,1,n){
			rep(j,1,m)putchar('-'),putchar('1'),putchar(' ');
			putchar('\n');
		}
		return;
	}
	rep(i,0,n + 1)rep(j,0,m + 1)dp[i][j][0] = inf;
	rep(i,1,n)rep(j,1,m)dp[i][j][0] = 0;
	rep(t,1,k >> 1){
		rep(i,0,n + 1)rep(j,0,m + 1)dp[i][j][t] = inf;
		rep(i,1,n)rep(j,1,m){
			chkmin(dp[i][j][t],dp[i-1][j][t-1] + g[i-1][j]);
			chkmin(dp[i][j][t],dp[i+1][j][t-1] + g[i][j]);
			chkmin(dp[i][j][t],dp[i][j-1][t-1] + f[i][j-1]);
			chkmin(dp[i][j][t],dp[i][j+1][t-1] + f[i][j]);
		}
	}
	rep(i,1,n){
		rep(j,1,m)write(dp[i][j][k>>1] * 2),putchar(' ');
		putchar('\n');
	}
}

int main(){
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	n = read(),m = read(),k = read();
	solve();
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