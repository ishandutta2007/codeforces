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

void run() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        bool ok = 1;

        rep(i, k, n) {
            int j = i%k;
            if (s[i] != '?') {
                if (s[j] != '?' && s[i] != s[j]) {
                    ok = 0;
                    break;
                }
                s[j] = s[i];
            }
        }

        if (ok) {
            int cnt[2] = {};
            rep(i, 0, k) if (s[i] != '?') cnt[s[i]-'0']++;
            if (cnt[0] > k/2 || cnt[1] > k/2) {
                ok = 0;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}