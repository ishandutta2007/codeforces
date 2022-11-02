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

Vi tree;
int len;

void add(int i, int v) {
    tree[i += len] += v;
    while (i /= 2) tree[i] = min(tree[i*2], tree[i*2+1]);
}

int findMin() {
    int i = 1;
    while (i < len) {
        if (tree[i] == tree[i*2]) {
            i *= 2;
        } else {
            i = i*2+1;
        }
    }
    return i-len;
}

void run() {
    int q, x; cin >> q >> x;

    for (len = 1; len < x; len *= 2);
    tree.resize(len*2, 1e9);

    rep(i, 0, x) tree[i+len] = 0;

    for (int i = len-1; i > 0; i--) {
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }

    while (q--) {
        int y; cin >> y;
        y %= x;
        add(y, 1);

        int gr = tree[1];
        int pos = findMin();

        int ans = gr*x + pos;
        cout << ans << '\n';
    }
}