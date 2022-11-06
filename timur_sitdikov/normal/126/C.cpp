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

const int MAXN = 2e3 + 5;

char c[MAXN][MAXN];

int g1[MAXN], v1[MAXN], g2[MAXN], v2[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%s", &c[i][0]);
	}
	int ans = 0;
	for(int d = n - 1; d >= 1; d--) {
		REP(i, 0, n) {
			int j = i + d;
			if (j < n) {
				int val = (c[i][j] ^ '0' ^ g1[i] ^ v1[j]);
				if (val) {
					//printf("%d %d\n", i, j);
					ans++;
					g1[i] ^= 1;
					v1[j] ^= 1;
				}
			}
		}
		REP(j, 0, n) {
			int i = j + d;
			if (i < n) {
				int val = (c[i][j] ^ '0' ^ g2[i] ^ v2[j]);
				if (val) {
					//printf("%d %d\n", i, j);
					ans++;
					g2[i] ^= 1;
					v2[j] ^= 1;
				}
			}
		}
	}
	REP(i, 0, n) {
		int val = (c[i][i] ^ '0' ^ g1[i] ^ v1[i] ^ g2[i] ^ v2[i]);
		if (val) {
			//printf("%d %d\n", i, i);
			ans++;
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