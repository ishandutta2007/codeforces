#include<bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long int ll;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define DF(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
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

const int MAXN = 3e2 + 2;
const int inf = 1e9;

int dp[2][MAXN][MAXN];
int a[MAXN][MAXN];
int dpos[MAXN][MAXN];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	F(i, 0, n)F(j, 0, n)cin >> a[i][j];
	F(i, 0, n)
		F(j, 0, n){
			int x = i, y = j;
			dpos[i][j] = -1;
			while(x < n && y >= 0){
				dpos[i][j]++;
				x++; y--;
			}
//			cout << i << " " << j << " " << dpos[i][j] << endl;
		}
	int tc = 0;
	dp[1][0][0] = a[0][0];
	F(d, 1, 2*n - 1){
		int len = (d <= (2*n-2)/2) ? (d + 1) : (2*n - 2 - d + 1);
		F(l, 0, len){
			F(r, 0, len){
				if(l > r)cont;
				int xl, yl, xr, yr;
				xl = (d <= (2*n-2)/2) ? d : (n-1);
				xr = (d <= (2*n-2)/2) ? d : (n-1);
				xl -= l; xr -= r;
				yl = l; yr = r;
				if(d > (2*n-2)/2){yl += d-(2*n-2)/2; yr += d-(2*n-2)/2;}
//				cout << d << " Elements " << l << " " << r << " coords " << xl << " " << yl << " " << xr << " " << yr << endl;
				if(l == r){
					dp[tc][l][r] = a[xl][yl] + max(max(((yl == 0) ? -inf : dp[1 - tc][dpos[xl][yl-1]][dpos[xl][yl-1]]), ((xl==0) ? -inf : dp[1 - tc][dpos[xl-1][yl]][dpos[xl-1][yl]])), max(-inf,((yl==0||xl==0) ? -inf : (dp[1 - tc][dpos[xl][yl-1]][dpos[xl-1][yl]]))));
					cont;
				}
				dp[tc][l][r] = -inf;
				if(xl > 0 && xr > 0)dp[tc][l][r] = max(dp[tc][l][r], a[xl][yl]+a[xr][yr]+dp[1-tc][dpos[xl-1][yl]][dpos[xr-1][yr]]);
				if(xl > 0 && yr > 0)dp[tc][l][r] = max(dp[tc][l][r], a[xl][yl]+a[xr][yr]+dp[1-tc][dpos[xl-1][yl]][dpos[xr][yr-1]]);
				if(yl > 0 && yr > 0)dp[tc][l][r] = max(dp[tc][l][r], a[xl][yl]+a[xr][yr]+dp[1-tc][dpos[xl][yl-1]][dpos[xr][yr-1]]);
				if(yl > 0 && xr > 0)dp[tc][l][r] = max(dp[tc][l][r], a[xl][yl]+a[xr][yr]+dp[1-tc][dpos[xl][yl-1]][dpos[xr-1][yr]]);
			}
		}
		tc = 1 - tc;
	}
	tc = 1 - tc;
	cout << dp[tc][0][0];
	return 0;
}