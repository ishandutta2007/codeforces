#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int z[maxn], cnt[maxn], ans[maxn];

int32_t main() {
    string s; cin >> s;
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (r > i) z[i] = min(r - i + 1, z[z[l] - (r - i + 1)]);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
    }
    // for (int i = 0; i < s.size(); ++i) cout << z[i] << ' '; cout << endl;
    for (int i = 0; i < maxn; ++i) ++cnt[z[i]];
    for (int i = 1; i < maxn; ++i) cnt[i] += cnt[i - 1];
    for (int i = s.size() - 1; i >= 0; --i) {
        int len = s.size() - i;
        if (z[i] != len) continue;
        ans[len] = cnt[maxn - 1] - cnt[len - 1] + 1;
    }
    ans[s.size()] = 1;
    vector<int> cand;
    for (int i = 0; i < maxn; ++i) if (ans[i] > 0) cand.push_back(i);
    cout << (int)cand.size() << endl;
    for (int i : cand) cout << i << ' ' << ans[i] << endl;
    return 0;
}