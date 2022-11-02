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
    int m, n;
    cin >> n >> m;

    Vi len(m);
    each(k, len) cin >> k;

    Vi pos(m);
    int last = n;

    for (int i = m-1; i >= 0; i--) {
        pos[i] = max(last-len[i], i);
        last = pos[i];

        if (pos[i]+len[i] > n) {
            cout << -1 << '\n';
            return;
        }
    }

    deb(pos);

    if (pos[0] != 0) {
        cout << -1 << '\n';
        return;
    }

    each(k, pos) {
        cout << k+1 << ' ';
    }
    cout << '\n';
}