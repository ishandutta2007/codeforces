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

const int MAXN = 202;
const int MAXK = 1e3 + 3;
const int mod = 1000000007;

lint dp[2][MAXN][MAXK];
int tc = 0;
int n, k;
int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(dp);
	scanf("%d%d", &n, &k);
	F(i, 0, n)scanf("%d", &a[i]);
	dp[0][0][0] = 1;
	sort(a, a + n);
	F(i, 0, n){
		fi0(dp[1 - tc]);
		F(j, 0, n + 1){
			F(l, 0, k + 1){
				int nl = l + ((i == 0) ? 0 : j * (a[i] - a[i - 1]));
				//printf("For (%d, %d, %d) nl = %d dp = %lld\n", i, j, l, nl, dp[i][j][l]);
				if(nl > k || dp[tc][j][l] == 0)cont;
				//printf("(%d, %d, %d)\n", i, j, l);
				if(j > 0){
					dp[1 - tc][j - 1][nl] += dp[tc][j][l] * j;
					dp[1 - tc][j - 1][nl] %= mod;
				}
				if(j < n){
					dp[1 - tc][j + 1][nl] += dp[tc][j][l];
					dp[1 - tc][j + 1][nl] %= mod;
				}
				if(j > 0){
					dp[1 - tc][j][nl] += dp[tc][j][l] * j;
					dp[1 - tc][j][nl] %= mod;
				}
				dp[1 - tc][j][nl] += dp[tc][j][l];
				dp[1 - tc][j][nl] %= mod;
			}
		}
		tc = 1 - tc;
	}
	lint ans = 0ll;
	F(i, 0, k + 1)ans += dp[tc][0][i];
	printf("%lld", ans%mod);
	ret 0;
}