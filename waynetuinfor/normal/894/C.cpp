#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
bool v[maxn];

int main() {
    int m; cin >> m;
    int g = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    if (g != a[0]) return cout << "-1" << endl, 0;
    vector<int> ans; 
    for (int i = 0; i < m; ++i) {
        ans.push_back(a[i]);
        ans.push_back(a[0]);
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}