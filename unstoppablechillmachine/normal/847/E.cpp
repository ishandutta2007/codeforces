//GLEBAS
#include <bits/stdc++.h>

using namespace std;

#define TASK "cifrul"

typedef long long ll;
typedef pair<ll, ll> par;

#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define pw(x) (1ll << (x))

const ll INF = ll(1e18);
const ll MOD = ll(1e9) + 7;
string s;

ll n;

bool zZzZz(ll m) {
    ll i = 0;
    ll curr = 0;
    while (i < n) {
        while (i < n && s[i] == '.') ++i;
        if (i == n) break;
        if (s[i] == 'P') {
            ll lim = max(m - 2 * curr, (m - curr) / 2);
            ll it = 0;
            ++i;
            while (i < n && it < lim && s[i] != 'P') ++i, ++it;
            curr = 0;
            continue;
        }
        if (s[i] == '*') {
            ll it = 1;
            while (i < n && it <= m && s[i] != 'P') ++i, ++it, curr++;
            if (i == n || s[i] != 'P') return 0;
            continue;
        }
    }
    return 1;
}

int source() {
    cin >> n;
    cin >> s;
    vector<ll> a(n);
    ll l = 0, r = 10 * n + 1;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        bool f1 = zZzZz(m);
        reverse(all(s));
        bool f2 = zZzZz(m);
        reverse(all(s));
        if (f1 || f2) r = m;
        else l = m;
    }
    cout << r;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        source();
        cout << '\n';
    }
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
    source();
#endif
    return 0;
}