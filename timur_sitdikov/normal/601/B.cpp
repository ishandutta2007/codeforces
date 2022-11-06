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
#define REPN(i, a, b) for((i) = (a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5, MAXLOG = 17;
const ll MOD = 1e9 + 7;

int a[MAXN], h[MAXN], dif_ind[MAXN];
pii tt[MAXN][MAXLOG];

void build(int n){
	int i, j, st2;
	REP(i, 0, n){
		tt[i][0] = mp(a[i], i);
	}
	for(j = 1, st2 = 2; j < MAXLOG; j++, st2 <<= 1){
		int offset = st2 >> 1;
		for(i = st2; i < min(MAXN, (st2 << 1)); i++){
			dif_ind[i] = j;
		}
		for(i = 0; i < n; i++){
			tt[i][j] = max(tt[i][j - 1], tt[min(i + offset, n - 1)][j - 1]);
		}
	}
}

pii get_val(int l, int r){
	int ind = dif_ind[r - l];
	return max(tt[l][ind], tt[r - (1 << ind) + 1][ind]);
}

ll req_sol(int n, int l, int r){
	if (l > r){
		return 0ll;
	}
	pii pp = get_val(l, r);
	int mid = pp.second;
	ll v0 = (ll)pp.first * (ll)(mid - l + 1) * (ll)(r - mid + 1);
	ll v1 = req_sol(n, l, mid - 1);
	ll v2 = req_sol(n, mid + 1, r);
	// cout << l << " " << r << " " << v0 + v1 + v2 << endl;
	return v0 + v1 + v2;
}

void solve(){
	int n, i, j, q, l, r;
	scanf("%d%d", &n, &q);
	REP(i, 0, n){
		scanf("%d", &h[i]);
		if (i){
			a[i - 1] = abs(h[i] - h[i - 1]);
		}
	}
	n--;
	build(n);
	/*REP(i, 0, n){
		REP(j, 0, MAXLOG){
			printf("%d ", tt[i][j].first);
		}
		putchar('\n');
	}*/
	/*printf("#\n");
	return;*/
	REP(i, 0, q){
		scanf("%d%d", &l, &r);
		ll ans = req_sol(n, l - 1, r - 2);
		printf("%lld\n", ans);
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