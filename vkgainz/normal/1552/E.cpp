#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> pos(n);
    vector<int> c(n * k);
    for(int i = 0; i < n * k; i++) {
        cin >> c[i];
        --c[i];
        pos[c[i]].push_back(i);
    }
    vector<pair<int, int>> ans(n);
    for(int i = 0; i < n; i += k - 1) {
        int st = i, en = i + k - 2;
        en = min(en, n - 1);
        vector<int> seen(n, -1);
        vector<bool> left(n);
        for(int x = st; x <= en; x++)
            left[x] = true;
        for(int x = 0; x < n * k; x++) {
            if(!left[c[x]]) continue;
            if(seen[c[x]] != -1) {
                ans[c[x]] = {seen[c[x]], x};
                seen.clear();
                seen.resize(n, -1);
                left[c[x]] = false;
            }
            else {
                seen[c[x]] = x;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i].first +1 << " " << ans[i].second + 1 << "\n";
    }
}