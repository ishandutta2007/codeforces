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

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll INF = 1e18;
const int MAXN = 2e5 + 105;
const ll MOD = 1e9 + 7;

vector<string> v[200];
string c, c1;

set<string> st[2];

void solve(){
	int n, q, i, j;
	scanf("%d%d", &n, &q);
	REP(i, 0, q){
		cin >> c >> c1;
		v[c1[0]].pb(c);
	}
	st[0].insert("a");
	REP(i, 1, n){
		st[i & 1].clear();
		FA(it, st[(i & 1) ^ 1]){
			string tmps = *it;
			char tmpc = tmps[0];
			REP(j, 0, SZ(v[tmpc])){
				string tmps1 = v[tmpc][j] + tmps.substr(1, tmps.length() - 1);
				st[i & 1].insert(tmps1);
			}
		}
	}
	/*FA(it, st[(n & 1) ^ 1]){
		cout << *it << endl;
	}*/
	cout << SZ(st[(n & 1) ^ 1]) << endl;
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