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

const int MAXN = 12, MAXC = 105;

int cost[MAXN], cost_mask[1 << MAXN];

int cnt[1 << MAXN];
int ans[1 << MAXN][MAXC];

char c[2 * MAXN];

int get_mask(){
	scanf("%s", &c[0]);
	int ans = 0;
	for(int i = 0; c[i]; i++){
		ans += (c[i] - '0') * (1 << i);
	}
	return ans;
}

void solve(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	REP(i, 0, n){
		scanf("%d", &cost[i]);
	}
	REP(i, 0, 1 << n){
		REP(j, 0, n){
			if (i & (1 << j)){
				cost_mask[i] += cost[j];
			}
		}
	}
	REP(i, 0, m){
		cnt[get_mask()]++;
	}
	
	REP(i, 0, 1 << n){
		REP(j, 0, 1 << n){
			int cur_cost = cost_mask[((1 << n) - 1) ^ i ^ j];
			if (cur_cost < MAXC){
				ans[i][cur_cost] += cnt[j];
			}
		}
		REP(j, 1, MAXC){
			ans[i][j] += ans[i][j - 1];
		}
	}
	
	REP(i, 0, q){
		int v = get_mask();
		int k;
		scanf("%d", &k);
		printf("%d\n", ans[v][k]);
	}
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