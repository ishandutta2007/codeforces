#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
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

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

char s[MAXN], t[MAXN];

void solve(){
	int n, m;
	scanf("%d%d%s%s", &n, &m, &s[0], &t[0]);
	if (n > m + 1) {
		printf("NO\n");
		return;
	}
	int ind = -1;
	REP(i, 0, n) {
		if (s[i] == '*') {
			ind = i;
			break;
		}
		else if (s[i] != t[i]) {
			printf("NO\n");
			return;
		}
	}
	if (ind == -1 && n != m) {
		printf("NO\n");
		return;
	}
	for(int i = n - 1, j = m - 1; i > ind; i--, j--) {
		if (s[i] != t[j]) {
			printf("NO\n");
			return;
		}
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