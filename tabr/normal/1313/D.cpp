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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> l(n), r(n);
    vector<int> st;
    map<int, vector<int>> add, del;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        st.emplace_back(l[i]);
        st.emplace_back(r[i] + 1);
        add[l[i]].emplace_back(i);
        del[r[i] + 1].emplace_back(i);
    }
    vector<int> dp(1 << k);
    vector<int> cur(k, -1);
    int all = 0;
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    for (int i = 0; i < st.size() - 1; i++) {
        int pos = st[i], nxt = st[i + 1];
        int dif = nxt - pos;
        vector<int> a = add[pos], b = del[pos];
        vector<int> ndp(1 << k);
        int nall = all;
        for (int j : b) {
            for (int l = 0; l < k; l++) {
                if (cur[l] == j) {
                    cur[l] = -1;
                    nall &= ~(1 << l);
                    break;
                }
            }
        }
        for (int j = 0; j < (1 << k); j++) {
            ndp[j & nall] = max(ndp[j & nall], dp[j]);
        }
        int mall = nall;
        for (int j : a) {
            for (int l = 0; l < k; l++) {
                if (cur[l] == -1) {
                    cur[l] = j;
                    mall |= (1 << l);
                    break;
                }
            }
        }
        for (int j = 0; j < (1 << k); j++) {
            if ((j | mall) == mall && (j | nall) != nall) {
                ndp[j] = ndp[j & nall];
            }
        }
        nall = mall;
        for (int j = 0; j < (1 << k); j++) {
            if (__builtin_popcount(j) & 1) {
                ndp[j] += dif;
            }
            if ((j | nall) != nall) {
                ndp[j] = 0;
            }
        }
        all = nall;
        swap(ndp, dp);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}