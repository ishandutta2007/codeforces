#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int occ[N], occ_new[N], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        map<int, int> occ;
        for (int i = 0; i < n; ++i) {
            occ[a[i]]++;
        }


        for (int i = 0; i < n - 1; ++i) {
            map<int, int> occ_new;
            int prv = -1;
            for (auto [x, c] : occ) {
                if (c > 1) occ_new[0] += c - 1;
                if (prv != -1) occ_new[x - prv] += 1;
                prv = x;
            }
            swap(occ, occ_new);
        }

        cout << occ.begin()->first << "\n";
    }
}