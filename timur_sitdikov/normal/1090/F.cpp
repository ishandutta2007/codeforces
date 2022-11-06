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

map<pair<pii, int>, int> mem;

void if_swap(int &i, int &j){
	if (i > j) {
		swap(i, j);
	}
}

void sort(int &i, int &j, int &k){
	if_swap(i, j);
	if_swap(j, k);
	if_swap(i, j);
}

int get(int i, int j, int k){
	sort(i, j, k);
	if (mem.find(mp(mp(i, j), k)) == mem.end()) {
		return -1;
	}
	return mem[mp(mp(i, j), k)];
}

void make_query(int i, int j, int k) {
	sort(i, j, k);
	if (get(i, j, k) != -1) {
		return;
	}
	printf("? %d %d %d\n", i, j, k);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	mem[mp(mp(i, j), k)] = ans;
}

ll sum[6];
vector<pair<ll, int> > vv;
int per[6];
ll val[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, 5) {
		REPN(j, i + 1, 5) {
			REPN(k, j + 1, 5){
				make_query(i, j, k);
				int v = get(i, j, k);
				sum[i] += v;
				sum[j] += v;
				sum[k] += v;
			}
		}
		vv.pb(mp(sum[i], i));
	}
	SORT(vv);
	REP(i, 0, 5) {
		per[i] = vv[i]._2;
	}
	ll v02 = get(per[0], per[1], per[2]);
	ll v20 = get(per[2], per[3], per[4]) - get(per[0], per[3], per[4]);
	val[per[2]] = (v02 + v20) / 2;
	val[per[0]] = v02 - val[per[2]];
	val[per[3]] = get(per[0], per[2], per[3]) - val[per[0]];
	val[per[4]] = get(per[0], per[2], per[4]) - val[per[0]];
	val[per[1]] = get(per[1], per[3], per[4]) - val[per[4]];
	for(int i = 6; i <= n; i++) {
		make_query(per[0], per[1], i);
		int f = get(per[0], per[1], i);
		if (f < val[per[0]] + val[per[1]]) {
			val[i] = f - val[per[1]];
		} else if (f > val[per[0]] + val[per[1]]) {
			val[i] = f - val[per[0]];
		} else {
			make_query(per[1], per[4], i);
			f = get(per[1], per[4], i);
			val[i] = f - val[per[4]];
		}
	}
	printf("!");
	REPN(i, 1, n) {
		printf(" %lld", val[i]);
	}
	putchar('\n');
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