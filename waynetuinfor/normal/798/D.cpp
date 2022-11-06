#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> p;
    for (int i = 0; i < n; ++i) p.push_back(i);
    sort(p.begin(), p.end(), [=](const int& i, const int& j) {
        return a[i] > a[j];
    });
    vector<int> ans;
    ans.push_back(p[0]);
    for (int i = 1; i + 1 < p.size(); i += 2) {
        if (b[p[i]] > b[p[i + 1]]) ans.push_back(p[i]);
        else ans.push_back(p[i + 1]);
    }
    if (!(n & 1)) ans.push_back(p[p.size() - 1]);
    cout << ans.size() << '\n';
    for (int i : ans) cout << i + 1 << ' ';
    return 0;
}