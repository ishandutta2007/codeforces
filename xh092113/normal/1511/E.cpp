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

const ll mod = 998244353;
const int N = 3e5;

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

In void chkmin(ll &x,ll y){if(x < y)x = y;}
In void chkmax(ll &x,ll y){if(x > y)x = y;}

namespace ModCalc{
	In void Inc(ll &x,ll y){x += y;if(x >= mod)x -= mod;}
	In void Dec(ll &x,ll y){x -= y;if(x < 0)x += mod;}
	In ll Add(ll x,ll y){Inc(x,y);return x;}
	In ll Sub(ll x,ll y){Dec(x,y);return x;}
};
using namespace ModCalc;

char st[N+5];
vector<int> A[N+5],B[N+5];
ll f[N+5][2],s[N+5][2];
ll n,m;

In ll power(ll a,ll n){
	ll s = 1,x = a;
	while(n){
		if(n & 1)s = x * s % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return s;
}
ll solve(){
/*cout<<"n="<<n<<" m="<<m<<endl;
rep(i,1,n){
	rep(j,1,m)cout<<A[i][j]<<" ";cout<<endl;
}*/
	ll wn = 0,curwn = 0; 
	rep(i,1,n)rep(j,1,m)wn += A[i][j];
	ll ans = 0;
	rep(i,1,n){
		rep(j,0,m)f[j][0] = f[j][1] = s[j][0] = s[j][1] = 0;
		s[0][0] = 1;
		rep(j,1,m){
			if(!A[i][j]){ // calc f
				f[j][0] = Add(f[j-1][0],f[j-1][1]);
				f[j][1] = 0;
			}
			else{
				f[j][0] = Add(f[j-1][0],Add(f[j-1][1]*2%mod,s[j-1][1]));
				f[j][1] = f[j-1][0];
			}
			if(!A[i][j]){ // calc s
				s[j][0] = Add(s[j-1][0],s[j-1][1]);
				s[j][1] = 0;
			}
			else{
				s[j][0] = Add(s[j-1][0],s[j-1][1] * 2 % mod);
				s[j][1] = s[j-1][0];
			}
		}
		curwn = 0;rep(j,1,m)curwn += A[i][j];
		ll cur = Add(f[m][0],f[m][1]) * power(2,wn - curwn) % mod;
		Inc(ans,cur);
	}
	return ans;
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
// MEMORY LIMIT
// USe LONG LONG
// Enough ARRAY SIZE
	n = read(),m = read();
	rep(i,1,n)A[i].resize(m + 1);
	rep(j,1,m)B[j].resize(n + 1);
	rep(i,1,n){
		scanf("%s",st + 1);
		rep(j,1,m){
			A[i][j] = st[j] == 'o' ? 1 : 0;
			B[j][i] = A[i][j];
		}
	}
	ll ans = solve();
	rep(i,1,m){
		A[i].resize(n + 1);
		rep(j,1,n)A[i][j] = B[i][j];
	}
	swap(n,m);
	Inc(ans,solve());
	write(ans),putchar('\n');
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