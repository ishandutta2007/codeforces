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

#define prev pregveveve

struct Triple {
    int i, j, h;
};

int dp[205][205][405];
Triple prev[205][205][405];
char chr[205][205][405];

void run() {
    string s, t; cin >> s >> t;
    int maxHei = sz(s) + sz(t) + 3;

    rep(i, 0, sz(s)+1) {
        rep(j, 0, sz(t)+1) {
            rep(h, 0, maxHei) {
                dp[i][j][h] = -1;
            }
        }
    }

    queue<Triple> que;
    dp[0][0][0] = 0;
    que.push({0, 0, 0});

    while (!que.empty()) {
        int i = que.front().i, j = que.front().j, h = que.front().h;
        que.pop();

        if (i == sz(s) && j == sz(t) && h == 0) {
            string seq;
            while (dp[i][j][h]) {
                seq.pb(chr[i][j][h]);
                auto& q = prev[i][j][h];
                i = q.i; j = q.j; h = q.h;
            }
            reverse(all(seq));
            cout << seq << endl;
            return;
        }

        int i2 = (i < sz(s) && s[i] == '(' ? i+1 : i);
        int j2 = (j < sz(t) && t[j] == '(' ? j+1 : j);
        int h2 = h+1;

        if (h2 < maxHei && dp[i2][j2][h2] == -1) {
            dp[i2][j2][h2] = dp[i][j][h]+1;
            chr[i2][j2][h2] = '(';
            prev[i2][j2][h2] = {i, j, h};
            que.push({i2, j2, h2});
        }

        i2 = (i < sz(s) && s[i] == ')' ? i+1 : i);
        j2 = (j < sz(t) && t[j] == ')' ? j+1 : j);
        h2 = h-1;

        if (h2 >= 0 && dp[i2][j2][h2] == -1) {
            dp[i2][j2][h2] = dp[i][j][h]+1;
            chr[i2][j2][h2] = ')';
            prev[i2][j2][h2] = {i, j, h};
            que.push({i2, j2, h2});
        }
    }

    assert(0);
}