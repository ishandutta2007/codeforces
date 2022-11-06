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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

void output_path(int n, int a, int b, int c, int d){
	cout << a << " " << c << " ";
	REPN(i, 1, n){
		if (i != a && i != b && i != c && i != d){
			cout << i << " ";
		}
	}
	cout << d << " " << b << endl;
}

void solve(){
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	if (n == 4 || k <= n){
		cout << -1 << endl;
		return;
	}
	output_path(n, a, b, c, d);
	output_path(n, c, d, a, b);
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}