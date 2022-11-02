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

const string DIGITS[] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int n, k;
vector<string> elems;

int need[1<<7][10]; // from, to -> how many
int dp[2005][2005]; // prefix, to add -> best digit

void run() {
    cin >> n >> k;
    elems.resize(n);
    each(e, elems) cin >> e;

    reverse(all(elems));

    rep(mask, 0, 1<<7) {
        string a;
        rep(i, 0, 7) a.pb((mask >> i) & 1 ? '1' : '0');
        rep(j, 0, 10) {
            auto &b = DIGITS[j];
            bool ok = 1;
            int num = 0;
            rep(x, 0, 7) {
                if (a[x] == '1') {
                    if (b[x] != '1') {
                        ok = 0;
                        break;
                    }
                } else if (b[x] == '1') {
                    num++;
                }
            }
            need[mask][j] = (ok ? num : 5000);
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    Vi masks;

    rep(pref, 1, n+1) {
        auto& cur = elems[pref-1];
        int mask = 0;
        rep(i, 0, 7) {
            if (cur[i] == '1') mask |= 1<<i;
        }
        masks.pb(mask);

        rep(add, 0, k+1) {
            for (int d = 9; d >= 0; d--) {
                int rest = add - need[mask][d];
                if (rest >= 0 && dp[pref-1][rest] != -1) {
                    dp[pref][add] = d;
                    break;
                }
            }
        }
    }

    if (dp[n][k] == -1) {
        cout << "-1\n";
        return;
    }

    int x = k;

    for (int i = n; i > 0; i--) {
        deb(i, x);
        cout << dp[i][x];
        x -= need[masks[i-1]][dp[i][x]];
    }

    cout << '\n';
}