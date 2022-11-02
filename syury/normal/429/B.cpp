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
#define tm afhdhn

const int MAXN = 1e3 + 10;

int n, m;
int a[MAXN][MAXN];
int dp[2][4][MAXN][MAXN];
int in1[2] = {0, 1};
int in2[2] = {1, 2};
int out1[2] = {2, 3};
int out2[2] = {3, 0};
lint ans = 0ll;

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d%d", &n, &m);
	F(i, 0, n)
		F(j, 0, m)
			scanf("%d", &a[i][j]);
	fi0(dp);
	//F(i, 0, 4)
	//	dp[0][i][0][0] = a[0][0];
	//F(i, 0, 4)
	//	dp[0][i][n - 1][m - 1] = a[0][0];
	F(i, 0, n){
		F(j, 0, m){
			if(i == 0 && j == 0){cont;}
			if(i > 0){
				dp[0][0][i][j] = max(dp[0][0][i - 1][j], dp[0][1][i - 1][j]) + a[i - 1][j];
			}
			if(j > 0){
				dp[0][1][i][j] = max(dp[0][0][i][j - 1], dp[0][1][i][j - 1]) + a[i][j - 1];
			}
		}
	}
	Df(i, n - 1, -1){
		Df(j, m - 1, -1){
			if(i == n - 1 && j == m - 1){cont;}
			if(i < n - 1){
				dp[0][2][i][j] = max(dp[0][2][i + 1][j], dp[0][3][i + 1][j]) + a[i + 1][j];
			}
			if(j < m - 1){
				dp[0][3][i][j] = max(dp[0][3][i][j + 1], dp[0][2][i][j + 1]) + a[i][j + 1];
			}
		}
	}
	Df(i, n - 1, -1){
		F(j, 0, m){
			if(i == n - 1 && j == 0){cont;}
			if(i < n - 1){
				dp[1][2][i][j] = max(dp[1][2][i + 1][j], dp[1][1][i + 1][j]) + a[i + 1][j];
			}
			if(j > 0){
				dp[1][1][i][j] = max(dp[1][2][i][j - 1], dp[1][1][i][j - 1]) + a[i][j - 1];
			}
		}
	}
	F(i, 0, n){
		Df(j, m - 1, -1){
			if(i == 0 && j == m - 1){cont;}
			if(i > 0){
				dp[1][0][i][j] = max(dp[1][0][i - 1][j], dp[1][3][i - 1][j]) + a[i - 1][j];
			}
			if(j < m - 1){
				dp[1][3][i][j] = max(dp[1][3][i][j + 1], dp[1][0][i][j + 1]) + a[i][j + 1];
			}
		}
	}
	F(i, 1, n - 1){
		F(j, 1, m - 1){
			for(auto i1 : in1)
				for(auto i2 : in2){
					if(i1 == i2){cont;}
					if(i1 == 0 && i2 == 2){cont;}
					int o1 = 2;
					if(i2 == 2){o1 = 3;}
					int o2 = 6 - i1 - i2 - o1;
					//printf("For i = %d j = %d ans = %lld\n", i, j,  1ll * dp[0][i1][i][j] + dp[0][o1][i][j] + dp[1][i2][i][j] + dp[1][o2][i][j]);
					ans = max(ans, 1ll * dp[0][i1][i][j] + dp[0][o1][i][j] + dp[1][i2][i][j] + dp[1][o2][i][j]);
				}
		}
	}
	printf("%lld", ans);
	ret 0;
}