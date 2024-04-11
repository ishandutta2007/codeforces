#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        bool f = true;
        if (2 * m + 1 > n) {
            f = false;
        }
        else {
            vector<int> b;
            int pos_a = 0, pos_b = n - (m + 1);
            for (int i = 0; i < 2 * m + 1; ++i) {
                if (i % 2 == 0) {
                    b.emplace_back(a[pos_b]);
                    ++pos_b;
                }
                else {
                    b.emplace_back(a[pos_a]);
                    ++pos_a;
                }
            }
            for (int i = 1; i < 2 * m + 1; i += 2) {
                if (b[i] >= b[i - 1] || b[i] >= b[i + 1])
                    f = false;
            }
        }
        if (f)
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    vector<int> b;
    int pos_a = 0, pos_b = n - (l + 1);
    for (int i = 0; i < 2 * l + 1; ++i) {
        if (i % 2 == 0) {
            b.emplace_back(a[pos_b]);
            ++pos_b;
        }
        else {
            b.emplace_back(a[pos_a]);
            ++pos_a;
        }
    }
    for (int i = pos_a; i < n - (l + 1); ++i) {
        b.emplace_back(a[i]);
    }
    for (auto &c : b) {
        cout << c << " ";
    }
}