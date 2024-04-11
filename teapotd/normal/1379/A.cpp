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
    string kek = "abacaba";

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool got = 0;

        rep(i, 0, sz(s)-sz(kek)+1) {
            string t = s;
            bool ok = 1;
            rep(j, 0, sz(kek)) {
                if (t[i+j] == '?') {
                    t[i+j] = kek[j];
                } else if (t[i+j] != kek[j]) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                each(c, t) if (c == '?') c = 'x';
                int cnt = 0;

                rep(i, 0, sz(s)-sz(kek)+1) {
                    bool xd = 1;
                    rep(j, 0, sz(kek)) {
                        if (t[i+j] != kek[j]) {
                            xd = 0;
                            break;
                        }
                    }
                    cnt += xd;
                }

                if (cnt == 1) {
                    cout << "Yes\n";
                    cout << t << '\n';
                    got = 1;
                    break;
                }
            }
        }

        deb(0);
        if (!got) {
            cout << "No\n";
        }
    }
}