#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 2e5 + 10;
bool pr[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    for (int i = 2; i < N; i++) {
        if (!pr[i] && (i * 1ll * i < N)) {
            for (int j = i * i; j < N; j += i) {
                pr[j] = true;
            }
        }
        pr[i] = !pr[i];
    }
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> dels;
        for (int i = 1; i < n; i++) {
            if (n % i == 0 && pr[n / i]) {
                dels.push_back(i);
            }
        }
        vector<vector<ll>> sum(dels.size());
        for (int i = 0; i < sum.size(); i++) {
            sum[i].resize(dels[i]);
        }
        vector<int> a(n);
        multiset<ll> vals;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < dels.size(); j++) {
                sum[j][i % dels[j]] += a[i];
            }
        }
        for (int i = 0; i < dels.size(); i++) {
            for (int j = 0; j < dels[i]; j++) {
                vals.insert(sum[i][j] * dels[i]);
            }
        }
        cout << *vals.rbegin() << '\n';
        for (int i = 0; i < q; i++) {
            int pos, new_val;
            cin >> pos >> new_val;
            pos--;
            int delta = new_val - a[pos];
            for (int j = 0; j < dels.size(); j++) {
                vals.erase(vals.find(sum[j][pos % dels[j]] * dels[j]));
                sum[j][pos % dels[j]] += delta;
                vals.insert(sum[j][pos % dels[j]] * dels[j]);
            }
            a[pos] = new_val;
            cout << *vals.rbegin() << '\n';
        }
    }
    return 0;
}