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
        int n; cin >> n;
        Vi elems(n);
        int sum = 0;

        each(e, elems) {
            cin >> e;
            sum += e;
        }

        if (sum%2 == 1) {
            cout << "NO\n";
            continue;
        }

        int half = sum/2;
        vector<bool> dp(half+1);
        dp[0] = 1;

        each(e, elems) {
            for (int i = half; i >= e; i--) {
                dp[i] = dp[i] || dp[i-e];
            }
        }

        cout << (dp[half] ? "YES\n" : "NO\n");
    }
}