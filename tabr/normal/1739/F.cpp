#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> a;
    for (int i = 0; i < n; i++) {
        int c;
        string s;
        cin >> c >> s;
        deque<char> d;
        d.emplace_back(s[0]);
        d.emplace_back(s[1]);
        int now = 1;
        for (int j = 2; j < (int) s.size(); j++) {
            int p = -1;
            for (int k = 0; k < (int) d.size(); k++) {
                if (s[j] == d[k]) {
                    p = k;
                }
            }
            if (p == -1) {
                if (now == 0) {
                    d.emplace_front(s[j]);
                } else if (now == (int) d.size() - 1) {
                    d.emplace_back(s[j]);
                    now++;
                } else {
                    now = -1;
                    break;
                }
            } else {
                if (abs(p - now) != 1) {
                    now = -1;
                    break;
                }
                now = p;
            }
        }
        if (now != -1) {
            string t;
            for (char b : d) {
                t += b;
            }
            a[t] += c;
            reverse(t.begin(), t.end());
            a[t] += c;
        }
    }
    debug(a);
    vector<map<string, long long>> dp(1 << 12);
    vector<map<string, pair<int, string>>> pre(1 << 12);
    dp[0][string()] = 0;
    pre[0][string()] = make_pair(-1, "");
    for (int mask = 0; mask < (1 << 12); mask++) {
        for (auto [t, c] : dp[mask]) {
            for (int i = 0; i < 12; i++) {
                if (mask & (1 << i)) {
                    continue;
                }
                int nmask = mask | (1 << i);
                string nt = t + (char) ('a' + i);
                while (!nt.empty()) {
                    auto iter = a.lower_bound(nt);
                    if (iter == a.end()) {
                        nt.erase(nt.begin());
                        continue;
                    }
                    string z = iter->first;
                    if (z.size() < nt.size()) {
                        nt.erase(nt.begin());
                        continue;
                    }
                    z.resize(nt.size());
                    if (nt != z) {
                        nt.erase(nt.begin());
                        continue;
                    }
                    break;
                }
                long long nc = c;
                for (int j = 0; j < (int) nt.size(); j++) {
                    string z = nt.substr(j);
                    if (a.count(z)) {
                        nc += a[z];
                    }
                }
                if (dp[nmask][nt] <= nc) {
                    dp[nmask][nt] = nc;
                    pre[nmask][nt] = make_pair(i, t);
                }
            }
        }
    }
    long long best = -1;
    string s;
    for (auto [t, c] : dp.back()) {
        if (c > best) {
            best = c;
            s = t;
        }
    }
    debug(best);
    debug(dp.back());
    string ans;
    int now = (1 << 12) - 1;
    while (now > 0) {
        int i = pre[now][s].first;
        s = pre[now][s].second;
        now ^= 1 << i;
        ans += (char) ('a' + i);
    }
    cout << ans << '\n';
    return 0;
}