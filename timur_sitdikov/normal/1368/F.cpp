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

int dp[MAXN], opt[MAXN];
int used[MAXN];
int cnt[MAXN];
int l[MAXN], r[MAXN], lim[MAXN];
int ind[MAXN];

vi cur;
int n;

void move() {
	int k = SZ(cur);
	printf("%d", k);
	REP(i, 0, k) {
		printf(" %d", cur[i] + 1);
	}
	putchar('\n');
	fflush(stdout);
	int a;
	scanf("%d", &a);
	a--;
	REP(i, 0, k) {
		used[(a + i) % n] = 0;
	}
}

void finish() {
	printf("0\n");
	fflush(stdout);
	exit(0);
}

void solve(){
	REPN(m, 1, 1000) {
		int ans = 0;
		pii mx = {0, 0};
		REPN(i, 1, m - 1) {
			//int cur = m / (i + 1) * i;
			//int cur = (m / (i + 1) - 1) * i;
			int cur = m - (m + i) / (i + 1) - i;
			mx = max(mx, {cur, i});
		}
		dp[m] = mx._1;
		opt[m] = mx._2;
		//printf("%d: %d %d\n", m, mx._1, mx._2 + 1);
	}
	//return;
	cin >> n;
	if (n <= 3) {
		finish();
	}
	
	int step = opt[n];
	int sz = (n + step) / (step + 1);
	REP(i, 0, n) {
		ind[i] = i / (step + 1);
	}
	REP(i, 0, n) {
		if (i == 0 || i > 0 && ind[i] > ind[i - 1]) {
			l[ind[i]] = i;
		}
		if (i == n - 1 || i < n - 1 && ind[i] < ind[i + 1]) {
			r[ind[i]] = i;
		}
		lim[ind[i]]++;
	}
	REP(i, 0, sz) {
		lim[i]--;
	}
	
	/*REP(i, 0, n) {
		printf("%d ", ind[i]);
	}
	return;*/
	
	while(1) {
		REP(i, 0, sz) {
			cnt[i] = 0;
		}
		REP(i, 0, n) {
			cnt[ind[i]] += used[i];
		}
		cur.clear();
		REP(i, 0, step + 1) {
			int mini = -1;
			REP(j, 0, sz) {
				if (cnt[j] < lim[j] && (mini == -1 || cnt[j] < cnt[mini])) {
					mini = j;
				}
			}
			if (mini == -1) {
				break;
			}
			int ind = -1;
			REP(j, l[mini], r[mini]) {
				if (!used[j]) {
					ind = j;
					break;
				}
			}
			if (ind != -1) {
				used[ind] = 1;
				cnt[mini]++;
				cur.pb(ind);
			}
		}
		if (SZ(cur) == 0) {
			break;
		}
		move();
		int sum = 0;
		REP(i, 0, n) {
			sum += used[i];
		}
		if (sum == dp[n]) {
			break;
		}
		
		/*REP(i, 0, n) {
			printf("%d ", used[i]);
		}
		putchar('\n');*/
	}
	finish();
}

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}