#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            sum += x;
        }
        vector<int> kek = {sum};
        bool ok = true;
        while (!kek.empty()) {
            int w = kek.back();
            kek.pop_back();
            if (cnt.count(w) && cnt[w] > 0) {
                cnt[w]--;
            } else if (w > 1) {
                kek.push_back(w / 2);
                kek.push_back((w + 1) / 2);
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (auto [_, c] : cnt) {
                if (c != 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}