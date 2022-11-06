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
const int MAXN = 5e5 + 5;
const ll MOD = 1e9 + 7;

int l[MAXN], r[MAXN], g[MAXN], ind_b[MAXN];
char s[MAXN], q[MAXN];

void solve(){
	int n, m, pos;
	scanf("%d%d%d%s%s", &n, &m, &pos, &s[1], &q[0]);
	int bb = 0;
	REPN(i, 1, n){
		l[i] = i - 1;
		r[i] = i + 1;
		if (s[i] == '('){
			bb++;
			ind_b[bb] = i;
		} else {
			int last = ind_b[bb];
			g[last] = i;
			g[i] = last;
			bb--;			
		}
	}
	r[0] = 1;
	l[n + 1] = n;
	REP(i, 0, m){
		if (q[i] == 'L'){
			pos = l[pos];
		} else if (q[i] == 'R'){
			pos = r[pos];
		} else if (q[i] == 'D'){
			int a = min(pos, g[pos]);
			int b = max(pos, g[pos]);
			r[l[a]] = r[b];
			l[r[b]] = l[a];
			if (r[b] <= n){
				pos = r[b];
			} else {
				pos = l[a];
			}
		}
	}
	for(int i = r[0]; i <= n; i = r[i]){
		putchar(s[i]);
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