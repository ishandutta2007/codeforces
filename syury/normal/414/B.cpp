#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
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
#define y1 adjf

const int mod = 1000000007;
const int MAXN = 2007;

int n, k;
int dp[MAXN][MAXN];

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	F(i, 1, n + 1)
		dp[0][i] = 1;
	F(i, 0, k - 1){
		F(j, 1, n + 1){
			for(int d = j; d <= n; d += j){
				dp[i + 1][d] += dp[i][j];
				if(dp[i + 1][d] > mod){dp[i + 1][d] -= mod;}
			}
		}
	}
	lint tot = 0ll;
	F(i, 1, n + 1)
		tot += dp[k - 1][i];
	tot %= mod;
	printf("%lld", tot);
	ret 0;
}