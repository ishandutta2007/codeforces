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
#define REPN(i, a, b) for((i) = (a); (i) <= (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;

char sgn[MAXN];
int val[MAXN];

void solve(){
	int n, m, i, a, cur_sum;
	char s[10];
	sgn[0] = '+';
	for(m = 1; ; m++){
		scanf("%s%s", &s[0], &s[0]);
		if (s[0] == '='){
			break;
		}
		sgn[m] = s[0];
	}
	scanf("%d", &n);
	cur_sum = 0;
	REP(i, 0, m){
		if (sgn[i] == '-'){
			cur_sum -= n;
			val[i] = n;
		} else {
			cur_sum += 1;
			val[i] = 1;
		}
	}
	REP(i, 0, m){
		if (cur_sum < n){
			int tmp = min(n - cur_sum, n - 1);
			if (sgn[i] == '-'){
				val[i] -= tmp;
			} else {
				val[i] += tmp;
			}
			cur_sum += tmp;
		}
	}
	if (cur_sum != n){
		printf("Impossible\n");
		return;
	}
	printf("Possible\n");
	REP(i, 0, m){
		printf("%d ", val[i]);
		if (i == m - 1){
			printf("= ");
		} else {
			printf("%c ", sgn[i + 1]);
		}
	}
	printf("%d\n", n);
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}