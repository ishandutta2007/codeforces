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

ll ch2(ll n) { return n * (n-1) / 2; }
ll ch3(ll n) { return n * (n-1) * (n-2) / 6; }

void run() {
    int n;
    double p;
    cin >> n >> p;

    constexpr ll SCALE = 10000;
    ll pScaled = llround(p*SCALE);
    ll low = pScaled * ch3(n) * 2;

    rep(a, 0, n+1) {
        ll cur = (ch3(a) * 2 + ch2(a) * (n-a) * 2 + a * ch2(n-a)) * SCALE;
        if (cur >= low) {
            cout << a << '\n';
            return;
        }
    }

    assert(0);
}