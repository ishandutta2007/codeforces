#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e2 + 2;
const ll mod = 1000000007;

ll dp[10][MAXN];
ll cnk[2*MAXN][2*MAXN];
int a[10];
int n;

void precalc(){
	F(i, 0, 2*MAXN)
		F(j, 0, 2*MAXN){
			if(j == 0){cnk[i][j] = 1; cont;}
			if(i < j){cnk[i][j] = 0; cont;}
			cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
			cnk[i][j] %= mod;
		}
}

ll C(int i, int j){ret cnk[i][j];}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	precalc();
	cin >> n;
	F(i, 0, 10)cin >> a[i];
	F(j, 0, n + 1)dp[9][j] = (j >= a[9]) ? 1 : 0;
	DF(c, 8, 0){
		F(l, 0, n + 1){
			dp[c][l] = 0;
			F(j, 0, l+1){
				if(j < a[c])cont;
				ll prv = dp[c+1][l-j];
				prv = prv * C(l, j) % mod;
				dp[c][l] += prv;
				dp[c][l] %= mod;
			}
		}
	}
	F(l, 0, n + 1){
		F(j, 0, l+1){
			if(j < a[0])cont;
			ll prv = dp[1][l-j];
			ll coeff = C(l, j);
			if(j == 0){dp[0][l] += prv * coeff % mod; dp[0][l] %= mod; cont;}
			coeff -= C(l-1, j-1);
			coeff = (coeff%mod + mod)%mod;
			dp[0][l] += coeff * prv % mod;
			dp[0][l] %= mod;
		}
	}
	ll ans = 0;
	F(l, 1, n + 1)ans += dp[0][l];
	cout << ans%mod;
	return 0;
}