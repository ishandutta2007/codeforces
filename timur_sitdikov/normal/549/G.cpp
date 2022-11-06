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
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int tt[4 * MAXN];

void calc(int ind){
    tt[ind] = tt[ind << 1] + tt[(ind << 1) + 1];
}

int get_val(int ind, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    }
    if (l == tl && r == tr){
        return tt[ind];
    }
    int tm = (tl + tr) >> 1;
    return get_val(ind << 1, tl, tm, l, min(r, tm)) + get_val((ind << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void upd_val(int ind, int tl, int tr, int pos, int val){
    if (tl == tr){
        tt[ind] = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm){
        upd_val(ind << 1, tl, tm, pos, val);
    } else {
        upd_val((ind << 1) + 1, tm + 1, tr, pos, val);
    }
    calc(ind);
}

pii pp[MAXN];
int a[MAXN];

vi ans;

void solve(){
    int n, i;
    scanf("%d", &n);
    REP(i, 0, n){
        scanf("%d", &a[i]);
        pp[i] = mp(a[i] + i, i);
    }
    sort(pp, pp + n);
    reverse(pp, pp + n);
    REP(i, 1, n){
        if (pp[i].first == pp[i - 1].first){
            printf(":(\n");
            return;
        }
    }
    REP(i, 0, n){
        int ind = pp[i].second;
        int v1 = get_val(1, 0, n - 1, 0, ind);
        int v2 = (n - 1 - ind) - get_val(1, 0, n - 1, ind, n - 1);
        upd_val(1, 0, n - 1, ind, 1);
        //printf("%d ", a[ind] + v);
        ans.pb(a[ind] + v1 - v2);
    }
    for(i = ans.size() - 1; i >= 0; i--){
        printf("%d ", ans[i]);
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