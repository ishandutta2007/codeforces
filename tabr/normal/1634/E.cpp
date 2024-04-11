#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define debug(...)
#endif

const int N = (int) 2e5 + 1;
vector<int> a[N];
string s[N];
unordered_set<int> b[N];
unordered_map<int, int> mp[N];
unordered_map<int, unordered_set<int>> at;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        a[i] = vector<int>(n);
        s[i] = string(n, '?');
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (mp[i].count(a[i][j])) {
                s[i][j] = 'L';
                s[i][mp[i][a[i][j]]] = 'R';
                mp[i].erase(mp[i].find(a[i][j]));
            } else {
                mp[i][a[i][j]] = j;
            }
        }
        for (auto p : mp[i]) {
            b[i].emplace(p.first);
            at[p.first].emplace(i);
        }
    }
    while (!at.empty()) {
        int orig = at.begin()->first;
        int now = orig;
        do {
            if (at[now].empty()) {
                cout << "NO" << '\n';
                return 0;
            }
            int who = *at[now].begin();
            int nxt = *b[who].begin();
            if (nxt == now) {
                nxt = *next(b[who].begin());
            }
            s[who][mp[who][now]] = 'L';
            s[who][mp[who][nxt]] = 'R';
            b[who].erase(now);
            b[who].erase(nxt);
            at[now].erase(who);
            at[nxt].erase(who);
            if (at[now].empty()) {
                at.erase(at.find(now));
            }
            if (at[nxt].empty()) {
                at.erase(at.find(nxt));
            }
            now = nxt;
        } while (now != orig);
    }
    cout << "YES" << '\n';
    for (int i = 0; i < m; i++) {
        cout << s[i] << '\n';
    }
    return 0;
}