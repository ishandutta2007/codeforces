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

constexpr int MAX_V = 1<<25;

int n, ans;
Vi elems, part[2];
int cnt[2][MAX_V];

void solve(int bit) {
    part[0].clear();
    part[1].clear();
    memset(cnt, 0, sizeof(cnt));

    int upper = 1<<bit;

    each(e, elems) {
        int x = (e>>bit) & 1;
        part[x].pb(e);
        cnt[x][upper - (e & ((1<<bit)-1))]++;
    }

    rep(i, 0, 2) {
        rep(j, 1, upper+1) {
            cnt[i][j] += cnt[i][j-1];
        }
    }

    int kek = 0;

    rep(s, 0, 2) {
        int whole = cnt[!s][upper];

        each(e, part[s]) {
            int tail = e & ((1<<bit)-1);
            kek += cnt[s][tail];
            if (tail*2 >= upper) kek--;

            kek += whole - cnt[!s][tail];
        }
    }

    kek /= 2;

    if (kek % 2) {
        ans ^= 1<<bit;
    }
}

void run() {
    cin >> n;
    elems.resize(n);
    each(e, elems) cin >> e;
    sort(all(elems));
    rep(i, 0, 25) solve(i);
    cout << ans << endl;
}