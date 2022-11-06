#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

map<int, int> cnt;

void dec_cnt(int v) {
	cnt[v]--;
	if (cnt[v] == 0) {
		cnt.erase(v);
	}
}

void solve(){
	int n;
	scanf("%d", &n);
	if (n & 1) {
		printf("NO\n");
		return;
	}
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	int l = cnt.begin()->_1;
	int r = l;
	dec_cnt(l);
	int a[4];
	while(1) {
		if (cnt.empty()) {
			break;
		}
		a[0] = l - 1;
		a[1] = l + 1;
		a[2] = r - 1;
		a[3] = r + 1;
		sort(a, a + 4);
		int fl = 0;
		REP(i, 0, 4) {
			if (cnt.find(a[i]) != cnt.end()) {
				dec_cnt(a[i]);
				if (a[i] == l - 1) {
					l = a[i];
				} else if (a[i] == r - 1) {
					r = a[i];
				} else if (a[i] == l + 1) {
					l = a[i];
				} else {
					r = a[i];
				}
				if (l > r) {
					swap(l, r);
				}
				fl = 1;
				break;
			}
		}
		if (!fl) {
			printf("NO\n");
			return;
		}
		if (r - l >= 2) {
			printf("NO\n");
			return;
		}
	}
	if (l + 1 != r) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
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