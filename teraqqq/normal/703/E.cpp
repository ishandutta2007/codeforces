#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ii = long long;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int C = 1e6 + 229;

const int N = 1001;
const int D = 1e4;

int dp[N][D];
short prv[N][D];
ll ds[N][D];
short hid[C];

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); for (ll& x : a) cin >> x;
    
    if (k == 1) {
        cout << "1\n" << min_element(a.begin(), a.end()) - a.begin() + 1 << "\n";
        return;
    }

    vector<ii> divs;
    for (ii d = 1; d*d <= k; ++d) {
        if (k % d != 0) continue;
        divs.push_back(d);
        if (d * d != k) divs.push_back(k / d);
    }
    sort(divs.begin(), divs.end());

    mt19937 rng(1337228);
    int hsh_x;
    while (true) {
        bool ok = true;
        int x = rng() % C; set<int> s;
        for (ii t : divs) {
            if (s.count(t * x % C)) {
                ok = false;
                break;
            }
            s.insert(t * x % C);
        }

        if (ok) {
            hsh_x = x;
            break;
        }
    }

    for (int i = 0; i < divs.size(); ++i) {
        hid[divs[i] * hsh_x % C] = i;
    }

    const int m = divs.size();
    const int INF = 1e9;

    // for (auto x : divs) cout << (ll)x << ' '; cout << endl;

    for (int i = 0; i <= n; ++i) fill(prv[i], prv[i]+m+1, -1);
    fill(dp[0]+1, dp[0]+m+1, INF);
    fill(ds[0]+1, ds[0]+m+1, (ll)1e18);
    dp[0][0] = 0; ds[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        copy(dp[i-1], dp[i-1]+m+1, dp[i]);
        copy(ds[i-1], ds[i-1]+m+1, ds[i]);
        ll a0 = __gcd(a[i-1], k);

        for (int t = 0; t < m; ++t) {
            ll prev = divs[t] / __gcd(a0, divs[t]);
            int j = hid[hsh_x * prev % C];
            if (divs[j] == prev) {
                if (ckmin(dp[i][t], dp[i-1][j] + 1)) ds[i][t] = (ll) 1e18;
                if (dp[i][t] == dp[i-1][j] + 1) {
                    if (ckmin(ds[i][t], ds[i-1][j] + a[i-1])) prv[i][t] = j;
                }
            }
        }
    }

    if (dp[n][m-1] == INF) {
        cout << "-1\n";
    } else {
        cout << dp[n][m-1] << endl;
        for (int i = n, j = m - 1; i != 0; --i) {
            if (prv[i][j] != -1) {
                cout << i << ' ';
                j = prv[i][j];
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}