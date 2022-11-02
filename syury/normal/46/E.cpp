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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm dhgdg

const int MAXN = 2e3 + 3;
const lint inf = 1e18;

lint dp[2][MAXN];
int sum[MAXN][MAXN];
lint pref[2][MAXN];
int n, m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, n){
		F(j, 0, m){
			scanf("%d", &sum[i][j]);
			if(j > 0)sum[i][j] += sum[i][j - 1];
		}
	}
	F(j, 0, m + 2)pref[0][j] = 0;
	int tc = 1;
	F(i, 0, n){
		dp[tc][0] = -inf;
		dp[tc][m + 1] = -inf;
		F(j, 1, m + 1){
			int add = sum[i][j - 1];
			dp[tc][j] = add + ((tc == 1) ? pref[1 - tc][j - 1] : pref[1 - tc][j + 1]);
		}
		if(tc == 1){
			pref[tc][m + 1] = -inf;
			Df(j, m, 0)pref[tc][j] = max(dp[tc][j], pref[tc][j + 1]);
		}
		else{
			pref[tc][0] = -inf;
			F(j, 1, m + 1)pref[tc][j] = max(dp[tc][j], pref[tc][j - 1]);
		}
		tc = 1 - tc;
	}
	tc = 1 - tc;
	lint ans = -inf;
	F(j, 1, m + 1)ans = max(ans, dp[tc][j]);
	printf("%lld", ans);
	ret 0;
}