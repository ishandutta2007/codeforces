#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

int p[MAXN];

int used[MAXN];

vi loops[MAXN];

vector<pair<vi, vi> > ans;

vi pos[5];

void process_vec(vi &tmp1) {
	vi tmp2 = tmp1;
	rotate(tmp2.begin(), tmp2.begin() + 1, tmp2.end());
	ans.pb(mp(tmp1, tmp2));
}

vi add(vi &v1, vi &v2) {
	vi ans = v1;
	REP(i, 0, SZ(v2)) {
		ans.pb(v2[i]);
	}
	return ans;
}

void process_vecs(vi &tmp1, vi &tmp2) {
	vi tmp3, tmp4;
	tmp3 = tmp1;
	tmp4 = tmp2;
	rotate(tmp3.begin(), tmp3.begin() + 1, tmp3.end());
	rotate(tmp4.begin(), tmp4.begin() + 1, tmp4.end());
	ans.pb(mp(add(tmp1, tmp2), add(tmp3, tmp4)));
}

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		scanf("%d", &p[i]);
	}
	int m = 0;
	REPN(i, 1, n) {
		if (!used[i]) {
			for(int j = i; !used[j]; j = p[j]) {
				loops[m].pb(j);
				used[j] = 1;
			}
			m++;
		}
	}
	vi tmp1, tmp2, tmp3, tmp4;
	REP(i, 0, m) {
		while(SZ(loops[i]) >= 5) {
			tmp1.clear();
			REP(j, SZ(loops[i]) - 5, SZ(loops[i])) {
				tmp1.pb(loops[i][j]);
			}
			//loops[i][SZ(loops[i]) - 5] = loops[i].back();
			REP(j, 0, 4) {
				loops[i].pop_back();
			}
			process_vec(tmp1);
		}
	}
	REP(i, 0, m) {
		pos[SZ(loops[i])].pb(i);
	}
	REP(i, 0, SZ(pos[4])) {
		process_vec(loops[pos[4][i]]);
	}
	while(SZ(pos[2]) > 0 && SZ(pos[3]) > 0) {
		tmp1 = loops[pos[2].back()];
		tmp2 = loops[pos[3].back()];
		pos[2].pop_back();
		pos[3].pop_back();
		process_vecs(tmp1, tmp2);
	}
	while(SZ(pos[2]) > 1) {
		tmp1 = loops[pos[2][SZ(pos[2]) - 1]];
		tmp2 = loops[pos[2][SZ(pos[2]) - 2]];
		pos[2].pop_back();
		pos[2].pop_back();
		process_vecs(tmp1, tmp2);
	}
	REP(i, 0, SZ(pos[2])) {
		process_vec(loops[pos[2][i]]);
	}
	while(SZ(pos[3]) > 2) {
		tmp1 = loops[pos[3][SZ(pos[3]) - 1]];
		tmp2 = loops[pos[3][SZ(pos[3]) - 2]];
		tmp3 = loops[pos[3][SZ(pos[3]) - 3]];
		pos[3].pop_back();
		pos[3].pop_back();
		pos[3].pop_back();
		tmp4.clear();
		tmp4.pb(tmp2[1]);
		tmp4.pb(tmp2[2]);
		process_vecs(tmp1, tmp4);
		//tmp2[1] = tmp2[2];
		tmp2.pop_back();
		process_vecs(tmp3, tmp2);
	}
	REP(i, 0, SZ(pos[3])) {
		process_vec(loops[pos[3][i]]);
	}
	
	printf("%d\n", SZ(ans));
	REP(i, 0, SZ(ans)) {
		printf("%d\n", SZ(ans[i]._1));
		REP(j, 0, SZ(ans[i]._1)) {
			printf("%d ", ans[i]._1[j]);
		}
		putchar('\n');
		REP(j, 0, SZ(ans[i]._2)) {
			printf("%d ", ans[i]._2[j]);
		}
		putchar('\n');
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