#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, n;
    cin >> l >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i]; a.push_back(l);
    int lo = 1, hi = l;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        int x = 0, ok = 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] - x > mid) {
                ok = 0;
                break;
            }
            x = min(a[i + 1], x + mid);
        }
        if(x == l && ok) hi = mid;
        else lo = mid + 1;
    }
    int r = lo;
    lo = 1, hi = l;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int x = 0, y = 0, ok = 1;
        for(int i = 0; i < n; ++i) {
            x = max(a[i], x + mid);
            y = min(a[i + 1], y + r);
            if(x > y) {
                ok = 0;
                break;
            }
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    int f = lo;
    // f, r
    vector<int> ax(n + 1), ay(n + 1);
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i) {
        x = max(a[i], x + f);
        y = min(a[i + 1], y + r);
        assert(x <= y);
        ax[i + 1] = x;
        ay[i + 1] = y;
    }
    vector<pair<int,int>> ans;
    int p = l;
    for(int i = n - 1; i >= 0; --i) {
        int nxt = ax[i];
        if(p - ax[i] > r) {
            assert(p - r <= ay[i]);
            nxt = p - r;
        }
        ans.push_back({nxt, p});
        p = nxt;
    }
    reverse(ans.begin(), ans.end());
    for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
}