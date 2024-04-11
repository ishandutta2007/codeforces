#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int l[maxn], r[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        vec.push_back(make_pair(l[i], -1));
        vec.push_back(make_pair(r[i], 1));
    }
    sort(vec.begin(), vec.end());
    int cur = 0, ans = 0;
    for (auto i : vec) {
        cur -= i.second;
        ans = max(ans, cur);
    }
    if (ans > 2) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}