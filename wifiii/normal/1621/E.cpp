#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        a.resize(m);
        vector<ll> sum(m);
        vector<vector<pair<int,int>>> b(m);
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            int sz;
            cin >> sz;
            b[i].resize(sz);
            ll s = 0;
            for(int j = 0; j < sz; ++j) {
                int x;
                cin >> x;
                b[i][j] = {x, cnt++};
                s += x;
            }
            sum[i] = s;
        }
        vector<int> ord(m);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return sum[i] * b[j].size() > sum[j] * b[i].size();});
        vector<int> rord(m);
        for(int i = 0; i < m; ++i) rord[ord[i]] = i;
        vector<int> pre(m), suf(m + 1);
        for(int i = 0; i < m; ++i) {
            if(1ll * a[i] * b[ord[i]].size() >= sum[ord[i]]) {
                pre[i] = 1;
            } else {
                break;
            }
        }
        suf[m] = 1;
        for(int i = m - 1; i >= 0; --i) {
            if(1ll * a[i] * b[ord[i]].size() >= sum[ord[i]]) {
                suf[i] = 1;
            } else {
                break;
            }
        }
        vector<int> l(m), r(m);
        r[m - 1] = m - 1;
        for(int i = m - 1; i >= 1; --i) {
            if(1ll * a[i] * b[ord[i - 1]].size() >= sum[ord[i - 1]]) {
                r[i - 1] = r[i];
            } else {
                r[i - 1] = i - 1;
            }
        }
        for(int i = 1; i < m; ++i) {
            if(1ll * a[i - 1] * b[ord[i]].size() >= sum[ord[i]]) {
                l[i] = l[i - 1];
            } else {
                l[i] = i;
            }
        }
        vector<int> ans(cnt);
        for(int i = 0; i < m; ++i) {
            int k = rord[i], sz = b[i].size();
            ll s = sum[i];
            for(auto [w, id] : b[i]) {
                // s / sz -> (s - w) / (sz - 1)
                int lo = -1, hi = m - 1;
                while(lo < hi) {
                    int mid = (lo + hi + 1) / 2;
                    if(1ll * a[mid] * (sz - 1) >= s - w) {
                        lo = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                if(lo == -1) {
                    continue;
                }
                // k -> lo
                if(k > lo) {
                    if((!lo || pre[lo - 1]) && suf[k + 1] && r[lo] >= k) {
                        ans[id] = 1;
                    }
                }
                if(k < lo) {
                    if((!k || pre[k - 1]) && suf[lo + 1] && l[lo] <= k) {
                        ans[id] = 1;
                    }
                }
                if(k == lo) {
                    if((!lo || pre[lo - 1]) && suf[lo + 1]) {
                        ans[id] = 1;
                    }
                }
            }
        }
        for(int i = 0; i < cnt; ++i) cout << ans[i]; cout << '\n';
    }
}