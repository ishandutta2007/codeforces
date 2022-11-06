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

vi g[MAXN];
int par[MAXN];

ll cnt0[MAXN], cnt1[MAXN], sum0[MAXN], sum1[MAXN];
ll cnt0_g, cnt1_g, sum0_g, sum1_g;

void dfs(int s) {
	ll cnt0_tot = 0, cnt1_tot = 0, sum0_tot = 0, sum1_tot = 0;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (par[s] != to) {
			par[to] = s;
			dfs(to);
			
			cnt1_tot += cnt1[to];
			cnt0_tot += cnt0[to];
			sum1_tot += sum1[to];
			sum0_tot += sum0[to];
		}
	}
	
	ll cnt0_g_add = 0ll, cnt1_g_add = 0ll, sum0_g_add = 0ll, sum1_g_add = 0ll;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (par[s] != to) {
			/*cnt0_g_add += cnt0[to] * (cnt0_tot - cnt0[to]);
			cnt0_g_add += cnt1[to] * (cnt1_tot - cnt1[to]);
			cnt1_g_add += cnt0[to] * (cnt1_tot - cnt1[to]);
			cnt1_g_add += cnt1[to] * (cnt0_tot - cnt0[to]);*/
			
			cnt0_g_add += cnt0[to] * (cnt0_tot - cnt0[to]);
			cnt0_g_add += cnt1[to] * (cnt1_tot - cnt1[to]);
			cnt1_g_add += cnt0[to] * (cnt1_tot - cnt1[to]);
			cnt1_g_add += cnt1[to] * (cnt0_tot - cnt0[to]);
			
			//sum0_g_add += (sum0[to] + cnt0[to]) * (sum0_tot - (sum0[to] + cnt0[to]));
			//sum0_g_add += (sum1[to] + cnt1[to]) * (sum1_tot - (sum1[to] + cnt1[to]));
			//sum1_g_add += (sum0[to] + cnt0[to]) * (sum1_tot - (sum1[to] + cnt1[to]));
			//sum1_g_add += (sum1[to] + cnt1[to]) * (sum0_tot - (sum0[to] + cnt0[to]));
			
			/*sum0_g_add += (sum0[to] + cnt0[to]) * (sum1_tot - (sum0[to] + cnt0[to]));
			sum0_g_add += (sum1[to] + cnt1[to]) * (sum0_tot - (sum1[to] + cnt1[to]));
			sum1_g_add += (sum0[to] + cnt0[to]) * (sum0_tot - (sum1[to] + cnt1[to]));
			sum1_g_add += (sum1[to] + cnt1[to]) * (sum1_tot - (sum0[to] + cnt0[to]));*/
			
			sum0_g_add += (sum0[to] + cnt0[to]) * (cnt0_tot - cnt0[to]) + cnt0[to] * (sum0_tot - sum0[to] + cnt0_tot - cnt0[to]);
			sum0_g_add += (sum1[to] + cnt1[to]) * (cnt1_tot - cnt1[to]) + cnt1[to] * (sum1_tot - sum1[to] + cnt1_tot - cnt1[to]);
			sum1_g_add += (sum0[to] + cnt0[to]) * (cnt1_tot - cnt1[to]) + cnt0[to] * (sum1_tot - sum1[to] + cnt1_tot - cnt1[to]);
			sum1_g_add += (sum1[to] + cnt1[to]) * (cnt0_tot - cnt0[to]) + cnt1[to] * (sum0_tot - sum0[to] + cnt0_tot - cnt0[to]);
		}
	}
	cnt0_g_add /= 2;
	cnt1_g_add /= 2;
	sum0_g_add /= 2;
	sum1_g_add /= 2;
	
	cnt0_g += cnt0_g_add;
	cnt1_g += cnt1_g_add;
	sum0_g += sum0_g_add;
	sum1_g += sum1_g_add;
	
	cnt0[s] = 1 + cnt1_tot;
	cnt1[s] = cnt0_tot;
	sum0[s] = sum1_tot + cnt1_tot;
	sum1[s] = sum0_tot + cnt0_tot;
	
	
	cnt0_g += cnt0[s] - 1;
	cnt1_g += cnt1[s];
	sum0_g += sum0[s];
	sum1_g += sum1[s];
}

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	
	/*REPN(i, 1, n) {
		printf("%d %lld %lld %lld %lld\n", i, cnt0[i], cnt1[i], sum0[i], sum1[i]);
	}
	printf("%lld %lld %lld %lld\n", cnt0_g, cnt1_g, sum0_g, sum1_g);*/
	
	ll ans = sum0_g / 2 + (sum1_g + cnt1_g) / 2;
	cout << ans << endl;
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