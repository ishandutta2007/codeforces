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

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e18;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

queue<pair<int, pair<ll, ll> > > qq;

ll ans[MAXN];

void solve(){
	int n, lim, i;
	ll t, d;
	scanf("%d%d", &n, &lim);
	ll cur = 0ll;
	REP(i, 0, n){
		scanf("%lld%lld", &t, &d);
		while(!qq.empty()){
			ll tmp = max(cur, qq.front().second.first) + qq.front().second.second;
			if (tmp <= t){
				ans[qq.front().first] = tmp;
				cur = tmp;
				qq.pop();
			} else {
				break;
			}
		}
		if (SZ(qq) <= lim){
			qq.push(mp(i, mp(t, d)));
		} else {
			ans[i] = -1;
		}
	}
	while(!qq.empty()){
		ll tmp = max(cur, qq.front().second.first) + qq.front().second.second;
		ans[qq.front().first] = tmp;
		cur = tmp;
		qq.pop();
	}
	REP(i, 0, n){
		printf("%lld ", ans[i]);
	}
	putchar('\n');
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