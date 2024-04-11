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

const int MAXN = 2e5 + 5;

pair<int, pii> task[MAXN];

vi vals;

bool process(int n, int t, int mid){
	vals.clear();
	int cnt = 0;
	int tt = 0;
	REP(i, 0, n){
		if (task[i]._2._1 >= mid && cnt < mid && tt + task[i]._1 <= t){
			tt += task[i]._1;
			cnt++;
			vals.pb(task[i]._2._2);
		}
	}
	return cnt == mid;
}

void solve(){
	int n, t;
	scanf("%d%d", &n, &t);
	REP(i, 0, n){
		int a, b;
		scanf("%d%d", &a, &b);
		task[i] = mp(b, mp(a, i));
	}
	sort(task, task + n);
	int l = 0, r = n + 1;
	for(; l + 1 < r; ){
		int mid = (l + r) / 2;		
		if (process(n, t, mid)){
			l = mid;
		} else {
			r = mid;
		}
	}
	process(n, t, l);
	printf("%d\n%d\n", l, l);
	REP(i, 0, SZ(vals)){
		printf("%d ", vals[i] + 1);
	}
	putchar('\n');
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