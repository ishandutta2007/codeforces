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
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;

char s[MAXN];

void solve(){
	int n, ans = 0;
	scanf("%s", &s[0]);
	n = strlen(s);
	REP(i, 0, n){
		int mx = 0, mn = 0;
		REP(j, i, n){
			if (s[j] == '('){
				mx++;
				mn++;
			} else if (s[j] == ')'){
				mx--;
				mn--;
			} else {
				mx++;
				mn--;
			}
			if (mn < 0){
				mn = min(mn + 2, mx);
			}
			//printf("%d %d\n", mx, mn);
			if (mx >= 0 && mn <= 0 && (j - i) % 2 == 1){
				//printf("%d %d %d %d\n", i, j, mx, mn);
				ans++;
			}
			if (mx < 0){
				break;
			}
		}
	}
	printf("%d\n", ans);
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