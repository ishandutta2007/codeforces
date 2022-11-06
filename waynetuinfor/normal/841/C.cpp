#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn], ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    vector<pair<int, int>> vec;
    for (int i = 1; i <= m; ++i) cin >> b[i], vec.push_back(make_pair(b[i], i));
    sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
    sort(a + 1, a + m + 1);
    for (int i = 0; i < vec.size(); ++i) ans[vec[i].second] = a[i + 1];
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' '; cout<< endl;
    return 0;
}