#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using ll = long long;

template<class T>
using vec = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    rep(i, min(n, 30)) {
        string t = s;
        rep(j, n - i) {
            t[i + j] = max(s[j], s[i + j]);
        }
        ans = max(ans, t);
    }
    while (ans.size() > 1 && ans[0] == '0') {
        ans.erase(ans.begin());
    }
    cout << ans << endl;
    return 0;
}