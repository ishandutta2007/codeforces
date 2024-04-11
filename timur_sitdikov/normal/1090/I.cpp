#include <bits/stdc++.h>

#define Pi acos(-1.)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define fi first
#define se second
#define FILE "474"
#define standart 1

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e9 + 322;
const ll LINF = 2e18 + 474;
const ll MAXN = 2e7 + 5;
const double eps = 1e-12;

ll n, l, r;
unsigned long long x, y, z, b1, b2, MOD;

ll a[MAXN];
unsigned long long b[MAXN];

void solve() {
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2 ;
    b[1] = b1;
    b[2] = b2;
    for(int i = 3; i <= n; i++) {
        b[i] = (b[i-2] * x + b[i-1] * y + z) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = (b[i] % (r - l + 1)) + l;
    }
    bool ok = false;
    ll mn = a[1], ans;
    for(int i = 2; i <= n; i++) {
        if(a[i] > mn) {
            if(!ok) {
                ans = a[i] * mn;
            }
            ans = min(ans, a[i] * mn);
            ok = true;
        }
        mn = min(mn, a[i]);
    }
    ll mx = a[n];
    for(int i = n-1; i >= 1; i--) {
        if(a[i] < mx) {
            if(!ok) {
                ans = a[i] * mn;
            }
            ans = min(ans, a[i] * mx);
            ok = true;
        }
        mx = max(mx, a[i]);
    }
    if(!ok) {
        cout << "IMPOSSIBLE\n";
    }
    else
        cout << ans << "\n";
}




int main() {
    if(!standart) {
        freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    setlocale(LC_ALL, "Russian");
    MOD = 1;
    MOD <<= 32;
    int T = 1; cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}