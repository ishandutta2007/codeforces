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

set<int> g[MAXN];

queue<int> qq;

int v[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 1, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].insert(b);
		g[b].insert(a);
	}
	REP(i, 0, n) {
		scanf("%d", &v[i]);
	}
	if (v[0] != 1) {
		printf("No\n");
			return;
	}
	qq.push(v[0]);
	REP(i, 1, n) {
		int cur = v[i];
		while(!qq.empty()) {
			int s = qq.front();
			if (g[s].find(cur) != g[s].end()) {
				break;
			}
			qq.pop();
		}
		if (qq.empty()) {
			printf("No\n");
			return;
		}
		qq.push(cur);
	}
	printf("Yes\n");
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