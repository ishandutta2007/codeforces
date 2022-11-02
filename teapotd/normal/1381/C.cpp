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

bool brute(int n, int x, int y, Vi guess) {
    Vi ans(n);

    while (true) {
        int gx = 0;
        rep(i, 0, n) gx += (guess[i] == ans[i]);
        Vi xd1 = guess, xd2 = ans, xd3;
        sort(all(xd1));
        sort(all(xd2));
        set_intersection(all(xd1), all(xd2), back_inserter(xd3));
        int gy = sz(xd3);
        if (x == gx && y == gy) {
            return 1;
        }

        bool ok = 0;
        rep(i, 0, n) {
            ans[i]++;
            if (ans[i] <= n) {
                ok = 1;
                break;
            }
            ans[i] = 0;
        }

        if (!ok) {
            break;
        }
    }

    return 0;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    Vi guess(n);
    each(e, guess) {
        cin >> e;
        e--;
    }

    vector<Vi> cols(n+1);
    rep(i, 0, n) {
        cols[guess[i]].pb(i);
    }

    set<Pii> que;
    int unused = -1;

    rep(i, 0, n+1) {
        que.insert({ sz(cols[i]), i });
        if (cols[i].empty()) {
            unused = i;
        }
    }

    Vi ans(n, unused);

    rep(i, 0, x) {
        int c = que.rbegin()->y;
        que.erase(--que.end());
        ans[cols[c].back()] = c;
        cols[c].pop_back();
        que.insert({ sz(cols[c]), c });
    }

    int remain = n-x;

    while (remain > n-y) {
        if (que.begin()->x == 0) {
            que.erase(que.begin());
            continue;
        }

        int a = que.begin()->y;

        if (sz(que) == 1) {
            if (remain == 1) {
                int xd1 = -1, xd2 = -1;
                rep(i, 0, n) {
                    if (ans[i] != unused && ans[i] != a && ans[i] != guess[i] && guess[i] != a) {
                        if (xd1 == -1) {
                            xd1 = i;
                        } else if (ans[xd1] != ans[i]) {
                            xd2 = i;
                            break;
                        }
                    }
                }

                if (xd1 != -1 && xd2 != -1) {
                    int b = ans[xd1], c = ans[xd2];
                    ans[xd1] = a;
                    ans[xd2] = c;
                    ans[cols[a].back()] = b;
                    break;
                }
            }

            cout << "NO\n";
#ifdef LOC
            cout << flush;
            assert(!brute(n, x, y, guess));
#endif
            return;
        }

        int b = que.rbegin()->y;
        que.erase(que.begin());
        que.erase(--que.end());

        ans[cols[a].back()] = (remain == n-y+1 ? unused : b);
        ans[cols[b].back()] = a;
        cols[a].pop_back();
        cols[b].pop_back();

        que.insert({ sz(cols[a]), a });
        que.insert({ sz(cols[b]), b });
        remain -= 2;
    }

    cout << "YES\n";
    each(a, ans) cout << a+1 << ' ';
    cout << '\n';

#ifdef LOC
    cout << flush;
    assert(brute(n, x, y, guess));
    each(e, ans) {
        assert(e >= 0 && e <= n);
    }
    int gx = 0;
    rep(i, 0, n) gx += (guess[i] == ans[i]);
    Vi xd1 = guess, xd2 = ans, xd3;
    sort(all(xd1));
    sort(all(xd2));
    set_intersection(all(xd1), all(xd2), back_inserter(xd3));
    int gy = sz(xd3);
    if (x != gx || y != gy) {
        deb(x, gx, y, gy);
        assert(0);
    }
#endif
}

void run() {
    int t; cin >> t;
    while (t--) {
        solve();
#ifdef LOC
        cout << flush;
#endif
    }
}