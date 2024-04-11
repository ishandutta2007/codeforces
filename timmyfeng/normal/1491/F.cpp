#include <bits/stdc++.h>
using namespace std;

int query(vector<int> l, vector<int> r) {
    cout << "? " << l.size() << " " << r.size() << endl;
    for (auto i : l) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : r) {
        cout << i << " ";
    }
    cout << endl;

    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int u = 2;
        for ( ; u <= n; ++u) {
            vector<int> p(u - 1);
            iota(p.begin(), p.end(), 1);
            if (query(p, {u}) != 0) {
                break;
            }
        }

        int l = 1, r = u - 1;
        while (l < r) {
            int m = (l + r) / 2;
            vector<int> p(m);
            iota(p.begin(), p.end(), 1);
            if (query(p, {u}) != 0) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        set<int> ans;
        for (int i = 1; i <= n; ++i) {
            ans.insert(i);
        }

        ans.erase(l), ans.erase(u);

        for (int i = u + 1; i <= n; ++i) {
            if (query({u}, {i}) != 0) {
                ans.erase(i);
            }
        }

        cout << "! " << ans.size() << " ";
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}