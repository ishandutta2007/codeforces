#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <algorithm>
#include <deque>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> in(n + 1);
    vector<int> left;
    for (int i = 0; i < n; i++) {
        if (a[i] > n) {
            left.push_back(a[i]);
        } else {
            if (!in[a[i]]) {
                in[a[i]] = true;
            } else {
                left.push_back(a[i]);
            }
        }
    }
    sort(left.begin(), left.end());
    vector<int> make;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            make.push_back(i);
        }
    }
    bool work = true;
    for (int i = 0; i < make.size(); i++) {
        work &= (make[i] * 2 + 1 <= left[i]);
    }
    if (work) cout << make.size() << "\n";
    else cout << -1 << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}