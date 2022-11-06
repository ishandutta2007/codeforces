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
const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;

set<pii> ee;
set<int> vv;
vector<int> ve;

int col[MAXN], g1[MAXN], n;
queue<int> qq;

void bfs(int s, int cl){
	int to, i;
	col[s] = cl;
	qq.push(s);
	vv.erase(s);
	while(!qq.empty()){
		s = qq.front();
		qq.pop();
		ve.clear();
		FA(it, vv){
			to = *it;
			if (!col[to]){
				int a = to, b = s;
				if (a > b){
					swap(a, b);
				}
				if (ee.find(mp(a, b)) == ee.end()){
					col[to] = cl;
					qq.push(to);
					ve.pb(to);
				}
			}
		}
		REP(i, 0, SZ(ve)){
			to = ve[i];
			vv.erase(to);
		}
	}
}

void solve(){
	int m, k, i, a, b, cl;
	scanf("%d%d%d", &n, &m, &k);
	REP(i, 0, m){
		scanf("%d%d", &a, &b);
		if (a > b){
			swap(a, b);
		}
		ee.insert(mp(a, b));
		if (a == 1){
			g1[b] = 1;
		}
	}	
	REPN(i, 2, n){
		vv.insert(i);
	}
	cl = 0;
	int cnt = 0;
	REPN(i, 2, n){
		if (!g1[i]){
			cnt++;
		}
	}
	if (cnt < k){
		printf("impossible\n");
		return;
	}
	REPN(i, 2, n){
		if (!g1[i] && !col[i]){
			bfs(i, ++cl);
		}
	}
	if (cl > k){
		printf("impossible\n");
		return;
	}
	REPN(i, 2, n){
		if (col[i] == 0){
			printf("impossible\n");
			return;
		}
	}
	printf("possible\n");
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}