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

int v[MAXN];
int cnt[MAXN];
int offset;

vi goods;
int is_good[MAXN];

void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	REPN(i, 1, n) {
		int a;
		scanf("%d", &a);
		//printf("%d\n", a);
		v[i] = a;
		if (a < 0) {
			offset++;
			cnt[-a]--;
		} else {
			cnt[a]++;
		}
	}
	REPN(i, 1, n) {
		if (cnt[i] + offset == m) {
			goods.pb(i);
			is_good[i] = 1;
		}
	}
	if (SZ(goods) == 1) {
		int a = goods[0];
		REPN(i, 1, n) {
			if (v[i] == a || v[i] < 0 && v[i] != -a) {
				printf("Truth\n");
			} else {
				printf("Lie\n");
			}
		}
	} else {
		REPN(i, 1, n) {
			if (!is_good[abs(v[i])]) {
				if (v[i] < 0) {
					printf("Truth\n");
				} else {
					printf("Lie\n");
				}
			} else {
				printf("Not defined\n");
			}
		}
	}
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