#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
typedef complex<double> point;
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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
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
// const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

int v[MAXN];
int tail[MAXN], neigh[MAXN], nxt[MAXN];
vi ans;

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
		tail[i] = i;
		neigh[i] = -1;
		nxt[i] = (i + 1) % n;
	}
	ans.clear();
	int cur = 0;
	for(; ; ) {
		if (nxt[cur] == cur) {
			break;
		}
		if (gcd(v[tail[cur]], v[nxt[cur]]) != 1) {
			neigh[tail[cur]] = nxt[cur];
			tail[cur] = tail[nxt[cur]];
			nxt[cur] = nxt[nxt[cur]];
		} else {
			ans.pb(nxt[cur]);
			if (neigh[nxt[cur]] != -1) {
				tail[neigh[nxt[cur]]] = tail[nxt[cur]];
				nxt[neigh[nxt[cur]]] = nxt[nxt[cur]];
				nxt[cur] = neigh[nxt[cur]];
			} else {
				nxt[cur] = nxt[nxt[cur]];
			}
			cur = nxt[cur];
		}
		/*printf("%d\n", cur);
		REP(j, 0, n) {
			printf("%d ", neigh[j]);
		}
		putchar('\n');
		REP(j, 0, n) {
			printf("%d ", tail[j]);
		}
		putchar('\n');
		REP(j, 0, n) {
			printf("%d ", nxt[j]);
		}
		putchar('\n');*/
	}
	while(cur != tail[cur] && gcd(v[cur], v[tail[cur]]) == 1) {
		ans.pb(cur);
		tail[neigh[cur]] = tail[cur];
		cur = neigh[cur];
	}
	if (v[cur] == 1) {
		ans.pb(cur);
	}
	printf("%d", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf(" %d", ans[i] + 1);
	}
	putchar('\n');
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