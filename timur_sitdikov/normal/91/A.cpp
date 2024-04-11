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

const int MAXN = 1e6 + 5;

vi pos[200];

char s[MAXN], t[MAXN];

void solve(){
	scanf("%s%s", &s[0], &t[0]);
	int n = strlen(s);
	REP(i, 0, n) {
		pos[s[i]].pb(i);
	}
	int ans = 1;
	int cur = 0;
	for(int i = 0; t[i]; i++) {
		char c = t[i];
		if (pos[c].empty()) {
			printf("-1\n");
			return;
		}
		int ind = lower_bound(pos[c].begin(), pos[c].end(), cur) - pos[c].begin();
		if (ind == SZ(pos[c])) {
			ans++;
			cur = pos[c][0] + 1;
		} else {
			cur = pos[c][ind] + 1;
		}
	}
	printf("%d\n", ans);
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