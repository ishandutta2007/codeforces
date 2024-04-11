#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> leaf(n + 1, true);
    vector<int> par(n + 1);

    for (int i = 2; i <= n; ++i) {
        cin >> par[i];
        leaf[par[i]] = false;
    }

    vector<int> child(n + 1);

    for (int i = 2; i <= n; ++i) {
        if (leaf[i]) {
            ++child[par[i]];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!leaf[i] && child[i] < 3) {
            cout << "No\n";
            exit(0);
        }
    }

    cout << "Yes\n";
}