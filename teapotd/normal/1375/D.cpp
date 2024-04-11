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
    Vi A, seen, ans;

    while (t--) {
        int n; cin >> n;
        A.resize(n);
        each(e, A) cin >> e;
        ans.clear();

        while (true) {
            bool ok = 1;
            seen.assign(n+5, 0);

            rep(i, 0, n) {
                if (A[i] != i) ok = 0;
                seen[A[i]] = 1;
            }

            if (ok) break;
            int mex = 0;
            while (seen[mex]) mex++;

            int dst = mex;

            if (mex >= n) {
                rep(i, 0, n) if (A[i] != i) {
                    dst = i;
                    break;
                }
            }

            ans.pb(dst+1);
            A[dst] = mex;
        }

        cout << sz(ans) << '\n';
        each(a, ans) cout << a << ' ';
        cout << '\n';
    }
}