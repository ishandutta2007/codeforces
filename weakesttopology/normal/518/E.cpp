#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> fixed(n);
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s != "?") {
            a[i] = stoi(s);
            fixed[i] = true;
        }
    }
    bool good = true;
    for (int s = 0; s < k; ++s) {
        vector<pair<long long, int>> pts;
        pts.emplace_back(-inf, s - k);
        for (int i = s; i < n; i += k) {
            if (fixed[i]) {
                pts.emplace_back(a[i], i);
            }
            if (i + k >= n) {
                pts.emplace_back(+inf, i + k);
            }
        }
        int m = (int)size(pts);
        for (int j = 0; j + 1 < m; ++j) {
            if (pts[j].first + (pts[j + 1].second - pts[j].second) / k > pts[j + 1].first) {
                good = false;
                break;
            }
        }
        if (not good) break;
        for (int j = 0; j + 1 < m; ++j) {
            int l = pts[j].second, r = pts[j + 1].second;
            if (pts[j + 1].first <= 0) {
                long long last = pts[j + 1].first;
                for (int i = r - k; i > l; i -= k) {
                    a[i] = --last;
                }
            }
            else if (pts[j].first >= 0) {
                long long last = pts[j].first;
                for (int i = l + k; i < r; i += k) {
                    a[i] = ++last;
                }
            }
            else {
                long long last = max(-1LL * (r - k - l) / (2 * k), pts[j].first + 1);
                last = min(last, pts[j + 1].first - (r - k - l) / k);
                for (int i = l + k; i < r; i += k) {
                    a[i] = last++;
                }
            }
        }
    }
    if (not good) {
        cout << "Incorrect sequence\n";
        exit(0);
    }
    else {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << "\n "[i + 1 < n];
        }
    }
    exit(0);
}