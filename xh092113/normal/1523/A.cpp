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

const int N = 1e3;

int n,m;
int a[N+5];
char s[N+5];
vector<int> vc;

void solve(){
	scanf("%s",s + 1);
	int num = 0;
	rep(i,1,n){a[i] = s[i] - '0';num += a[i];}
	a[n+1] = 0;
	rep(i,1,m){
		vc.resize(0);
		rep(j,1,n)if(!a[j] && a[j-1] + a[j+1] == 1)vc.pb(j);
		for(auto x : vc)a[x] = 1;
		if(!vc.size())break;
	}
	rep(i,1,n)putchar(a[i] + '0');putchar('\n');
}

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	int Tc = read();
	while(Tc--){
		n = read(),m = read();
		solve();
	}
	
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