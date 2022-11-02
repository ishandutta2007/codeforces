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
#define tm dhgdg

const int MAXN = 5e3 + 3;
const int mod = 1000000007;

int dp[2][MAXN];
int psum[2][MAXN];
int n, k;
int a, b;

int get(int w, int l, int r){
	if(r < l)ret 0;
	if(l == 0)ret psum[w][r];
	int crr = psum[w][r] - psum[w][l - 1];
	while(crr < 0)crr += mod;
	while(crr >= mod)crr -= mod;
	ret crr;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d%d", &n, &a, &b, &k); a--; b--;
	int tc = 1;
	fi0(dp); fi0(psum);
	dp[0][a] = 1;	
	F(i, 0, n)if(a > i)psum[0][i] = 0; else psum[0][i] = 1;
	F(i, 0, k){
		fi0(dp[tc]);
		F(j, 0, n){
			if(j == b){if(b != 0)psum[tc][j] = psum[tc][j - 1]; else psum[tc][j] = 0; cont;}
			int l, r;
			if(j > b){r = n - 1; l = (j + b)/2 + 1;}
			else{l = 0; r = (j + b)/2 - 1; if((j + b)&1)r++;}
			//printf("For j = %d l = %d r = %d\n", j, l, r);
			dp[tc][j] = get(1 - tc, l, r) - dp[1 - tc][j];
			if(dp[tc][j] < 0)dp[tc][j] += mod;
			psum[tc][j] = ((j == 0) ? 0 : psum[tc][j - 1]) + dp[tc][j];
			if(psum[tc][j] >= mod)psum[tc][j] -= mod;
		}
		tc = 1 - tc;
	}
	printf("%d", psum[1 - tc][n - 1]);
	ret 0;
}