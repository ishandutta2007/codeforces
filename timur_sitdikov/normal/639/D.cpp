#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
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
const ll LIM = 2e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

ll vals[5][MAXN];
int top_vals[5];

int all_vals[5 * MAXN];

// set<int> st;
map<ll, int> cost;

ll coord[MAXN];

ll b, c;
int n, k;

ll get_cost(ll from, ll to){
	return ((to - from) / 5ll) * min(b, 5ll * c) + ((to - from) % 5ll) * c;
}

void solve(){
	int i, j, ind, tt;
	cin >> n >> k >> b >> c;
	REP(i, 0, n){
		scanf("%d", &tt);
		coord[i] = (ll)tt;
		REP(j, 0, 5){
			//st.insert(tt + j);
			all_vals[5 * i + j] = tt + j;
		}
	}	
	/*FA(it, st){
		tt = *it;
		ind = tt % 5;
		if (ind < 0){
			ind += 5;
		}
		vals[ind][top_vals[ind]++] = tt;
	}*/
	sort(all_vals, all_vals + 5 * n);
	REP(i, 0, 5 * n){
		if (i == 0 || all_vals[i] > all_vals[i - 1]){
			tt = all_vals[i];
			ind = tt % 5;
			if (ind < 0){
				ind += 5;
			}
			vals[ind][top_vals[ind]++] = tt;
		}
	}
	sort(coord, coord + n);
	ll ans = INF;
	REP(j, 0, 5){
		cost.clear();
		ll last = -LIM + j, to = LIM + j, cur_ans = 0ll;
		int r = 0, cnt = 0;
		REP(i, 0, top_vals[j]){
			ll cur = vals[j][i];
			for(; r < n && coord[r] <= cur; r++){
				ll cur_cost = get_cost(coord[r], to);
				cur_ans += cur_cost;
				cost[-cur_cost]++;
				cnt++;
			}
			for(; cnt > k; ){
				ll cur_cost = -(cost.begin()->first);
				cur_ans -= cur_cost;
				cost[-cur_cost]--;
				if (cost[-cur_cost] == 0){
					cost.erase(cost.begin());
				}
				cnt--;
			}
			ll tmp = cur_ans - (ll)k * get_cost(cur, to);
			// cout << j << " " << i << " " << vals[j][i] << " " << r << " " << tmp << endl;
			if (cnt == k){
				ans = min(ans, tmp);
			}
		}
	}
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