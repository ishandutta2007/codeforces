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

const int mod = 100000000;
const int MAXN = 101;
const int MAXK = 11;

int dp0[MAXN][MAXN][MAXK], dp1[MAXN][MAXN][MAXK];
int sum0[MAXN][MAXN], sum1[MAXN][MAXN];
int n0, n1, k0, k1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(dp0); fi0(dp1); fi0(sum0); fi0(sum1);
	scanf("%d%d%d%d", &n0, &n1, &k0, &k1);
	dp0[0][0][0] = dp1[0][0][0] = 1;
	sum0[0][0] = sum1[0][0] = 1;
	F(i, 0, n0 + 1){
		F(j, 0, n1 + 1){
			F(k, 1, max(k0, k1) + 1){
				if(i == 0 && j == 0)
					cont;
				if(k <= k0){
					int _p = i - k;
					if(_p >= 0){
						dp0[i][j][k] = sum1[_p][j];
					}
				}
				if(k <= k1){
					int _p = j - k;
					if(_p >= 0){
						dp1[i][j][k] = sum0[i][_p];
					}
				}
				sum0[i][j] += dp0[i][j][k];
				sum1[i][j] += dp1[i][j][k];
				sum0[i][j] %= mod; sum1[i][j] %= mod;
			}
		}
	}
	printf("%d", (sum0[n0][n1] += sum1[n0][n1]) % mod);
	ret 0;
}