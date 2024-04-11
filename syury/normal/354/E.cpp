#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double dbl;

map<pii, vector<int> > can_get;
int pp[3] = {0, 4, 7};
int kek[6];
int num[20];
bool dp[20][20];
pii curr[20][20];
int car[20][20];
int len;
ll n;

void solve(int i, int sum){
	if(i == 6){
		int l = sum/10, r = sum%10;
		if(can_get.count(mp(l, r)))ret;
		can_get[mp(l, r)] = {kek[0], kek[1], kek[2], kek[3], kek[4], kek[5]};
		ret;
	}
	F(j, 0, 3){
		kek[i] = pp[j];
		solve(i + 1, sum + pp[j]);
	}
}

void calc(int pos, int carry){
	if(curr[pos][carry].X != -1)ret;
	if(pos == len - 1){
		curr[pos][carry] = {0, 0};
		for(auto&x : can_get){
			if(x.X.X == carry && x.X.Y == num[pos]){
				dp[pos][carry] = true;
				curr[pos][carry] = x.X;
			}
		}
		ret;
	}
	curr[pos][carry] = {0, 0};
	F(prv, 0, 20){
		calc(pos + 1, prv);
		if(!dp[pos + 1][prv])cont;
		for(auto&x : can_get){
			int l = x.X.X, r = x.X.Y;
			r = r + prv;
			l += r/10;
			r %= 10;
			if(r == num[pos] && l == carry){
				dp[pos][carry] = true;
				car[pos][carry] = prv;
				curr[pos][carry] = x.X;
			}
		}
	}
}

signed main(){
	sync;
	solve(0, 0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		len = 0;
		while(n){
			num[len++] = n%10;
			n /= 10;
		}
		F(i, 0, 20)F(j, 0, 20){dp[i][j] = false; curr[i][j] = {-1, -1};}
		reverse(num, num + len);
		calc(0, 0);
		if(!dp[0][0]){cout << -1 << '\n'; cont;}
		vector<ll> ans(6);
		int cc = 0;
		F(i, 0, len){
			pii v = curr[i][cc];
			auto& vv = can_get[v];
			F(j, 0, 6)ans[j] = ans[j] * 10 + vv[j];
			cc = car[i][cc];
		}
		F(j, 0, 6)cout << ans[j] << ' ';
		cout << '\n';
	}
	ret 0;
}