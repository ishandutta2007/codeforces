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
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

char s1[MAXN], s2[MAXN];
char v[MAXN];
int cnt[2];
int cur[2];

bool check(char *s) {
	int b = 0;
	for(int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			b++;
		} else {
			b--;
		}
		if (b < 0) {
			return false;
		}
	}
	return b == 0;
}

void solve(){
	int n;
	scanf("%d%s", &n, &v[0]);
	cnt[0] = cnt[1] = 0;
	REP(i, 0, n) {
		cnt[v[i] - '0']++;
	}
	if (cnt[0] % 2 || cnt[1] % 2) {
		printf("NO\n");
		return;
	}
	cur[0] = cur[1] = 0;
	REP(i, 0, n) {
		if (v[i] == '0') {
			if (cur[0] % 2 == 0) {
				s1[i] = '(';
				s2[i] = ')';
			} else {
				s1[i] = ')';
				s2[i] = '(';
			}
			cur[0]++;
		} else {
			if (cur[1] * 2 < cnt[1]) {
				s1[i] = '(';
				s2[i] = '(';
			} else {
				s1[i] = ')';
				s2[i] = ')';
			}
			cur[1]++;
		}
	}
	s1[n] = s2[n] = 0;
	if (!check(s1) || !check(s2)) {
		printf("NO\n");
		return;
	}
	printf("YES\n%s\n%s\n", s1, s2);
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