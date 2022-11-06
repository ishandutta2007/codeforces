#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
map<int, long long> ans;

void init(int n) {
    map<int, long long> pre;
    for (int i = 1; i <= n; ++i) {
        ++ans[a[i]];
        map<int, long long> cur;
        cur[a[i]] = 1;
        for (auto it = pre.begin(); it != pre.end(); ++it) {
            ans[__gcd(it->first, a[i])] += it->second;
            cur[__gcd(it->first, a[i])] += it->second;
        }
        pre = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init(n);
    int q; cin >> q; while (q--) {
        int x; cin >> x;
        cout << ans[x] << endl;
    }    
    return 0;
}