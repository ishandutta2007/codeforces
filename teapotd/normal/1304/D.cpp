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

vector<ll> compressVec(vector<ll*>& vec) {
    sort(all(vec), [](ll* l, ll* r) { return *l < *r; });
    vector<ll> old;
    each(e, vec) {
        if (old.empty() || old.back() != *e)
            old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

void print(vector<ll>& elems) {
    vector<ll*> tmp;
    each(e, elems) tmp.pb(&e);
    compressVec(tmp);
    each(e, elems) cout << e+1 << ' ';
    cout << '\n';
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    vector<ll> least, great;
    least.pb(0);
    great.pb(0);
    int k = 1, e = -1;

    each(c, s) {
        if (c == '<') {
            least.pb(least.back()+1);
            great.pb(k++);
        } else {
            least.pb(least.back() - int(1e9));
            great.pb(e--);
        }
    }

    print(least);
    print(great);
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}