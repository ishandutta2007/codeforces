#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
vector<vector<int>> mp;
bitset<maxn> bt;
int l[maxn], r[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        vector<int> tmp; int x;
        for (int j = 0; j < m + 2; ++j) tmp.push_back((int)(s[j] - '0'));
        mp.push_back(tmp);
    }
    reverse(mp.begin(), mp.end());
    int high = 0;
    for (int i = 0; i < n; ++i) {
        l[i] = m + 1; r[i] = 0;
        bool have = false;
        for (int j = 0; j < m + 2; ++j) if (mp[i][j]) {
            have = true;
            l[i] = min(l[i], j); r[i] = max(r[i], j);
        }
        if (have) high = i;
    }
    ++high;
    int ans = INT_MAX;
    for (int s = 0; s < (1 << high); ++s) {
        bt.reset();
        int cur = 0;
        for (int i = 0; i < high; ++i) if ((1 << i) & s) bt[i] = true;
        bool p = true;
        for (int i = 0; i < high; ++i) {
            if (p) cur += r[i];
            else cur += m + 1 - l[i];
            if (i != high - 1) {
                if (bt[i]) {
                    if (p) cur += r[i];
                    else cur += l[i];
                    p = true;
                } else {
                    if (p) cur += m + 1 - r[i];
                    else cur += m + 1 - l[i];
                    p = false;
                }
            }
            
        }
        ans = min(ans, cur);
    }
    cout << ans + high - 1 << endl;
    return 0;
}