#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int s[maxn];

int main() {
    int n, m; cin >> n >> m;
    while (n--) {
        int l, r; cin >> l >> r;
        s[l]++, s[r + 1]--;
    }
    for (int i = 1; i <= m; ++i) s[i] += s[i - 1];
    vector<int> ans;
    for (int i = 1; i <= m; ++i) if (s[i] == 0) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}