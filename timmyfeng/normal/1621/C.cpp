#include <bits/stdc++.h>
using namespace std;

int query(int a) {
    cout << "? " << a << endl;
    int result; cin >> result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> ans(n + 1);

        for (int i = 1; i <= n; ++i) {
            if (ans[i] == 0) {
                int prv = query(i);
                while (ans[prv] == 0) {
                    ans[prv] = query(i);
                    prv = ans[prv];
                }
            }
        }

        cout << "! ";
        for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
        cout << endl;
    }
}