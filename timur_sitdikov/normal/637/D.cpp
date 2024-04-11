#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
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
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

pii pp[MAXN];
int v[MAXN];

void solve(){
	int n, m, s, d, i, top;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	REP(i, 0, n){
		scanf("%d", &v[i]);		
	}
	sort(v, v + n);
	top = 0;
	pp[top++] = mp(v[0], v[0]);
	REP(i, 1, n){
		if (v[i] - pp[top - 1].second <= s + 1){
			pp[top - 1].second = v[i];
		} else {
			pp[top++] = mp(v[i], v[i]);
		}
	}
	if (pp[0].first <= s){
		printf("IMPOSSIBLE\n");
		return;
	}
	REP(i, 0, top){
		if (pp[i].second - pp[i].first >= d - 1){
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	int cur = 0;
	REP(i, 0, top){
		int tmp = pp[i].first - 1 - cur;
		printf("RUN %d\n", tmp);
		cur += tmp;
		tmp = pp[i].second + 1 - cur;
		printf("JUMP %d\n", tmp);
		cur += tmp;
	}
	if (cur < m){
		printf("RUN %d\n", m - cur);
	}
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