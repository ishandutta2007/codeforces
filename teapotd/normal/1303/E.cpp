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

string s, a, b;
int nxt[26][405];
int dp[405][405];

bool check() {
    rep(i, 0, sz(a)+1) rep(j, 0, sz(b)+1) {
        if (i == 0 && j == 0) {
            dp[i][j] = 0;
            continue;
        }

        dp[i][j] = sz(s)+1;

        if (i > 0) {
            int c = a[i-1]-'a';
            dp[i][j] = min(dp[i][j], nxt[c][dp[i-1][j]]+1);
        }

        if (j > 0) {
            int c = b[j-1]-'a';
            dp[i][j] = min(dp[i][j], nxt[c][dp[i][j-1]]+1);
        }
    }

    return dp[sz(a)][sz(b)] <= sz(s);
}

void solve() {
    string t;
    cin >> s >> t;

    rep(c, 0, 26) {
        int k = nxt[c][sz(s)+1] = nxt[c][sz(s)] = sz(s);
        for (int i = sz(s)-1; i >= 0; i--) {
            if (s[i]-'a' == c) k = i;
            nxt[c][i] = k;
        }
    }

    rep(i, 0, sz(t)+1) {
        a = t.substr(0, i);
        b = t.substr(i);
        if (check()) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}