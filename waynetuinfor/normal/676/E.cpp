#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int mod[] = { 479001599, 433494437, 1073807359 };
int a[maxn];

inline int add(int a, int b, int c) { if (b < 0) b %= mod[c], b += mod[c]; return a + 0ll + b >= mod[c] ? a + 0ll + b - mod[c] : a + b; }
inline int mul(int a, int b, int c) { if (b < 0) b %= mod[c], b += mod[c]; return a * 1ll * b % mod[c]; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int q = 0;
    fill(a, a + maxn, mod[0]);
    for (int i = 0; i <= n; ++i) {
        string s; cin >> s;
        if (s == "?") {
            ++q;
            continue;
        }
        stringstream ss(s);
        ss >> a[i];
    }
    if (q == 0) { 
        vector<int> v(3), x(3, 1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) v[j] = add(v[j], mul(x[j], a[i], j), j), x[j] = mul(x[j], k, j);
        }
        for (int i = 0; i < 3; ++i) {
            if (v[i] != 0) return cout << "No" << endl, 0;
        }
        cout << "Yes" << endl;
        return 0;
    }
    if (k == 0) {
        if (a[0] == mod[0]) {
            if ((n - q + 1) & 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if (a[0] == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        return 0;
    }
    if (n & 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}