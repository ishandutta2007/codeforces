#include <bits/stdc++.h>
#define int long long
using namespace std;

int fac[51];
map<int, bool> lc;

int32_t main() {
    vector<int> all;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            vector<int> v;
            for (int k = 0; k < j; ++k) v.push_back(4);
            for (int k = 0; k < i - j; ++k) v.push_back(7);
            do {
                int t = 0, c = 1;
                for (int k : v) t += c * k, c *= 10;
                all.push_back(t);
            } while (next_permutation(v.begin(), v.end()));
        }
    }
    sort(all.begin(), all.end());
    fac[0] = 1;
    for (int i = 1; i <= 50; ++i) fac[i] = fac[i - 1] * i;
    vector<int> v;
    int n, k; cin >> n >> k;
    if (n <= 20 && fac[n] < k) return cout << "-1" << endl, 0;
    --k;
    for (int i : all) if (i <= n) v.push_back(i);
    int z = -1;
    for (int i = n; i >= 1; --i) {
        int c = n - i;
        if (c * fac[c] >= k) {
            z = i;
            break;
        }
    } 
    if (z == -1) z = 1;
    // cout << "z = " << z << endl;
    int ans = 0;
    for (int i : v) if (i < z) ++ans;
    for (int i : v) lc[i] = true;
    int cur = 0;
    vector<int> ch;
    for (int i = z; i <= n; ++i) ch.push_back(i);
    for (int i = z; i <= n; ++i) {
        int d = 31, p = 0;
        while (d--) {
            if (p + (1 << d) < ch.size()) {
                int u = ch[p + (1 << d)];
                int c = p + (1 << d);
                if (cur + c * fac[n - i] <= k) p += (1 << d);
            }
        }
        cur += p * fac[n - i];
        // cout << "i = " << i << " ch[p] = " << ch[p] << endl;
        if (lc[i] && lc[ch[p]]) ++ans;
        vector<int> nch;
        for (int j : ch) if (j != ch[p]) nch.push_back(j);
        ch = nch;
    }
    cout << ans << endl;
}