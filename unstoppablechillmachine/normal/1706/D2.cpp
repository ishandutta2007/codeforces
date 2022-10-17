#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 1e5 + 10;
const int B = static_cast<int>(sqrt(1e5)) + 10;
vector<int> colors[N];
int cc[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < N; i++) {
            colors[i] = {};
            cc[i] = 0;
        }
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int answer = 1e5;
        for (int mx_value = 1000; mx_value >= 0; mx_value--) {
            bool ok = true;
            int mn_value = mx_value, cur = 1;
            for (int i = 0; i < n; i++) {
                while (a[i] / cur > mx_value && cur < k) {
                    cur++;
                }
                if (a[i] / cur > mx_value) {
                    ok = false;
                    break;
                }
                mn_value = min(mn_value, a[i] / cur);
            }
            if (ok) {
                answer = min(answer, mx_value - mn_value);
            }
        }
        int r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= min(k, 100); j++) {
                if (j == 1 || a[i] / j != a[i] / (j - 1)) {
                    colors[a[i] / j].push_back(i);
                }
            }
            r = max(r, a[i] / min(k, 100));
        }
        for (int i = 0; i <= r; i++) {
            for (auto id : colors[i]) {
                cc[id]++;
            }
        }
        answer = min(answer, r);
        int cnt = n;
        //cout << "R " << r << endl;
        for (int i = 1; i <= 1e5; i++) {
            for (auto id : colors[i - 1]) {
                cc[id]--;
                if (cc[id] == 0) {
                    cnt--;
                }
            }
            while (r < 1e5 && cnt < n) {
                r++;
                for (auto id : colors[r]) {
                    cc[id]++;
                    if (cc[id] == 1) {
                        cnt++;
                    }
                }
            }
            if (cnt < n) {
                break;
            }
            answer = min(answer, r - i);
        }
        cout << answer << '\n';
    }
    return 0;
}