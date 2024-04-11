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

int n;
int a[N+5];

void solve(){
	cout<<n * 3<<endl;
	rep(i,1,n)a[i] = read();
	for(rg int i = 1;i < n;i += 2){
		cout<<1<<" "<<i<<" "<<i+1<<endl;
		cout<<2<<" "<<i<<" "<<i+1<<endl;
		cout<<1<<" "<<i<<" "<<i+1<<endl;
		cout<<1<<" "<<i<<" "<<i+1<<endl;
		cout<<2<<" "<<i<<" "<<i+1<<endl;		
		cout<<1<<" "<<i<<" "<<i+1<<endl;
	}
}

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	int Tc = read();
	while(Tc--){
		n = read();
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