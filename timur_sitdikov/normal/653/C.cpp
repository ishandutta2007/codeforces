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

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int n;
int v[MAXN];
vi inds;

set<pii> st;

bool check(int a, int b){
	vi tmpv = inds;
	tmpv.pb(a);
	tmpv.pb(b);
	int i;
	swap(v[a], v[b]);
	bool ans = true;
	REP(i, 0, SZ(tmpv)){
		int ind = tmpv[i];
		if (ind & 1){
			if (ind > 1 && v[ind - 1] <= v[ind]){
				ans = false;
			}
			if (ind < n && v[ind] >= v[ind + 1]){
				ans = false;
			}
		}
		if (!(ind & 1)){
			if (ind > 1 && v[ind - 1] >= v[ind]){
				ans = false;
			}
			if (ind < n && v[ind] <= v[ind + 1]){
				ans = false;
			}
		}
	}
	swap(v[a], v[b]);
	return ans;
}

void solve(){
	int i, j;
	scanf("%d", &n);
	REPN(i, 1, n){
		scanf("%d", &v[i]);
	}
	REP(i, 1, n){
		if ((i & 1) && v[i] >= v[i + 1] || !(i & 1) && v[i] <= v[i + 1]){			
			if (SZ(inds) == 0 || inds[SZ(inds) - 1] != i){
				inds.pb(i);
			}
			inds.pb(i + 1);
		}
	}
	if (SZ(inds) > 6){
		printf("0\n");
		return;
	}
	SORT(inds);
	REP(j, 0, SZ(inds)){
		REPN(i, 1, n){
			int a = i, b = inds[j];
			if (a > b){
				swap(a, b);
			}
			if (check(a, b)){
				st.insert(mp(a, b));
			}
		}
	}
	printf("%d\n", SZ(st));
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}