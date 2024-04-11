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
    int n, m; cin >> n >> m;
    Vi elems(n);
    each(e, elems) cin >> e;

    int begin = 0, end = m+1;

    while (begin+1 < end) {
        int mid = (begin+end-1) / 2;
        int last = 0;
        bool ok = 1;

        each(e, elems) {
            if (e < last) {
                if (last-e > mid) {
                    ok = 0;
                    break;
                }
            } else if (e > last) {
                if (!(e+mid >= m && e+mid-m >= last)) {
                    last = e;
                }
            }
        }

        if (ok) {
            end = mid+1;
        } else {
            begin = mid+1;
        }
    }

    cout << begin << endl;
}