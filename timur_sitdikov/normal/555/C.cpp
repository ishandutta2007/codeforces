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
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

set <pii> vg, vv;
set<pii>::iterator it, it1;

int calc(int x, int y, set <pii> &vg, set <pii> &vv){
    int l1, r1, l2, r2, old, ans;
    it = vg.lower_bound(mp(x + 1, 0));
    l2 = x + 1;
    r2 = it->first - 1;
    it--;
    l1 = it->first;
    r1 = x - 1;
    old = it->second;
    ans = y - old;
    vg.erase(it);
    if (l1 <= r1){
        vg.insert(mp(l1, old));
    }
    vg.insert(mp(x, y));
    if (l2 <= r2){
        vg.insert(mp(l2, old));
    }
    it = vv.lower_bound(mp(y + 1, 0));
    l2 = y + 1;
    r2 = it->first - 1;
    it--;
    l1 = it->first;
    r1 = y;
    old = it->second;
    vv.erase(it);
    vv.insert(mp(l1, x));
    if (l2 <= r2){
        vv.insert(mp(l2, old));
    }
    return ans;
}

void solve(){
    int n, q, i, x, y, ans;
    char c[10];
    scanf("%d%d", &n, &q);
    vg.insert(mp(n + 1, 0));
    vg.insert(mp(1, 0));
    vv.insert(mp(n + 1, 0));
    vv.insert(mp(1, 0));
    REP(i, 0, q){
        scanf("%d%d%s", &x, &y, &c[0]);
        if (c[0] == 'U'){
            ans = calc(x, y, vg, vv);
        } else {
            ans = calc(y, x, vv, vg);
        }
        printf("%d\n", ans);
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