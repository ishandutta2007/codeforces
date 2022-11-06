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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e6 + 5;

map<int, int> cnt;
map<int, int> cnt_n;

map<int, int> candidates;
set<int> cur;

void solve(){
	int n;
	scanf("%d", &n);
	cnt.clear();
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		cnt[a]++;
	}
	cnt_n.clear();
	FA(it, cnt) {
		cnt_n[it->_2]++;
	}
	//cnt_n[14]++;
	//cnt_n[12]++;
	candidates.clear();
	FA(it, cnt_n) {
		int c = it->_1;
		int l = (int)sqrt(c + 0.5);
		cur.clear();
		REPN(x, 1, l) {
			int p = c / x, q = c % x;
			if (q == 0) {
				cur.insert(x - 1);
			}
			cur.insert(x);
		}
		REPN(p, 1, l) {
			int x = c / p, q = c % p;
			if (q == 0) {
				cur.insert(x - 1);
			}
			cur.insert(x);
		}
		FA(it_cur, cur) {
			candidates[*it_cur]++;
		}
		
		/*FA(it_cur, cur) {
			printf("%d ", *it_cur);
		}
		putchar('\n');*/
	}
	candidates.erase(0);
	int ans_sz = 0;
	FA(it, candidates) {
		if (it->_2 == SZ(cnt_n)) {
			ans_sz = it->_1;
		}
	}
	/*printf("%d\n", SZ(cnt_n));
	FA(it, candidates) {
		printf("%d %d\n", it->_1, it->_2);
	}
	putchar('\n');*/
	int ans_cnt = 0;
	FA(it, cnt_n) {
		int c = it->_1;
		int mul = 0;
		if (c % (ans_sz + 1) == 0) {
			mul = c / (ans_sz + 1);
		} else {
			int p = c / ans_sz, q = c % ans_sz;
			mul = p - (p - q) / (ans_sz + 1);
			//mul = c / ans_sz;
		}
		ans_cnt += mul * it->_2;
		/*int p = c / ans_sz, q = c % ans_sz;
		if (q == 0 && ) {
			ans_cnt += p - 1;
		} else {
			ans_cnt += p;
		}*/
	}
	printf("%d\n", ans_cnt);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();    
    }
}