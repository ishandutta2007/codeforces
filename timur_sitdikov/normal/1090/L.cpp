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
const double eps = 1e-12;

bool check(ll t, ll n, ll a, ll b, ll k) {
    ll tot = ((n + 1) / 2) * min(a, t) + (n / 2) * min(b, t);
    return tot >= t * k;
}

void solve() {
    ll t, n, a, b, k, ans;
    cin >> t >> n >> a >> b >>k;
    a = min(a, t);
    b = min(b, t);
    if(k > n) {
        cout << 0;
        return;
    }
    if(check(t, n, a, b, k) == true) {
        ans = t;
    }
    else {
        ll l = min(a, b), r = t;
        while(l + 1 < r) {
            ll mid = (l + r) >> 1;
            if(check(mid, n, a, b, k)) {
                l = mid;
            }
            else
                r = mid;
        }
        ans = l;
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