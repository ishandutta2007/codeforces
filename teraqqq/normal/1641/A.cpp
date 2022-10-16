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
    int n, x, ans = 0; cin >> n >> x;
    map<int, int> cnt;
    vector<int> a(n);
    for (int& x : a) cin >> x, cnt[x]++;

    sort(a.begin(), a.end());

    for (ll t : a) {
        if (cnt[t] == 0) continue;
        vector<int> seq;

        while (t <= int(1e9) && cnt.count(t)) {
            seq.push_back(cnt[t]);
            cnt[t] = 0;
            t *= x;
        }

        // for (int u : seq) cout << u << ' '; cout << '\n';

        seq.push_back(0);
        for (int i = 0; i + 1 < seq.size(); ++i) {
            ans += seq[i] - min(seq[i], seq[i+1]);
            seq[i+1] -= min(seq[i], seq[i+1]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}