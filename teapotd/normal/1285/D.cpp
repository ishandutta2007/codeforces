#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

vector<array<int, 2>> trie;

int dfs(int i, int d) {
    if (!trie[i][0] && !trie[i][1]) {
        return 0;
    }
    if (!trie[i][0]) {
        return dfs(trie[i][1], d-1);
    }
    if (!trie[i][1]) {
        return dfs(trie[i][0], d-1);
    }

    int a = dfs(trie[i][0], d-1);
    int b = dfs(trie[i][1], d-1);
    return min(a, b) | (1 << d);
}

void run() {
    int n; cin >> n;
    trie.resize(1, {});

    rep(i, 0, n) {
        int k; cin >> k;
        int j = 0;
        for (int bit = 30; bit >= 0; bit--) {
            int val = (k >> bit) & 1;
            if (!trie[j][val]) {
                trie[j][val] = sz(trie);
                trie.pb({});
            }
            j = trie[j][val];
        }
    }

    int ans = dfs(0, 30);
    cout << ans << endl;
}