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

const int MAXN = 2e3 + 3;
const int mod = 1000000007;

lint dp[MAXN][MAXN];
int n, h;
int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &h);
	F(i, 0, n){
		scanf("%d", &a[i]);
		if(a[i] > h){printf("0"); ret 0;}
	}
	fi0(dp);
	dp[0][0] = 1;
	F(i, 0, n){
		F(j, 0, n + 1){
			if(dp[i][j] == 0)cont;
			if(j == h - a[i])dp[i + 1][j] = (dp[i + 1][j] + dp[i][j])%mod;
			if(j != 0 && j == h - a[i])dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j] * j)%mod;
			if(j + 1 == h - a[i])dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j])%mod;
			if(j + 1 == h - a[i])dp[i + 1][j] = (dp[i + 1][j] + dp[i][j])%mod;
			if(j + 1 == h - a[i])dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * j)%mod;
		}
	}
	printf("%lld", dp[n][0]);
	ret 0;
}