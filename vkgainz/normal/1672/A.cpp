#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = accumulate(a.begin(), a.end(), 0) - n;
        if (sum % 2) cout << "errorgorn\n";
        else cout << "maomao90\n";
    }
}