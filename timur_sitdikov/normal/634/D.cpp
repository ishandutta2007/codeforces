#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int tt[4 * MAXN];
pii pp[MAXN];

void calc(int ind){
	tt[ind] = min(tt[ind << 1], tt[(ind << 1) + 1]);
}

void build(int ind, int tl, int tr){
	if (tl == tr){
		tt[ind] = pp[tl].second;
		// printf("%d %d\n", ind, tt[ind]);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(ind << 1, tl, tm);
	build((ind << 1) + 1, tm + 1, tr);
	calc(ind);
	// printf("%d %d\n", ind, tt[ind]);
}

int get_val(int ind, int tl, int tr, int l, int r){
	// printf("%d %d %d %d %d %d\n", ind, tl, tr, l, r, tt[ind]);
	if (l > r){
		return INF;
	}
	if (tl == l && tr == r){
		return tt[ind];
	}
	int tm = (tl + tr) >> 1;
	return min(get_val(ind << 1, tl, tm, l, min(r, tm)), get_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve(){
	int d, v, n, i;
	scanf("%d%d%d", &d, &v, &n);
	pp[0] = mp(0, 0);
	REPN(i, 1, n){
		scanf("%d%d", &pp[i].first, &pp[i].second);
	}
	pp[n + 1] = mp(d, 0);
	n += 2;	
	sort(pp, pp + n);
	build(1, 0, n - 1);
	ll ans = 0ll;
	int cur_v = v, cur_ind = 0;
	while(cur_ind != n - 1){
		int cur_x = pp[cur_ind].first;
		int cur_p = pp[cur_ind].second;
		int l = cur_ind + 1;
		int r = lower_bound(pp, pp + n, mp(cur_x + v + 1, 0)) - pp - 1;		
		if (r < l){
			cout << -1 << endl;
			return;
		}		
		int mn = get_val(1, 0, n - 1, l, r);
		//cout << "1: " << cur_ind << " " << r << " " << mn << endl;		
		if (mn > cur_p){
			ans += (ll)(v - cur_v) * (ll)cur_p;
			int nxt_x = pp[cur_ind + 1].first;
			cur_v = v - (nxt_x - cur_x);
			cur_ind++;
		} else {
			for(i = cur_ind + 1; pp[i].second > pp[cur_ind].second; i++);
			int nxt_x = pp[i].first;
			if (cur_v < nxt_x - cur_x){
				ans += (ll)(nxt_x - cur_x - cur_v) * (ll)cur_p;
				cur_v = nxt_x - cur_x;
			}
			cur_v -= nxt_x - cur_x;
			cur_ind = i;
		}
		//cout << "2: " << cur_ind << " " << cur_v << endl;
	}
	cout << ans << endl;
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}