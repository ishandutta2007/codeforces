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

string s[2][2], s1[2];

void solve(){
	int i, j, k;
	REP(i, 0, 2){
		REP(j, 0, 2){
			cin >> s[i][j];
			if (j == 0){
				REP(k, 0, 2){
					if (s[i][j][k] != 'X'){
						s1[i] += s[i][j][k];
					}
				}
			} else {
				for(k = 1; k >= 0; k--){
					if (s[i][j][k] != 'X'){
						s1[i] += s[i][j][k];
					}
				}
			}
		}
	}
	REP(i, 0, 3){
		// cout << s1[0] << " " << s1[1] << endl;
		if (s1[0] == s1[1]) {
			printf("YES\n");
			return;
		}
		string tmp = "";
		tmp += s1[0][1];
		tmp += s1[0][2];
		tmp += s1[0][0];
		s1[0] = tmp;
	}
	printf("NO\n");
	
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}