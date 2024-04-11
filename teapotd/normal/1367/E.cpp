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

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int cnt[26] = {};
        each(c, s) cnt[c-'a']++;

        int ans = 1;

        rep(len, 2, n+1) {
            int diff = gcd(len, k);
            int per = len/diff;

            int avail = 0;
            each(c, cnt) avail += c / per;

            if (avail >= diff) {
                ans = len;
            }
        }

        cout << ans << '\n';
    }
}