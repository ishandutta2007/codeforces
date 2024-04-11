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

struct MaxRect {
    int begin, end, hei;
};

vector<MaxRect> getMaxRects(Vi hei) {
    hei.insert(hei.begin(), -1);
    hei.pb(-1);
    Vi reach(sz(hei), sz(hei)-1);
    vector<MaxRect> ans;

    for (int i = sz(hei)-1; --i;) {
        int j = i+1, k = i;
        while (hei[j] > hei[i]) j = reach[j];
        reach[i] = j;

        while (hei[k] > hei[i-1]) {
            ans.pb({ i-1, 0, hei[k] });
            auto& rect = ans.back();
            while (hei[k] == rect.hei) {
                k = reach[k];
            }
            rect.end = k-1;
        }
    }
    return ans;
}

void run() {
    int n; cin >> n;
    Vi a(n);

    each(k, a) {
        cin >> k;
        k = int(1e9) + 5 - k;
    }

    each(r, getMaxRects(a)) {
        if (r.begin == 0 && r.end == n) continue;
        if ((r.end-r.begin)%2 != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}