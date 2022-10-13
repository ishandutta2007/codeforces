#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>
#include <array>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        if (b < a - 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> l, r; 
        l.push_back(a);
        r.push_back(b);
        for (int i = 1; i < a; i++) {
            if (i != b) {
                r.push_back(i);
            }
        }
        for (int i = b + 1; i <= n; i++) {
            if (i != a) {
                l.push_back(i);
            }
        }
        if (l.size() > n / 2  || r.size() > n / 2) {
            cout << -1 << "\n";
        } else {
            for (int i = min(a, b) + 1; i < max(a, b); i++) {
                if (l.size() < n / 2) {
                    l.push_back(i);
                } else {
                    r.push_back(i);
                }
            }
            vector<int> ans;
            ans.insert(ans.begin(), l.begin(), l.end());
            ans.insert(ans.end(), r.begin(), r.end());
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}