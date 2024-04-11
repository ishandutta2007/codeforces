#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<int> I(n);
    iota(all(I), 0);
    sort(all(I), [&](int i, int j){ return a[i] < a[j]; });

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) pos[I[i]] = i;

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[I[(pos[i] + 1) % n]];
    }

    vector<ll> sum(1 << n);
    for (int i = 0; i < n; ++i) sum[1 << i] = a[i] - b[i];

    for (int mask = 1; mask < (1 << n) - 1; ++mask) {
        int lsb = mask & -mask;
        sum[mask] = sum[mask ^ lsb] + sum[lsb];
        if (sum[mask] == 0) {
            debug(bitset<4>(mask));
            cout << -1 << endl;
            exit(0);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << "\n "[i + 1 < n];
    }


    exit(0);
}