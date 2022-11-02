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

constexpr int MOD = 998244353;

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x;
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    map<Pii, int> val;
    vector<array<int, 2>> rows(n), cols(m);
    int cntRows[3] = {0, 0, n}, cntCols[3] = {0, 0, m};
    int inter[2] = {};

    auto del = [&](int i, int j) {
        auto it = val.find({i, j});
        if (it == val.end()) return;
        int v = it->y;
        val.erase(it);
        inter[(i+j+v)%2]--;
        cntRows[!rows[i][0] + !rows[i][1]]--;
        cntCols[!cols[j][0] + !cols[j][1]]--;
        rows[i][(j+v)%2]--;
        cols[j][(i+v)%2]--;
        cntRows[!rows[i][0] + !rows[i][1]]++;
        cntCols[!cols[j][0] + !cols[j][1]]++;
    };

    auto add = [&](int i, int j, int v) {
        val[{i,j}] = v;
        inter[(i+j+v)%2]++;
        cntRows[!rows[i][0] + !rows[i][1]]--;
        cntCols[!cols[j][0] + !cols[j][1]]--;
        rows[i][(j+v)%2]++;
        cols[j][(i+v)%2]++;
        cntRows[!rows[i][0] + !rows[i][1]]++;
        cntCols[!cols[j][0] + !cols[j][1]]++;
    };

    deb(cntRows, cntCols, inter);

    while (k--) {
        int i, j, t;
        cin >> i >> j >> t;
        i--; j--;
        del(i, j);
        if (t != -1) add(i, j, t);

        deb(cntRows, cntCols, inter);

        Zp ans = 0;
        if (cntRows[0] == 0) ans += Zp(2).pow(cntRows[2]);
        if (cntCols[0] == 0) ans += Zp(2).pow(cntCols[2]);
        ans -= !inter[0] + !inter[1];
        cout << ans.x << '\n';
    }
}