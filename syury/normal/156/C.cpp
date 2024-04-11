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
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

const int mod = 1000000007;

int dp[103][2800];
int t;
string s;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fi0(dp);
	dp[0][0] = 1;
	F(i, 1, 101){
		F(sum, 0, 2800){
			F(c, 'a', 'z' + 1){
				int d = c - 'a';
				if(sum < d)cont;
				dp[i][sum] += dp[i - 1][sum - d];
				if(dp[i][sum] >= mod)dp[i][sum] -= mod;
			}
		}
	}
	cin >> t;
	F(g, 0, t){
		cin >> s;
		int sum = 0;
		I(c, s)sum += c - 'a';
		cout << (dp[(int)s.length()][sum] - 1 + mod)%mod << "\n";
	}
	ret 0;
}