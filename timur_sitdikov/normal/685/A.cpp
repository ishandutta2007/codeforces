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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

int p[MAXN];

set<pii> ans;

int get_num(int l, int r){
	int ans = 0;
	REP(i, l, r){
		ans = ans * 7 + p[i];
	}
	return ans;
}

int get_cnt_dig(int n){
	int ans = 0;
	for(; n; n /= 7, ans++);
	return max(ans, 1);
}

void solve(){
	int n, m, cn, cm;
	cin >> n >> m;
	cn = get_cnt_dig(n - 1);
	cm = get_cnt_dig(m - 1);
	if (cn + cm > 7){
		cout << 0 << endl;
		return;
	}
	int f = 1 * 2* 3 * 4 * 5 * 6 * 7;
	REP(i, 0, 7){
		p[i] = i;
	}
	REP(i, 0, f){
		int tmpn = get_num(0, cn);
		int tmpm = get_num(cn, cn + cm);
		if (tmpn < n && tmpm < m){
			ans.insert(mp(tmpn, tmpm));
		}
		next_permutation(p, p + 7);
	}
	cout << SZ(ans) << endl;
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