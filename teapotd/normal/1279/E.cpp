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

constexpr int MAX_N = 55;
constexpr ll INF = ll(1e18) + 20;

vector<ll> fac, nCycles, nPerms;

ll add(ll a, ll b) {
    return min(a+b, INF);
}

ll mul(ll a, ll b) {
    if (b > INF/a) return INF;
    return min(a*b, INF);
}

void precomp() {
    fac.resize(MAX_N, 1);
    rep(i, 2, MAX_N) fac[i] = mul(fac[i-1], i);

    nCycles.resize(MAX_N, 1);
    rep(i, 2, MAX_N) nCycles[i] = fac[i-2];

    nPerms.resize(MAX_N);
    nPerms[0] = 1;

    rep(len, 1, MAX_N) {
        rep(cyc, 1, len+1) {
            nPerms[len] = add(nPerms[len], mul(nCycles[cyc], nPerms[len-cyc]));
        }
    }
}

ll matches(const Vi& vec) {
    static vector<bool> seen;
    seen.assign(sz(vec), 0);
    int nEnds = 0;

    rep(i, 0, sz(vec)) {
        if (vec[i] == -1) {
            nEnds++;
            continue;
        }
        if (seen[vec[i]]) return 0;
        seen[vec[i]] = 1;
    }

    if (nEnds == 0) return 1;
    seen.assign(sz(vec), 0);

    rep(i, 0, sz(vec)) {
        if (vec[i] == -1 || seen[i]) continue;

        int j = vec[i];
        seen[i] = 1;

        while (j != -1 && j != i && !seen[j]) {
            seen[j] = 1;
            j = vec[j];
        }

        if (i == j) {
            return 0;
        }
    }

    return fac[nEnds-1];
}

Vi solveCycle(int n, ll k) {
    Vi ans(n, -1);
    ans[0] = n-1;

    rep(i, 1, n) {
        bool ok = 0;
        rep(j, 0, n) {
            ans[i] = j;
            ll tmp = matches(ans);
            if (k < tmp) {
                ok = 1;
                break;
            }
            k -= tmp;
        }
        assert(ok);
    }

    return ans;
}

Vi solve(int n, ll k) {
    k--;

    if (k >= nPerms[n]) {
        return {};
    }

    Vi ans(n);
    int pos = 0;

    while (pos < n) {
        int remain = n-pos;
        bool ok = 0;

        rep(cyc, 1, remain+1) {
            ll tail = nPerms[remain-cyc];
            ll ways = mul(nCycles[cyc], tail);

            if (k < ways) {
                Vi tmp = solveCycle(cyc, k/tail);

                rep(i, 0, sz(tmp)) {
                    ans[pos+i] = tmp[i]+pos;
                }

                k %= tail;
                pos += cyc;
                ok = 1;
                break;
            }

            k -= ways;
        }

        assert(ok);
    }

    assert(k == 0);
    return ans;
}

void run() {
    int t; cin >> t;
    precomp();

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        Vi tmp = solve(n, k);
        if (tmp.empty()) {
            cout << "-1\n";
        } else {
            each(e, tmp) cout << e+1 << ' ';
            cout << '\n';
        }
    }
}