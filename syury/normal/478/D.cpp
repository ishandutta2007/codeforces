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
#define tm afhdhn

const int MAXN = 2e5 + 5;
const int mod = 1000000007;

int r, g, h;
int dp[2][MAXN];
int _c = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &r, &g);
	h = 1;
	while(h * (h + 1)/2 <= r + g)h++;
	h--;
	fi0(dp[1]); dp[1][0] = 1;
	F(i, 0, h){
		int tot = (i + 1) * (i + 2)/2;
		F(j, 0, r + 1){
			dp[_c][j] = 0;
			if(tot - j <= g)dp[_c][j] = dp[1 - _c][j];
			if(j - i - 1 >= 0)dp[_c][j] += dp[1 - _c][j - i - 1];
			if(dp[_c][j] >= mod)dp[_c][j] -= mod;
		}
		_c = 1 - _c;
	}
	_c = 1 - _c;
	int ans = 0;
	F(j, 0, r + 1){
		ans += dp[_c][j];
		if(ans > mod)ans -= mod;
	}
	printf("%d", ans);
	ret 0;
}