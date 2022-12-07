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

const int N = 100;

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

ll b[N+5][N+5];
ll c[N+5][N+5];
ll n,m;

pii pos[N*N+5];
int f[N+5],p[N+5],cnt;

In bool cmp(pii x,pii y){
	if(b[x.fi][x.se] != b[y.fi][y.se])return b[x.fi][x.se] < b[y.fi][y.se];
	else return x.se < y.se;
}

void solve(){
	n = read(),m = read();
	rep(i,1,n){
		rep(j,1,m)b[i][j] = read();
		sort(b[i] + 1,b[i] + m + 1);
	}
	cnt = 0;
	rep(i,1,n)rep(j,1,m)pos[++cnt] = mp(i,j);
	sort(pos + 1,pos + cnt + 1,cmp);
//cout<<"..."<<endl;
//rep(i,1,cnt)cout<<pos[i].fi<<" "<<pos[i].se<<endl;
//cout<<"..."<<endl;
	rep(i,1,n)p[i] = 1;
	rep(i,1,m){
		int x = pos[i].fi,y = pos[i].se;
		f[i] = x;
		p[x] = y + 1;
		c[i][x] = b[x][y];
	}
	rep(i,1,m){
		rep(j,1,f[i] - 1)c[i][j] = b[j][p[j]++];
		rep(j,f[i] + 1,n)c[i][j] = b[j][p[j]++];
	}
	rep(i,1,n){
		rep(j,1,m)write(c[j][i]),putchar(' ');
		putchar('\n');
	}
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
// CLEAR
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