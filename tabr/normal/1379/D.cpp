#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, h, m, k;
    cin >> n >> h >> m >> k;
    ll d = m / 2;
    vector<ll> t(n);
    vector<ll> st(n * 3);
    for (int i = 0; i < n; i++) {
        ll hh, mm;
        cin >> hh >> mm;
        t[i] = mm % d;
        st[i] = t[i];
        st[i + n] = (t[i] - k + d) % d;
        st[i + n * 2] = (t[i] + k) % d;
    }
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    ll l = st.size();
    for (int i = 0; i < l; i++) {
        st.emplace_back(st[i] + d);
    }
    vector<ll> a(2 * l);
    for (int i = 0; i < n; i++) {
        int j = lower_bound(st.begin(), st.end(), t[i]) - st.begin();
        a[j]++;
        a[j + l]++;
    }
    vector<ll> s = a;
    for (int i = 1; i < l * 2; i++) {
        s[i] += s[i - 1];
    }
    ll ans = 0, cnt = 1e18;
    for (int i = 0; i < l; i++) {
        ll x = st[i];
        int j = lower_bound(st.begin(), st.end(), x + k) - st.begin();
        if (st[j] != x + k) {
            continue;
        }
        j--;
        if (cnt > s[j] - s[i]) {
            cnt = s[j] - s[i];
            ans = st[i];
        }
    }
    vector<ll> b;
    for (int i = 0; i < n; i++) {
        if ((ans < t[i] && t[i] < ans + k) || (ans < t[i] + d && t[i] + d < ans + k)) {
            b.emplace_back(i + 1);
        }
    }
    ans += k;
    ans %= d;
    cout << cnt << " " << ans << '\n';
    for (ll i : b) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}