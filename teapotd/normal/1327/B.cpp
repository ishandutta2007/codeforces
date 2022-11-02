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
        vector<bool> taken(n);
        int loose = -1;

        rep(i, 0, n) {
            int k, low = n;
            cin >> k;

            while (k--) {
                int x; cin >> x;
                if (!taken[x-1]) {
                    low = min(low, x-1);
                }
            }

            if (low < n) {
                taken[low] = 1;
            } else {
                loose = i;
            }
        }

        int kek = -1;

        if (loose != -1) {
            rep(i, 0, n) {
                if (!taken[i]) {
                    kek = i;
                    break;
                }
            }
        }

        deb(loose, kek, taken);

        if (kek != -1) {
            cout << "IMPROVE\n" << loose+1 << ' ' << kek+1 << '\n';
        } else {
            cout << "OPTIMAL\n";
        }
    }
}