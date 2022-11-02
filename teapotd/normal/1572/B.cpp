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
    cout << flush; _Exit(0);
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        Vi a(n+1), ans;

        rep(i, 1, n+1) {
            int k; cin >> k;
            a[i] = a[i-1] ^ k;
        }

        for (int j = n-1; j >= 0; j -= 2) {
            if (a[j] == 0) {
                for (int i = j-2; i > 0; i -= 2) {
                    if (a[i] != 0 && a[i+2] == 0) {
                        a[i] = a[i+2];
                        a[i+1] = a[i-1];
                        ans.pb(i);
                    }
                }
                for (int i = j+1; i <= n-2; i += 2) {
                    if (a[i+1] != 0 && a[i-1] == 0) {
                        a[i] = a[i+2];
                        a[i+1] = a[i-1];
                        ans.pb(i);
                    }
                }
                break;
            }
        }

        for (int i = n-2; i > 0; i -= 2) {
            if (a[i] != 0 && a[i+2] == 0) {
                a[i] = a[i+2];
                a[i+1] = a[i-1];
                ans.pb(i);
            }
        }

        bool ok = 1;
        each(e, a) if (e) ok = 0;

        if (ok) {
            cout << "YES\n";
            cout << sz(ans) << '\n';
            each(e, ans) cout << e << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}