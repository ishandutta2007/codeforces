#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        set<int> s;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            s.insert(a);
        }

        int mex = 0, max = *--s.end();
        while (s.count(mex) > 0) {
            ++mex;
        }

        if (mex == (int) s.size()) {
            cout << s.size() + k << "\n";
        } else {
            cout << s.size() + (k > 0 && s.count((mex + max + 1) / 2) == 0) << "\n";
        }
    }
}