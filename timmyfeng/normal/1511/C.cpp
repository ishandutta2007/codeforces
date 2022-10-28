#include <bits/stdc++.h>
using namespace std;

const int A = 51;

int where[A];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (where[a] == 0) {
            where[a] = i;
        }
    }

    while (q--) {
        int t;
        cin >> t;

        int i = where[t];
        for (int j = 1; j < A; ++j) {
            where[j] += 0 < where[j] && where[j] < i;
        }
        where[t] = 1;

        cout << i << " ";
    }
    cout << "\n";
}