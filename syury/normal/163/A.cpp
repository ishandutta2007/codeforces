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

const int MAXN = 5e3 + 3;
const int mod = 1000000007;

string s, t;
int n, m;
int dp[MAXN][MAXN];
int pref[MAXN][MAXN];

void add(int & x, int y){
	x += y;
	if(x >= mod)x -= mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	n = s.length(); m = t.length();
	int ans = 0;
	F(j, 0, m)if(t[j] == s[0])dp[0][j] = 1; else dp[0][j] = 0;
	F(j, 0, m){pref[0][j] = dp[0][j]; if(j > 0)add(pref[0][j], pref[0][j - 1]);}
	add(ans, pref[0][m - 1]);
	F(i, 1, n){
		F(j, 0, m){
			if(s[i] != t[j])cont;
			dp[i][j] = 1;
			if(j > 0)add(dp[i][j], pref[i - 1][j - 1]);
		}
		F(j, 0, m){pref[i][j] = dp[i][j]; if(j > 0)add(pref[i][j], pref[i][j - 1]);}
		add(ans, pref[i][m - 1]);
	}
	cout << ans;
	return 0;
}