#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> graf[maxn];
int dep[maxn], cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    dep[0] = 1;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        dep[i] = dep[p] + 1;
        ++cnt[dep[i]];
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) ans += (cnt[i] & 1);
    cout << (++ans) << endl;
    return 0;
}