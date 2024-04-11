#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
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
#define ws wejgnjn
#define left fhgfj

const int mod = 1000000007;
const lint CUT = mod * 1ll * 1e6;
const int MAXN = 319;

lint dp[2][MAXN][MAXN];
int n, m;
int tc = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	if(n > m){printf("0"); ret 0;}
	int x;
	scanf("%d", &x);
	fi0(dp);
	dp[0][0][0] = 1;
	F(i, 1, m + 1){
		F(j, 0, n + 1)
			F(k, 0, j + 1)
				dp[1 - tc][j][k] = 0;
		F(j, 0, n + 1){
			F(k, 0, j + 1){
				if(dp[tc][j][k] == 0)cont;
				if(dp[tc][j][k] >= CUT)dp[tc][j][k] %= mod;
				//while(dp[tc][j][k] >= mod)dp[tc][j][k] -= mod;
				if(i == x){
					dp[1 - tc][j + 1][k + 1] += dp[tc][j][k];
					dp[1 - tc][j + 1][k] += dp[tc][j][k];
					cont;
				}
				dp[1 - tc][j][k] += dp[tc][j][k];
				if(k > 0)dp[1 - tc][j][k - 1] += dp[tc][j][k];
				dp[1 - tc][j + 1][k + 1] += dp[tc][j][k];
				dp[1 - tc][j + 1][k] += dp[tc][j][k];
			}
		}
		tc = 1 - tc;
	}
	lint ans = dp[tc][n][0] % mod;
	F(i, 1, n + 1)ans = (ans * i) % mod;
	printf("%lld", ans);
	ret 0;
}