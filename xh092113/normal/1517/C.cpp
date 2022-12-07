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

typedef pair<int,int> pii;

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

int n,a[N+5][N+5];
int p[N+5];

void move(pii &p,int x){
	if(a[p.fi][p.se-1] == 0)p.se--;
	else p.fi++;
	a[p.fi][p.se] = x;
}
void solve(){
	rep(i,0,n)rep(j,0,n)a[i][j] = -1;
	rep(i,1,n)rep(j,1,n)a[i][j] = 0;
	rep(i,1,n){
		int x = p[i];
		a[i][i] = x;
		pii p = mp(i,i);
		rep(j,1,x - 1)move(p,x);
	}
	rep(i,1,n){
		rep(j,1,i)write(a[i][j]),putchar(' ');
		putchar('\n');
	}
}

int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	n = read();
	rep(i,1,n)p[i] = read();
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