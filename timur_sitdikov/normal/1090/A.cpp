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
const ll MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;


int n;
pair<ll, ll> a[MAXN];
ll ans = 0;

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll k; cin >> k;
        ll mx = 0;
        for(int j = 0; j < k; j++) {
            ll x; cin >> x;
            mx = max(x, mx);
        }
        a[i] = mp(mx, k);
    }
    sort(a, a + n);
    for(int i = n-2; i >= 0; i--) {
        ans += (a[n-1].fi - a[i].fi) * a[i].se;
    }
    cout << ans;
}




int main() {
    if(!standart) {
        freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    setlocale(LC_ALL, "Russian");
    int T = 1; //cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}