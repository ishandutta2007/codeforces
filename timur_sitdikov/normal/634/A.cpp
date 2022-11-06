#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

int v[2][MAXN], top[2];

void solve(){
	int n, i, j, a, offset;
	scanf("%d", &n);
	REP(i, 0, 2){
		REP(j, 0, n){
			scanf("%d", &a);
			if (a){
				v[i][top[i]++] = a;
			}
		}
	}
	REP(offset, 0, n - 1){
		if (v[1][offset] == v[0][0]){
			break;
		}
	}
	REP(i, 0, n - 1){
		if (v[0][i] != v[1][(i + offset) % (n - 1)]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}