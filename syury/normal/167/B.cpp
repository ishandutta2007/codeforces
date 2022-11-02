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

const int MAXN = 205;
const ldb eps = 1e-9;

ldb dp[MAXN][MAXN][MAXN];
int n, l, k;
vector<pair<int, int> > a;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &l, &k); a.rs(n);
	F(i, 0, n)scanf("%d", &a[i].Y);
	F(i, 0, n)scanf("%d", &a[i].X);
	sort(all(a)); reverse(all(a));
	F(j, 0, MAXN)
		F(t, 0, MAXN)
			dp[0][j][t] = 0;
	dp[0][0][k] = 1;
	F(i, 0, n){
		F(j, 0, i + 1){
			F(t, 0, MAXN){
				//dp[i][j][t] = 0;
				//ldb p = a[i - 1].Y/100.0;
				//dp[i][j][t] = dp[i - 1][j][t] * (1 - p);
				//int prv = (a[i - 1].X == -1) ? (t + 1) : (t - a[i - 1].X);
				//if(prv >= MAXN)prv = MAXN - 1;
				//if(prv >= 0 && prv < MAXN && j > 0)dp[i][j][t] += dp[i - 1][j - 1][prv] * p;
				ldb p = a[i].Y/100.0;
				dp[i + 1][j][t] += dp[i][j][t] * (1 - p);
				int nxt = (a[i].X == -1) ? (t - 1) : (t + a[i].X);
				if(nxt >= MAXN)nxt = MAXN - 1;
				if(nxt >= 0)dp[i + 1][j + 1][nxt] += dp[i][j][t] * p;
			}
		}
	}
	ldb ans = 0;
	F(j, l, MAXN)
		F(t, 0, MAXN)ans += dp[n][j][t];
	printf("%.15lf", (double)ans);
	ret 0;
}