#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> mn(1000100), mx(1000100);
    ll ans = 0;
    ll ok = 0;
    rep(i, 0, n) {
        int l;
        cin >> l;
        int a = 1e9, b = -1e9;
        vector<int> s;
        rep(j, 0, l) {
            int x;
            cin >> x;
            a = min(a, x);
            b = max(b, x);
            s.emplace_back(x);
        }
        int m = s[0];
        bool d = false;
        rep(j, 0, l) {
            if (m < s[j])
                d = true;
            else
                m = s[j];
        }
        if (d)
            ok++;
        else {
            mn[a]++;
            mx[b]++;
        }
    }
    ans = ok * ok + (n - ok) * ok * 2;
    rep(i, 1, 1000001) {
        mn[i] += mn[i - 1];
        ans += mn[i - 1] * mx[i];
    }

    cout << ans << endl;
    return 0;
}