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

const int MAXN = 18;

ldb dp[1 << MAXN];
int n;
ldb a[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d", &n);
	fi0(dp);
	double tmp;
	F(i, 0, n){
		F(j, 0, n){
			scanf("%lf", &tmp);
			a[i][j] = tmp;
		}
	}
	dp[(1 << n) - 1] = 1;
	Df(mask, (1 << n) - 1, -1){
		if(__builtin_popcount(mask) == 1)cont;
		int cnt = __builtin_popcount(mask);
		ldb p = 1.0/(cnt * (cnt - 1)/2);
		F(i, 0, n){
			F(j, i + 1, n){
				if(!(mask&(1 << i)))brk;
				if(!(mask&(1 << j)))cont;
				dp[mask^(1 << i)] += dp[mask] * p * a[j][i];
				dp[mask^(1 << j)] += dp[mask] * p * a[i][j];
			}
		}
	}
	F(i, 0, n){
		printf("%.15lf ", (double)dp[1 << i]);
	}
	ret 0;
}