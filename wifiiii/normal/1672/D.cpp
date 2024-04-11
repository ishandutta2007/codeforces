#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        vector<vector<int>> pa(n), pb(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        for(int i = 0; i < n; ++i) cin >> b[i], --b[i];
        if(a.back() != b.back()) {
            cout << "NO\n";
            continue;
        }
        vector<int> cnt(n);
        int nxt = a.back(), ok = 1, i = n - 2, j = n - 2;
        while(j >= 0) {
            if(a[i] == b[j]) {
                nxt = a[i];
                --j, --i;
            } else {
                if(nxt == b[j]) {
                    nxt = b[j];
                    ++cnt[b[j]];
                    --j;
                    continue;
                }
                if(cnt[a[i]]) {
                    --cnt[a[i]];
                    --i;
                    continue;
                }
                ok = 0;
                break;
            }
        }
        while(i >= 0) {
            if(!cnt[a[i]]) {
                ok = 0;
                break;
            }
            --cnt[a[i]];
            --i;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}