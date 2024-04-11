#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> vp(m), vs(m);
    int ans = 0;
    for (int i = 0, j = 0; i < m; ++i) {
        while (s[j] != t[i]) ++j;
        vp[i] = j++;
    }
    for (int i = m, j = n-1; i--;) {
        while (s[j] != t[i]) --j;
        vs[i] = j--;
    }

    for (int i = 1; i < m; ++i) {
        ans = max(ans, vs[i] - vp[i-1]);
    }
    cout << ans << endl;
}