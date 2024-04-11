#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int c[maxn], cnt[maxn];
set<int> s[maxn];
bool ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a; cin >> n >> a;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 1; i <= 1e6; ++i) s[0].insert(i);
    int cnta = 0;
    memset(ans, true, sizeof(ans));
    for (int i = 0; i < n; ++i) {
        if (c[i] == a) {
            ++cnta;
            for (auto j : s[cnta - 1]) ans[j] = false;
        } else {
            if (!ans[c[i]]) continue;
            ++cnt[c[i]];
            s[cnt[c[i]] - 1].erase(c[i]);
            s[cnt[c[i]]].insert(c[i]);
        }
    } 
    for (int i = 1; i <= 1e6; ++i) if (i != a && ans[i]) return cout << i << endl, 0;
    cout << "-1\n";
    return 0;
}