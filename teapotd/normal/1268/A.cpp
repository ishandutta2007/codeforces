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
    int n, k;
    string s;
    cin >> n >> k >> s;

    bool ok = 1;

    rep(i, k, n) {
        if (s[i%k] != s[i]) {
            ok = s[i%k] > s[i];
            break;
        }
    }

    if (!ok) {
        for (int i = k-1; i >= 0; i--) {
            s[i]++;
            if (s[i] > '9') {
                s[i] = '0';
            } else {
                break;
            }
        }
    }

    cout << n << '\n';
    rep(i, 0, n) cout << s[i%k];
    cout << '\n';
}