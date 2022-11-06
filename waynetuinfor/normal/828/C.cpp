#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
string t[maxn];
char ans[(int)(2e6 + 10)];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, len = 0; cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        cin >> t[i]; int k, x; cin >> k;
        while (k--) {
            cin >> x; --x; vec.push_back(make_pair(x, i));
            len = max(len, x + (int)t[i].length());
        }
    }
    sort(vec.begin(), vec.end());
    int p = -1;
    for (int i = 0; i < vec.size(); ++i) {
        int q = vec[i].first + t[vec[i].second].length();
        if (p > q) continue;
        for (int j = max(0, p - vec[i].first); j < t[vec[i].second].length(); ++j) ans[vec[i].first + j] = t[vec[i].second][j];
        p = vec[i].first + t[vec[i].second].length();
    }
    for (int i = 0; i < len; ++i) cout << (ans[i] ? ans[i] : 'a'); cout << endl;
    return 0;
}