#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define checkF(i, l, r) for(int i = l; i < r; i++)
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

const int MAXN = 1<<6;
const ldb eps = 1e-10;

int n, h;
ldb dp[MAXN][10];
ldb pr[MAXN][10];
ldb p[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &h);
	n = 1<<h;
	F(i, 0, n){
		F(j, 0, n){
			int dcp;
			scanf("%d", &dcp);
			p[i][j] = dcp/100.0;
		}
	}
	F(i, 0, n){
		pr[i][0] = p[i][i^1];
		dp[i][0] = p[i][i^1];
	}
	int w = 1;
	F(j, 1, h){
		w <<= 1;
		F(i, 0, n){
			dp[i][j] = dp[i][j - 1];
			ldb delta = 0;
			pr[i][j] = 0;
			F(k, 0, n){
				if((k>>(j+1)) != (i>>(j+1)))cont;
				if((k>>j)==(i>>j))cont;
				if(delta - dp[k][j - 1] < -eps)delta = dp[k][j - 1];
				pr[i][j] += pr[k][j - 1] * p[i][k];
			}
			pr[i][j] *= pr[i][j - 1];
			dp[i][j] += delta + pr[i][j] * w;;
		}
	}
	ldb ans = 0;
	F(i, 0, n)if(dp[i][h - 1] - ans > eps)ans = dp[i][h - 1];
	printf("%.15lf", (double)ans);
	ret 0;
}