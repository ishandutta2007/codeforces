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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e3 + 5, MAXV = 2e6 + 5;
const ll MOD = 1e9 + 7;

int a[MAXN];
char p[MAXV];

void solve(){
	int n;
	for(int i = 2; i * i < MAXV; i++){
		if (!p[i]){
			for(int j = i * i; j < MAXV; j += i){
				p[j] = 1;
			}
		}
	}
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &a[i]);
	}
	vi v_ans;
	v_ans.pb(a[0]);
	REP(i, 0, n){
		if (a[i] == 1){
			int cnt1 = 0, fl_even = 0;
			REP(j, 0, n){
				if (a[j] == 1){
					cnt1++;
				} else if (!p[1 + a[j]]){
					fl_even = a[j];
				}
			}
			v_ans.clear();
			REP(j, 0, cnt1){
				v_ans.pb(1);
			}
			if (fl_even){
				v_ans.pb(fl_even);
			}
		}
	}
	REP(i, 0, n){
		REP(j, 0, n){			
			if (i != j && !p[a[i] + a[j]] && SZ(v_ans) < 2){
				v_ans.clear();
				v_ans.pb(a[i]);
				v_ans.pb(a[j]);			
			}
		}
	}
	printf("%d\n", SZ(v_ans));
	REP(i, 0, SZ(v_ans)){
		printf("%d ", v_ans[i]);
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