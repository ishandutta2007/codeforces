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
    int n, k;
    cin >> n >> k;

    Vi ands(n), ors(n);

    rep(i, 1, n) {
        cout << "and " << 1 << ' ' << i+1 << endl;
        cin >> ands[i];
        cout << "or " << 1 << ' ' << i+1 << endl;
        cin >> ors[i];
    }

    int and12, or12;
    cout << "and 2 3" << endl;
    cin >> and12;
    cout << "or 2 3" << endl;
    cin >> or12;

    Vi elems(n);

    rep(bit, 0, 30) {
        bool a = (ors[1] >> bit) & 1;
        bool b = (ors[2] >> bit) & 1;
        bool c = (or12 >> bit) & 1;
        bool d = (ands[1] >> bit) & 1;
        bool e = (ands[2] >> bit) & 1;
        bool f = (and12 >> bit) & 1;
        bool x;

        if (!a) {
            x = 0;
        } else if (d) {
            x = 1;
        } else if (!b) {
            x = 0;
        } else if (!c) {
            x = 1;
        } else if (!e) {
            x = 0;
        } else if (!f) {
            x = 1;
        } else {
            assert(0);
        }

        if (x) {
            elems[0] |= 1 << bit;
        }
    }

    rep(i, 1, n) {
        rep(bit, 0, 30) {
            bool x;
            if ((elems[0] >> bit) & 1) {
                x = (ands[i] >> bit) & 1;
            } else {
                x = (ors[i] >> bit) & 1;
            }
            if (x) {
                elems[i] |= 1 << bit;
            }
        }
    }

    deb(elems);

    sort(all(elems));
    cout << "finish " << elems[k-1] << endl;
}