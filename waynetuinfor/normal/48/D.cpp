#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], ans[maxn];
vector<int> pos[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int t = 0;
    for (int i = maxn - 1; i >= 1; --i) {
        while (pos[i].size()) {
            ++t;
            for (int j = i; j >= 1; --j) {
                if (pos[j].size() == 0) return cout << "-1" << endl, 0;
                ans[pos[j].back()] = t; pos[j].pop_back();
            }
        }
    }
    cout << t << endl;
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}