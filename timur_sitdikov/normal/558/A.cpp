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

pii a1[MAXN], a2[MAXN];
int top1, top2;

void solve(){
    int n, i, a, x, lim, ans = 0;
    cin >> n;
    REP(i, 0, n){
        cin >> x >> a;
        if (x < 0){
            a1[top1++] = mp(-x, a);
        } else {
            a2[top2++] = mp(x, a);
        }
    }
    sort(a1, a1 + top1);
    sort(a2, a2 + top2);
    lim = min(top1, top2) + 1;
    REP(i, 0, lim){
        ans += a1[i].second + a2[i].second;
    }
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