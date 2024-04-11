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

string perm(const string& s, int k) {
    int tot = sz(s)-k+1;
    int fast = tot/2;
    string ret;

    if (fast > 0) {
        ret = s.substr(k-1, fast*2) + s.substr(0, k-1) + s.substr(k-1 + fast*2);
    } else {
        ret = s;
    }

    if (tot % 2) {
        reverse(ret.end()-k, ret.end());
    }
    return ret;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string ret = s;
        int bestK = 1;

        rep(k, 1, n+1) {
            string alt = perm(s, k);
            if (alt < ret) {
                ret = move(alt);
                bestK = k;
            }
        }

        cout << ret << '\n';
        cout << bestK << '\n';
    }
}