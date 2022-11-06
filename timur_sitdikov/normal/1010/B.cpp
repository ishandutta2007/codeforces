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

int v[MAXN];

void solve(){
	int n, m;
	scanf("%d%d", &m, &n);
	REP(i, 0, n){
		printf("1\n");
		fflush(stdout);
		int a;
		scanf("%d", &a);
		if (a == 0){
			return;
		}
		if (a == -2){
			exit(0);
		}
		v[i] = a;
	}
	int l = 2, r = m;
	int i = 0;
	while(l < r){
		int mid = (l + r) / 2;
		printf("%d\n", mid);
		fflush(stdout);
		int a;
		scanf("%d", &a);
		if (a == 0){
			return;
		}
		if (a == -2){
			exit(0);
		}
		if (v[i] == 1 && a == 1 || v[i] == -1 && a == -1){
			l = min(r, mid + 1);
		} else {
			r = max(l, mid - 1);
		}
		i = (i + 1) % n;
	}
	printf("%d\n", r);
	fflush(stdout);
}   

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif*/
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}