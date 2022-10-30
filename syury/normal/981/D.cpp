#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg

const int maxn = 55;

int n, k;
bool dp[maxn][maxn];
ll a[maxn];

inline bool can(ll pref){
	dp[0][0] = true;
	F(cnt, 1, n + 1){
		F(sh, 1, k + 1){
			dp[cnt][sh] = false;
			ll sum = 0;
			F(ex, 1, cnt + 1){
				sum += a[cnt - ex];
				if((sum&pref) == pref)dp[cnt][sh] |= dp[cnt - ex][sh - 1];
			}
		}
	}
	return dp[n][k];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	F(i, 0, n)cin >> a[i];
	ll ans = 0;
	DF(bit, 57, 0){
		if(can(ans|(1ll<<bit)))ans |= 1ll<<bit;
	}
	cout << ans;
	return 0;
}