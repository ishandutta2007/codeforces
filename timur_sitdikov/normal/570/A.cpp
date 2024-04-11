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
const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;

pii g[MAXN], cnt[MAXN];

void solve(){
    int n, m, i, j, a;
    cin >> n >> m;
    REP(i, 0, n){
        g[i].second = i;
    }
    REP(i, 0, m){
        REP(j, 0, n){
            cnt[j] = mp(0, j);
        }
        REP(j, 0, n){
            cin >> a;
            cnt[j].first -= a;
        }
        sort(cnt, cnt + n);
        g[cnt[0].second].first--;
    }
    sort(g, g + n);
    int ans = g[0].second;
    cout << ans + 1 << endl;
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