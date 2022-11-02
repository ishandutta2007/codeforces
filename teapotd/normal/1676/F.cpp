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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

void run() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        map<int, int> cntMap;
        rep(i, 0, n) {
            int a; cin >> a;
            cntMap[a]++;
        }

        int bestL = -1, bestR = -1;
        vector<pair<int, int>> cnt(all(cntMap));

        rep(i, 0, sz(cnt)) if (cnt[i].y >= k) {
            if (i > 0 && cnt[i-1].x == cnt[i].x-1 && cnt[i-1].y >= k) continue;
            int j = i+1;
            while (j < sz(cnt) && cnt[j].y >= k && cnt[j].x == cnt[i].x+j-i) j++;
            if (j-i > bestR-bestL) {
                bestL = cnt[i].x;
                bestR = cnt[i].x+j-i;
            }
        }

        if (bestL == -1) cout << -1 << '\n';
        else cout << bestL << ' ' << bestR-1 << '\n';
    }
}