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
#define tm afhdhn

const int MAXN = 40;

uli dp[MAXN][MAXN][MAXN];
uli sum[MAXN][MAXN];
int n, h;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h;
	fi0(dp); fi0(sum);
	dp[1][1][1] = 1;
	sum[1][1] = 1;
	sum[0][0] = 1;
	F(i, 2, n + 1){
		F(j, 1, i + 1){
			F(k, 1, i + 1){
				int hl = k - 1;
				//if(hl == 0)cont;
				lint curr = 0ll;
				F(l, 0, hl + 1)curr += sum[i - j][l];
				curr *= sum[j - 1][hl];
				dp[i][j][k] += curr;
				curr = 0ll;
				F(l, 0, hl + 1)curr += sum[j - 1][l];
				curr *= sum[i - j][hl];
				dp[i][j][k] += curr;
				dp[i][j][k] -= sum[j - 1][hl] * sum[i - j][hl];
				sum[i][k] += dp[i][j][k];
			}
		}
	}
	uli ans = 0;
	F(k, h, n + 1)ans += sum[n][k];
	cout << ans;
	ret 0;
}