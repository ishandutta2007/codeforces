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
        vector<ll> elems(n);
        each(e, elems) cin >> e;

        int left = 1, right = n-1;
        ll lval = elems[0], rval = 0;
        ll lLast = elems[0], rLast = 0;
        bool rMove = 1;
        int moves = 1;

        while (left <= right) {
            if (!rMove) {
                ll cur = 0;
                while (left <= right && cur <= rLast) {
                    cur += elems[left++];
                }
                lval += cur;
                lLast = cur;
            } else {
                ll cur = 0;
                while (left <= right && cur <= lLast) {
                    cur += elems[right--];
                }
                rval += cur;
                rLast = cur;
            }
            rMove = !rMove;
            moves++;
        }

        cout << moves << ' ' << lval << ' ' << rval << '\n';
    }
}