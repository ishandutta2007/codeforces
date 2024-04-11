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
    Vi a(n), b(n);
    each(k, a) cin >> k;
    each(k, b) cin >> k;

    int ans = m+5;
    sort(all(b));

    each(y, b) {
        int x = (y-a[0]+m) % m;
        Vi c = a;
        each(k, c) k = (k+x) % m;
        sort(all(c));
        if (b == c) ans = min(ans, x);
    }

    cout << ans << endl;
}