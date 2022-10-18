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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> st = a;
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    int lo = -1, hi = n - 1;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        ll c = st[mid];
        vector<int> b(2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (b[j] % 2 == j) {
                    b[j]++;
                } else if (a[i] <= c) {
                    b[j]++;
                }
            }
        }
        if (max(b[0], b[1]) >= k) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << st[hi] << '\n';
    return 0;
}