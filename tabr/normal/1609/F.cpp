#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    array<int, 60> ee;
    for (int i = 0; i < 60; i++) {
        ee[i] = 0;
    }
    function<long long(int, int)> f = [&](int l, int r) {
        if (l >= r) {
            return 0LL;
        } else if (l + 1 == r) {
            return 1LL;
        }
        int p = (l + r) / 2;
        long long res = f(l, p) + f(p, r);
        vector<pair<long long, long long>> sl, sr;
        for (int i = p - 1; i >= l; i--) {
            if (sl.empty()) {
                sl.emplace_back(a[i], a[i]);
            } else {
                sl.emplace_back(min(sl.back().first, a[i]), max(sl.back().second, a[i]));
            }
        }
        for (int i = p; i < r; i++) {
            if (sr.empty()) {
                sr.emplace_back(a[i], a[i]);
            } else {
                sr.emplace_back(min(sr.back().first, a[i]), max(sr.back().second, a[i]));
            }
        }
        vector<long long> mnr, mxr;
        for (auto [mn, mx] : sr) {
            mnr.emplace_back(mn);
            mxr.emplace_back(mx);
        }
        vector<long long> c(mnr.size() + 1);
        for (int i = (int) mnr.size() - 1; i >= 0; i--) {
            c[i] = c[i + 1];
            if (__builtin_popcountll(mnr[i]) == __builtin_popcountll(mxr[i])) {
                c[i]++;
            }
        }
        // vector<array<int, 60>> mnb(mnr.size() + 1);
        // vector<array<int, 60>> mxb(mnr.size() + 1);
        // mnb[0] = mxb[0] = ee;
        // for (int i = 0; i < (int) mnr.size(); i++) {
        //     mnb[i + 1] = mnb[i];
        //     mxb[i + 1] = mxb[i];
        //     mnb[i + 1][__builtin_popcountll(mnr[i])]++;
        //     mxb[i + 1][__builtin_popcountll(mxr[i])]++;
        // }
        debug(l, p, r);
        debug(mnr);
        debug(mxr);
        debug(res);
        vector<int> mnb_itmx(60), mxb_itmx(60);
        vector<int> mnb_itmn(60), mxb_itmn(60);
        int nowmn = 0, nowmx = 0;
        for (auto [mn, mx] : sl) {
            int itmn = (int) (mnr.rend() - upper_bound(mnr.rbegin(), mnr.rend(), mn));
            int itmx = (int) (lower_bound(mxr.begin(), mxr.end(), mx) - mxr.begin());
            if (__builtin_popcountll(mn) == __builtin_popcountll(mx)) {
                res += min(itmn, itmx);
            }
            res += c[max(itmn, itmx)];
            while (nowmn < itmn) {
                mnb_itmn[__builtin_popcountll(mnr[nowmn])]++;
                mxb_itmn[__builtin_popcountll(mxr[nowmn])]++;
                nowmn++;
            }
            while (nowmx < itmx) {
                mnb_itmx[__builtin_popcountll(mnr[nowmx])]++;
                mxb_itmx[__builtin_popcountll(mxr[nowmx])]++;
                nowmx++;
            }
            if (itmn < itmx) {
                int cnt = __builtin_popcountll(mx);
                res += mnb_itmx[cnt] - mnb_itmn[cnt];
            } else {
                int cnt = __builtin_popcountll(mn);
                res += mxb_itmn[cnt] - mxb_itmx[cnt];
            }
        }
        debug(res);
        return res;
    };
    cout << f(0, n) << '\n';
    return 0;
}