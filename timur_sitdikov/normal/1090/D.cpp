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
const ll MAXN = 1e5 + 5;
const double eps = 1e-12;

ll n, m;
set<pair<ll, ll> > st;
ll a[MAXN], b[MAXN];

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if(u > v)
            swap(u, v);
        st.insert(mp(u, v));
    }
    if(n * (n-1) == 2 * m) {
        cout << "NO";
        return;
    }
    ll x, y;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(st.find(mp(i, j)) == st.end() && i != j) {
                x = i, y = j;
                break;
            }
        }
    }
    a[x] = n-1;
    a[y] = n;
    b[x] = n;
    b[y] = n;
    ll cur = 1;
    for(int i = 1; i <= n; i++) {
        if(i != x && i != y) {
            a[i] = cur;
            cur++;
        }
    }
    cur = 1;
    for(int i = 1; i <= n; i++) {
        if(i != x && i != y) {
            b[i] = cur;
            cur++;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
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