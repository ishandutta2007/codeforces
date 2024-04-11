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

const long double EPS = 1e-14;
const long double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int x[3], y[3];

int check(int x1, int y1, int x2, int y2, int x3, int y3){
	if (x1 != x2){
		return 0;
	}
	if (y1 > y2){
		swap(x1, x2);
		swap(y1, y2);
	}
	if (y3 <= y1 || y3 >= y2){
		return 1;
	}
	return 0;
}

void solve(){
	int i, j, k;
	REP(i, 0, 3){
		cin >> x[i] >> y[i];
	}
	if (x[0] == x[1] && x[1] == x[2] || y[0] == y[1] && y[1] == y[2]){
		cout << 1 << endl;
		return;
	}
	REP(i, 0, 3){
		REP(j, i + 1, 3){
			k = 3 - i - j;
			if (check(x[i], y[i], x[j], y[j], x[k], y[k]) || check(y[i], x[i], y[j], x[j], y[k], x[k])){
				cout << 2 << endl;
				return;
			}
		}
	}
	cout << 3 << endl;
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