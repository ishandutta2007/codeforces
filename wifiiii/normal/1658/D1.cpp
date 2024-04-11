#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        vector<int> a(r - l + 1);
        for(int i = 0; i < r - l + 1; ++i) cin >> a[i];
        int ans = -1;
        auto check = [&](int x) {
            if(ans != -1) return;
            vector<int> vis(r - l + 1);
            for(int i : a) {
                i ^= x;
                if(i > r || i < l) return;
                if(vis[i - l]) return;
                vis[i - l] = 1;
            }
            ans = x;
        };
        sort(a.begin(), a.end());
        int mb = 1 << 30;
        for(int i = 0, j = 0; i < a.size(); i = j) {
            j = i + 1;
            while(j < a.size() && a[j] - a[j - 1] == 1) ++j;
            int sz = j - i, lb = sz & -sz;
            mb = min(mb, lb);
        }
        for(int i = 0, j = 0; i < a.size(); i = j) {
            j = i + 1;
            while(j < a.size() && a[j] - a[j - 1] == 1) ++j;
            int sz = j - i, lb = sz & -sz;
            if(mb == lb) {
                check(a[i] ^ l);
                check(a[j - 1] ^ l);
                check(a[i] ^ r);
                check(a[j - 1] ^ r);
            }
        }
        assert(ans != -1);
        cout << ans << '\n';
    }
}