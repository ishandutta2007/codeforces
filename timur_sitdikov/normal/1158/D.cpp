#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ll> point;
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
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e3 + 5;

point pt[MAXN];

int used[MAXN];

char s[MAXN];

ll cross(point &o, point &a, point &b) {
	return imag(conj(a - o) * (b - o));
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		pt[i] = point(x, y);
	}
	scanf("%s", &s[0]);
	int ind = 0;
	REP(i, 1, n) {
		if (pt[i].xx < pt[ind].xx || pt[i].xx == pt[ind].xx && pt[i].yy < pt[ind].yy) {
			ind = i;
		}
	}
	REP(i, 0, n) {
		printf("%d ", ind + 1);
		used[ind] = 1;
		int mini = -1;
		REP(j, 0, n) {
			if (used[j]) {
				continue;
			}
			if (mini == -1) {
				mini = j;
				continue;
			}
			ll v = cross(pt[ind], pt[mini], pt[j]);
			if (s[i] == 'L' && v < 0) {
				mini = j;
			} else if (s[i] == 'R' && v > 0) {
				mini = j;
			}
		}
		ind = mini;
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