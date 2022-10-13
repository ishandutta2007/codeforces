#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>
#include <array>

using namespace std;

bool test(vector<int> a, int x) {
    vector<int> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != x)
            b.push_back(a[i]);
    }
    bool ans = true;
    for (int i = 0; i < b.size(); i++) {
        ans &= (b[i] == b[b.size() - i - 1]);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (test(a, -1)) {
            cout << "YES" << "\n";
            continue;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != a[n - i - 1]) {
                if (test(a, a[i]) || test(a, a[n - i - 1])) {
                    cout << "YES" << "\n";
                } else {
                    cout << "NO" << "\n";
                }
                break;
            }
        }
    }
}