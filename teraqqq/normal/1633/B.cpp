#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

void solve() {
    string s; cin >> s;

    vector<int> cnt(2);
    int ans = 0;
    for (char c : s) cnt[c - '0']++;

    if (cnt[0] != cnt[1]) {
        cout << min(cnt[0], cnt[1]) << '\n';
    } else {
        cout << max(0, cnt[0] - 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}