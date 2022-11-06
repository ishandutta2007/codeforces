#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

ll c[MAXN];
int n;

ll calc(ll mask){
	ll ans = 0ll;
	REP(i, 0, n){
		if (mask & (1ll << i)){
			ans += c[i];
		}
	}
	return ans;
}

void solve(){
	ll L;
	cin >> n >> L;
	REP(i, 0, n){
		cin >> c[i];
	}
	for(int i = n - 1; i > 0; i--){
		c[i - 1] = min(c[i - 1], c[i]);
	}
	REP(i, 1, n){
		c[i] = min(c[i], 2ll * c[i - 1]);
	}
	ll add = 0ll;
	ll d = L / (1ll << (n - 1));
	add += d * c[n - 1];
	L -= d * (1ll << (n - 1));
	ll ans = calc(L);
	REP(i, 0, n){
		if (!(L & (1ll << i))){
			L ^= (1ll << i);
			ans = min(ans, calc(L));
		}
		L ^= (1ll << i);
	}
	ans += add;
	cout << ans << endl;
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}