#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

bool cmp(int a, int b) {
    int a2 = a, b2 = b;
    while (a2 % 2 == 0) {
        a2 /= 2;
    }
    while (b2 % 2 == 0) {
        b2 /= 2;
    }
    return a2 < b2 || (a2 == b2 && a < b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> b(n + 1);
        vector<pair<int, int>> seg(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] == 0) {
                seg[i] = {i + 1, n};
            } else {
                int l1 = 0, r1 = n;
                while (r1 - l1 > 1) {
                    int mid = (l1 + r1) / 2;
                    if (b[i] + 1 > i / mid) {
                        r1 = mid;
                    } else {
                        l1 = mid;
                    }
                }

                int l2 = 0, r2 = n + 1;
                while (r2 - l2 > 1) {
                    int mid = (l2 + r2) / 2;
                    if (b[i] <= i / mid) {
                        l2 = mid;
                    } else {
                        r2 = mid;
                    }
                }

                l2 = max(l2, 1ll);
                r1 = min(r1, n);

                seg[i] = {r1, l2};
                //cout << seg[i].first << ' ' << seg[i].second << endl;
            }
        }
        vector<vector<int>> add(n + 1);
        for (int i = 1; i <= n; i++) {
            add[seg[i].first].push_back(i);
        }
        set<pair<int, int>> active;
        vector<int> perm(n + 1);
        for (int i = 1; i <= n; i++) {
            for (auto it : add[i]) {
                active.insert({seg[it].second, it});
            }
            //cout << active.begin()->second << ' ';
            perm[active.begin()->second] = i;
            active.erase(active.begin());
        }
        for (int i = 1; i <= n; i++) {
            cout << perm[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}