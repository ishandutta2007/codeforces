#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> point;
typedef double DOUBLE;
#define xx first
#define yy second

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2505;

point pt[MAXN];

ll cross(const point &o, const point &a, const point &b) {
	return (a.xx - o.xx) * (b.yy - o.yy) - (b.xx - o.xx) * (a.yy - o.yy);
}

point pt0;
point pt_sorted[3 * MAXN];

bool cmp(const point &a, const point &b) {
	if (a <= pt0 && pt0 <= b) {
		return true;
	}
	if (b <= pt0 && pt0 <= a) {
		return false;
	}
	return cross(pt0, a, b) > 0;
}

int nxt[3 * MAXN];
ll sum_nxt[3 * MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%lld%lld", &pt[i].xx, &pt[i].yy);
	}
	ll ans = 0ll;
	REP(i, 0, n) {
		pt0 = pt[i];
		int top = 0;
		REP(j, 0, n) {
			if (j != i) {
				pt_sorted[top++] = pt[j];
			}
		}
		sort(pt_sorted, pt_sorted + top, cmp);
		REP(j, top, 3 * top) {
			pt_sorted[j] = pt_sorted[j - top];
		}
		bool on_convex = false;
		REP(j, 0, top) {
			if (cross(pt0, pt_sorted[i], pt_sorted[i + 1]) < 0) {
				on_convex = true;
				break;
			}
		}
		if (on_convex) {
			continue;
		}
		for(int j = 0, k = 1; j < 2 * top; j++) {
			for(; cross(pt0, pt_sorted[j], pt_sorted[k]) > 0; k++);
			nxt[j] = k - 1;
		}
		sum_nxt[0] = nxt[0];
		REP(j, 1, 2 * top) {
			sum_nxt[j] = sum_nxt[j - 1] + nxt[j];
		}
		//cout << "point " << pt[i].xx << " " << pt[i].yy << endl;
		ll cur = 0ll;
		for(int j = 0; j < top; j++) {
			int k = nxt[j];
			cur += (sum_nxt[k] - sum_nxt[j]) - k * (k - j);
			//cout << "add " << (sum_nxt[k] - sum_nxt[j]) - k * (k - j) << endl;
		}
		ans += cur;
		
		/*REP(j, 0, 2 * top) {
			cout << pt_sorted[j].xx << " " << pt_sorted[j].yy << " " << nxt[j] << endl;
		}
		cout << pt[i].xx << " " << pt[i].yy << " " << cur / 3 << endl;*/
	}
	ans /= 3;
	ans *= (n - 4);
	ans /= 2;
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