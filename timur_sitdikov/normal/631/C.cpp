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

int num[MAXN], t[MAXN], v[MAXN], ans[MAXN];
map<int, int> vv;

void solve(){
	int n, m, i, tt, a, mxnum, tmp;
	scanf("%d%d", &n, &m);
	REP(i, 0, n){
		scanf("%d", &v[i]);
		vv[v[i]]++;
	}
	REP(i, 0, m){
		scanf("%d%d", &tt, &a);
		t[a - 1] = tt;
		num[a - 1] = i + 1;
	}
	tt = 0;
	mxnum = 0;
	for(i = n - 1; i >= 0; i--){
		if (num[i] > mxnum){
			mxnum = num[i];
			tt = t[i];
		}
		if (tt == 0){
			tmp = v[i];
		} else if (tt == 1){
			tmp = vv.rbegin()->first;			
		} else {
			tmp = vv.begin()->first;
		}
		ans[i] = tmp;
		vv[tmp]--;
		if (vv[tmp] == 0){
			vv.erase(tmp);
		}		
	}
	REP(i, 0, n){
		printf("%d ", ans[i]);
	}
	putchar('\n');
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}