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

lint dp[23][12][12][6][6];

int n, t;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d", &n, &t);
	fi0(dp);
	F(i, 1, 5)
		F(j, 1, 5)
			if(i!=j)dp[2][0][0][i][j] = 1;
	F(i, 2, n){
		F(u, 0, t + 1){
			F(d, 0, t){
				F(pl, 1, 5){
					F(l, 1, 5){
						if(dp[i][u][d][pl][l] == 0)cont;
						F(nxt, 1, 5){
							if(l == nxt)cont;
							int nu = u, nd = d;
							if(l < pl && l < nxt)nd++;
							if(l > pl && l > nxt)nu++;
							dp[i + 1][nu][nd][l][nxt] += dp[i][u][d][pl][l];
						}
					}
				}
			}
		}
	}
	lint ans = 0ll;
	F(i, 1, 5)
		F(j, 1, 5)
			if(i!=j)ans += dp[n][t][t - 1][i][j];
	printf("%lld", ans);
	ret 0;
}