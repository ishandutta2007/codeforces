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

int tta[4 * MAXN], ttb[4 * MAXN], a, b;

void calc(int ind){
	tta[ind] = tta[ind << 1] + tta[(ind << 1) + 1];
	ttb[ind] = ttb[ind << 1] + ttb[(ind << 1) + 1];
}

int get_val(int ind, int tl, int tr, int l, int r, int t){
	if (l > r){
		return 0;
	}
	if (l == tl && r == tr){
		if (t == 1){
			return tta[ind];
		} else {
			return ttb[ind];
		}
	}
	int tm = (tl + tr) >> 1;
	return get_val(ind << 1, tl, tm, l, min(r, tm), t) + get_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r, t);
}

void upd_val(int ind, int tl, int tr, int pos, int val){
	if (tl == tr){
		tta[ind] = min(tta[ind] + val, a);
		ttb[ind] = min(ttb[ind] + val, b);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm){
		upd_val(ind << 1, tl, tm, pos, val);
	} else {
		upd_val((ind << 1) + 1, tm + 1, tr, pos, val);
	}
	calc(ind);
}


void solve(){
	int n, k, q, t, d, aa, p;
	scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
	while(q--){
		scanf("%d", &t);
		if (t == 1){
			scanf("%d%d", &d, &aa);
			upd_val(1, 0, n - 1, d - 1, aa);
		} else {
			scanf("%d", &p);
			int ans = get_val(1, 0, n - 1, 0, p - 2, 2) + get_val(1, 0, n - 1, p + k - 1, n - 1, 1);
			printf("%d\n", ans);
		}
	}
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}