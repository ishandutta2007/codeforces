#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

vector<pair<int, int>> ans;

void solve(int n) {
    if (n == 0) return;
    int sum = (n + 1) / 2;
    for (int i = sum; i >= 1; i--) {
        ans.push_back({i, sum + 1 - i});
    }
    --sum;
    for (int i = n - sum + 1; i <= n; i++) {
        ans.push_back({n + sum + 2 - i, i});
    }
}

int main() {
    int t; t = 1;
    while (t--) {
        int n; cin >> n;
        ans.clear();
        while (n % 3 != 2 && n > 0) {
            ans.push_back({n, n});
            --n;
        }
        solve(n - (n + 1) / 3);
        cout << ans.size() << "\n";
        for (auto &it : ans) {
            cout << it.first << " " << it.second << "\n";
        }
    }
}