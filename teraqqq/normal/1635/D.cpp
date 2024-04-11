#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

const int MOD = 1e9+7;

void solve() {
    int n, p; cin >> n >> p;
    vector<int> a;
    set<int> s;

    for (int i = n; i--; ) {
        int x; cin >> x;
        s.insert(x);
    }

    for (int x : s) {
        bool anc = false;
        for (int t = x; t != 0; ) {
            if (t % 2) {
                t /= 2;
            } else {
                if (t % 4 == 0) {
                    t /= 4;
                } else {
                    break;
                }
            }

            if (s.count(t)) {
                anc = true;
                break;
            }
        }

        if (!anc) a.push_back(x);
    }

    vector<int> cnt(max(60, p+3));
    for (int x : a) {
        int len = 0;
        for (int y = x; y != 0; y /= 2) ++len;
        cnt[len]++;
    }

    for (int i = 0; i < p; ++i) {
        cnt[i+2] = (cnt[i] + cnt[i+2]) % MOD;
        cnt[i+1] = (cnt[i] + cnt[i+1]) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i <= p; ++i) ans += cnt[i];
    cout << ans % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;
    while (t--) solve();
}