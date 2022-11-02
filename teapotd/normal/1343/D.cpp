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
        int n, k; cin >> n >> k;
        Vi elems(n);
        each(e, elems) cin >> e;

        Vi ans(k*2+5);
        ans[0] = n;

        rep(i, 0, n/2) {
            int a = elems[i], b = elems[n-i-1];
            int low = min(a, b)+1;
            int high = max(a, b)+k;
            ans[low]--;
            ans[high+1]++;
            ans[a+b]--;
            ans[a+b+1]++;
        }

        rep(i, 1, sz(ans)) {
            ans[i] += ans[i-1];
        }

        deb(ans);

        int ret = INT_MAX;
        each(a, ans) ret = min(ret, a);
        cout << ret << '\n';
    }
}