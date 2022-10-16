#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> x(n);

    int u = (n + k - 2) / (k - 1);

    vector<int> cnt(k+1), used(n);
    vector<int> l(n), r(n);

    int ptr = 1;
    for (int i = 1; i <= n * k; ++i) {
        int c; cin >> c; c -= 1;
        x[c].push_back(i);
        if (used[c]) continue;
        
        if (x[c].size() >= 2 && cnt[x[c].size()] < u) {
            l[c] = *(x[c].end() - 2);
            r[c] = *(x[c].end() - 1);
            used[c] = 1;
            cnt[x[c].size()] ++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << l [i] << ' ' << r[i] << endl;
    }
}