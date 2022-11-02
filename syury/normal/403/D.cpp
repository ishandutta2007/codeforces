#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define uF(i, l, r) for(i = l; i != r; i++)
#define uDf(i, l, r) for(i = l; i != r; i--)
#define I(a, x) for(auto a : x)
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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define tm fjfjfk

const int MAXN = 1e3 + 3;
const int MAXK = 55;
const int mod = 1000000007;

int dp[2][MAXN][MAXN];
int psum[2][MAXN][MAXN];
int prec[MAXK][MAXN];
lint fac[MAXK];
lint C[2 * MAXN][2 * MAXN];

int add(int x, int y){
	x += y;
	if(x >= mod)x -= mod;
	ret x;
}

void precalc(){
	fi0(dp); fi0(prec);
	F(i, 0, MAXN)dp[0][i][i] = 1;
	F(sum, 1, MAXN)F(last, 1, MAXN)psum[0][last][sum] = add((last == 1) ? 0 : psum[0][last - 1][sum], dp[0][last][sum]);
	F(sum, 1, MAXN)prec[1][sum] = psum[0][MAXN - 1][sum];
	int tc = 1;
	F(k, 2, MAXK){
		fi0(dp[tc]); fi0(psum[tc]);
		F(last, 1, MAXN){
			F(sum, 1, MAXN){
				if(last > sum)cont;
				dp[tc][last][sum] = psum[1 - tc][last - 1][sum - last]; 
			}
		}
		F(sum, 1, MAXN)F(last, 1, MAXN)psum[tc][last][sum] = add((last == 1) ? 0 : psum[tc][last - 1][sum], dp[tc][last][sum]);
		F(sum, 1, MAXN)prec[k][sum] = psum[tc][MAXN - 1][sum];
		tc = 1 - tc;
	}
	fac[0] = 1;
	F(i, 1, MAXK)fac[i] = fac[i - 1] * i % mod;
	C[0][0] = 1;
	F(n, 1, 2 * MAXN){
		F(k, 0, 2 * MAXN){
			if(k == 0){C[n][k] = 1; cont;}
			if(k > n){C[n][k] = 0; cont;}
			C[n][k] = add(C[n - 1][k - 1], C[n - 1][k]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	precalc();
	int t;
	scanf("%d", &t);
	F(g, 0, t){
		int n, k;
		scanf("%d%d", &n, &k);
		if(k >= MAXK){printf("0\n"); cont;}
		int ans = 0;
		F(tsum, 1, n + 1){
			int base = prec[k][tsum];
		//	printf("precalc for %d is %d\n", tsum, base);
			base = base * fac[k] % mod;
			int le = n - tsum;
			base = base * C[k + le][le] % mod;
			ans = add(ans, base);
		}
		printf("%d\n", ans);
	}
	ret 0;
}