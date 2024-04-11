#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<bool> del(n, true);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        del[--x] = false;
    }

    if ((n - m) % (k - 1) != 0) {
        cout << "NO\n";
        return;
    }

    int l = 0;
    {
        int c = 0;
        while (c < (k - 1) / 2) {
            c += del[l++];
        }
    }
    int r = n - 1;
    {
        int c = 0;
        while (c < (k - 1) / 2) {
            c += del[r--];
        }
    }

    for (int i = l; i <= r; ++i) {
        if (!del[i]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}