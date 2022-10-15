#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

vector<int> prefix_function(const string& s) {
    int n = (int)size(s);
    vector<int> p(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

// z-function from prefix function
vector<int> z_function(const vector<int>& p) {
    int n = (int)size(p);
    vector<int> z(n, 0);
    for (int i = 0; i < n; ++i) {
        int j = i - p[i] + 1;
        if (p[i]) z[j] = p[i];
    }
    z[0] = n;
    for (int i = 1, last = 1; i < n; ++i) {
        if (i + z[i] > last + z[last]) last = i;
        z[i] = min(z[i - last], last + z[last] - i);
    }
    z[0] = 0;
    return z;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    int len = (int)size(s);

    auto z = z_function(prefix_function(s));
    int taken = 0;

    bool good = true;
    for (int j = 0, last = -1; j < m; ++j) {
        int x;
        cin >> x;
        --x;
        if (last > x && z[len - (last - x)] < last - x) {
            good = false;
            break;
        }
        taken += x + len - max(last, x);
        last = x + len;
    }

    ll ans = 0;
    if (good) {
        ans = 1;
        constexpr ll mod = 1e9 + 7;
        for (int i = 0; i < n - taken; ++i) ans = (ans * 26) % mod;
    }

    cout << ans << endl;

    exit(0);
}