#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a[110], b;
set<ll> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        s.clear();
        cin >> n >> k;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        if (s.size() > k) {
            cout << -1 << endl;
            continue;
        }
        cout << n * k << endl;
        k1 = s.size();
        for (i = 0; i < n; i++) {
            for (auto u : s) {
                cout << u << ' ';
            }
            for (j = k1; j < k; j++) {
                cout << 1 << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}